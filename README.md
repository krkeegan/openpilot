WARNING
------

**USE OF ANY CODE IN THIS REPOSITORY IS AT YOUR OWN RISK.  See Waiver Below**

**I AM NOT A SOFTWARE ENGINEER AND HAVE NO FORMAL TRAINING OR EXPERIENCE WITH ANY OF THIS.  THERE ARE BUGS AND ERRORS IN THIS CODE WHICH IS AT BEST ALPHA QUALITY SOFTWARE AND SHOULD ONLY BE USED FOR RESEARCH PURPOSES. THIS IS NOT A PRODUCT. YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS. NO WARRANTY EXPRESSED OR IMPLIED.**

**You must keep your eyes on the road at all times and be ready to take control of the car at any point.**


---

- [WARNING](#warning)
- [What is openpilot?](#what-is-openpilot)
- [What is in this fork?](#what-is-in-this-fork)
- [Features](#features)
  - [Abandoned Features](#abandoned-features)
  - [Previous Features that have been Merged into Comma Repo:](#previous-features-that-have-been-merged-into-comma-repo)
- [Will you add something?](#will-you-add-something)
- [Improve Acceleration from Stop](#improve-acceleration-from-stop)
- [Development Process](#development-process)
- [Licensing](#licensing)
- [WAIVER](#waiver)

---

What is openpilot?
------

[openpilot](http://github.com/commaai/openpilot) is an open source driver assistance system.

What is in this fork?
------
This is my personal fork of openpilot that includes modifications that I want and nothing else.  I drive a __2019 Rav4 Hybrid (TSS2)__ most of the modifications were designed for my vehicle and my personal taste and may not work on other vehicles.

I am publishing this work to help others understand how openpilot works.  As such, __I am NOT providing support for installation or troubleshooting.__  If you are looking for a supported fork, I recommend [Shane's Stock Additions](https://github.com/sshane/openpilot) fork.  It contains many of the same features.

Features
------
Currently this fork contains the following modifications:
* 📏 __Change Driving Profile From Steering Wheel__ - The Driving Profiles can be toggled using the distance follow button on the steering wheel.  [Feature Toyota Distance Button](https://github.com/krkeegan/openpilot/tree/feature_toyota_distance_btn)
* ⚠️ __Disable Updates and Nags__ - Updates are permanently disabled and must be performed using `ssh` and `git`. [Feature Disable Updates](https://github.com/krkeegan/openpilot/tree/feature_disable_updates_testing_msg)
* 🏎️ __No More Sluggish Starts__ - [_pending_] Improve the starting acceleration off the line.  See below. [Feature Slow Start](https://github.com/krkeegan/openpilot/tree/feature_fix_slow_start)
* 🔧 __Small Toyota Tweaks__ - [_pending_] Specific tuning for my vehicle and my tastes. [Feature Toyota Tune](https://github.com/krkeegan/openpilot/tree/feature_toyota_tune)
  * Slightly lower acceleration limit at high speed
  * Increase PID acceleration limit at low speed.
* 🔋 __Hybrid Battery Saver__ - Maximum of 8 Hours of Standby [Feature Battery Saver](https://github.com/krkeegan/openpilot/tree/feature_battery_saver)
  * Hybrids have tiny 12v batteries, turn off the comma after a maximum of 8 hours of standby.
  * Also decreases the battery capacity used in calculations.
  * Raises the minimum voltage level to prevent damage to the battery.
  * 8 hours of standby time is more than enough to upload my drive data and stay on while I am at work.
* 🅱️ __Engine Braking__ - Allow engine braking [Feature Sport Gear](https://github.com/krkeegan/openpilot/tree/feature_sport_gear)
  * Allows openpilot to stay engaged when the gear selector is shifted into S mode.
  * This allows for engine braking on downhills.
    * _Note_ According to the vehicle manual enabling "sport mode" may also create some engine braking.
  * I have not noticed any significant change to longitudinal controller performance when S mode is engaged.  However, please use caution when using it.
  * __Note:__ _Openpilot will disengage without warning if S mode is shifted below S4.  This is because Toyota does not allow cruise control below S4._
* Other features from future versions of Openpilot as I see fit

### Abandoned Features
* Tweak alert volumes. [Feature Lower Volume](https://github.com/krkeegan/openpilot/tree/feature_lower_volume) is no longer needed now that the device adjusts its volume based on the ambient noise level in the car.
* Raw toggle added back in to enable automatic log uploading. [Feature Raw Logs](https://github.com/krkeegan/openpilot/tree/feature_raw_logs_upload)
  * Comma blocks the upload of full camera and log files from the device with an http 412 error.  I suspect they are trying to save money on bandwidth costs.  I think the block is triggered when a device authentication is used, since I am still able to trigger an upload using a generated token, so presumably you could get around this by generating and copying a new authentication to the device.  However I elected to use the API and have a little script that fires off whenever my device is seen on my home network.

### Previous Features that have been Merged into Comma Repo:
* Display blue barriers on car UI when openpilot is engaged.
* Use wide camera as light sensor, better night performance of the screen brightness.
* Toggle Disengage on Gas. (Openpilot adopted in 8.14)
* Increased acceleration limits at low speed in the planner.
* Accurate low battery voltage 11.8v, stop damaging lead acid batteries.
* 3 different following distances close, standard, far

Will you add something?
---
You can certainly ask, but the criteria for adding it is:

* Is it something I would use
* Is it something I consider safe?  I am pretty cautious.
* Is it easy to maintain?  I don't want this to be a chore to maintain.

If the answer to any of those is __no__, then I probably won't add it.

Improve Acceleration from Stop
---
The new MPC introduced in 8.10 has a much slower acceleration profile from a standstill.  This is caused by many things, but is largely driven by the `a_change_cost` which was introduced as part of the lag compensation.  As you can see below, the rate of acceleration significantly lags behind 8.9:

![8.9 v 8.12](https://user-images.githubusercontent.com/3046315/148848373-7737a46e-a547-48f2-88ec-c2861d42e1ee.png)

I have made adjustments to the `jerk` and `a_change` costs to allow for a faster change in acceleration at low speeds, this affects acceleration only and will not alter braking.  I also reduced the `STOP_DISTANCE` dynamically so that when the lead car pulls away, the MPC is told to maintain a closer distance, this helps cause the an earlier initial acceleration request.  The changes result in the improved profile seen below:

![8.12 v KRK](https://user-images.githubusercontent.com/3046315/148849415-2212361b-4bde-43c2-8f12-bbcdf6d833dd.png)

Development Process
---

The comma.ai repository is a [complicated beast](https://blog.comma.ai/a-2020-theme-externalization/).  I prefer to base my daily driver branch off of the `commaai/devel` branch.  However, this branch lacks the suite of automated tests.  So I create my development branches off of `commaai/master`.  I try to pick the commit that is closest to the release version and make a branch `master-x.xx` with x.xx being the release version number.

To make merging with future versions of Openpilot easier, I try to keep each "feature" on its own branch. My branches that start with `feature_` contain additional features or tweaks that have not been upstreamed into `commaai/master`.  My branches that start with `future_` contain commits that have been developed by `commaai` but were not included in the last release and are likely to be included in the next release.  Branches prefixed with `research_` are test branches that are likely used for running simulations and may not be designed for use in the real-world.

The `feature_` branches are rebased to each new `master-x.xx` "release".  If I do additional work on a `feature_` branch once a release has been made, then I will generally just make new commits on the branch.  When the next release happens, I then squash this multiple commits down into a single commit.

I then merge all of the `feature_` and `future_` branches into a `merged_x.xx` branch with x.xx being the release version number.  Once I am satisfied with that this `merged_` branch has passed the automated tests, or failed for understandable reasons, I cherry-pick the commits into `Rav4-TSS2`, that I use as my daily driver branch.  The idea is that the `merged_x.xx` branch and `Rav4-TSS2` should remain consistent so that the results of the tests on `merged_x.xx` can be relied on.

Sometimes I may create a `Rav4-TSS2-____` branch if I want to test changes in the vehicle before committing them to my daily driver branch.

It is all a mess, and it would make working off of my branches difficult, but since this is primarily for personal use, it works for me.

While I wouldn't recommend forking my branch, each of the `feature_` branches generally having a single commit should make it relatively easy to merge my work into yours.

Licensing
------

openpilot is released under the MIT license. Some parts of the software are released under other licenses as specified.

WAIVER
-----

Any user of this software ("User") and anyone claiming on User's behalf releases and forever discharges Kevin Keegan ("Author") and its directors, officers, employees, agents, stockholders, affiliates, subcontractors, software contributors, and customers from any and all claims, liabilities, obligations, promises, agreements, disputes, demands, damages, causes of action of any nature and kind, known or unknown, which User has or ever had or may in the future have against Author or any of the related parties arising our of or relating to the use of any software in this Repository.

User shall indemnify and hold harmless Author and its directors, officers, employees, agents, stockholders, affiliates, subcontractors, software contributors, and customers from and against all allegations, claims, actions, suits, demands, damages, liabilities, obligations, losses, settlements, judgments, costs and expenses (including without limitation attorneys’ fees and costs) which arise out of, relate to or result from any use of this software by user.

**THIS IS ALPHA QUALITY SOFTWARE FOR RESEARCH PURPOSES ONLY. THIS IS NOT A PRODUCT.
YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS.
NO WARRANTY EXPRESSED OR IMPLIED.**

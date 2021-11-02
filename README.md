Warning
------

**USE OF ANY CODE IN THIS REPOSITORY IS AT YOUR OWN RISK.  See Waiver Below**

**I AM NOT A SOFTWARE ENGINEER AND HAVE NO FORMAL EXPERIENCE WITH ANY OF THIS.  THERE ARE BUGS AND ERRORS IN THIS CODE WHICH IS AT BEST ALPHA QUALITY SOFTWARE AND SHOULD ONLY BE USED FOR RESEARCH PURPOSES. THIS IS NOT A PRODUCT. YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS. NO WARRANTY EXPRESSED OR IMPLIED.**

**You must keep your eyes on the road at all times and be ready to take control of the car at any point.**


Table of Contents
=======================

* [What is openpilot?](#what-is-openpilot)
* [What is in this fork?](#what-is-in-this-fork)
* [Will you add something?](#will-you-add-something)
* [Distance Profiles](#distance-profiles)
* [Development Process](#development-process)
* [Licensing](#licensing)
* [Waiver](#waiver)

---

What is openpilot?
------

[openpilot](http://github.com/commaai/openpilot) is an open source driver assistance system.

What is in this fork?
------
This is my personal fork of openpilot that includes modifications that I want and nothing else.  I drive a __2019 Rav4 Hybrid (TSS2)__ most of the modifications will only work on my vehicle type.

I am publishing this work to help others understand how openpilot works.  As such, __I am NOT providing support for installation or troubleshooting.__  If you are looking for a supported fork, I recommend [Shane's Stock Additions](https://github.com/sshane/openpilot) fork.

Currently this fork contains the following modifications:
* 3 Distance profiles that can be toggled using the distance follow button on the steering wheel.  
  * These profiles are a modified version of Shane's profiles.  See below.
  * There are no on screen messages regarding the distance profile selected, only the icons on the vehicle's HUD.
* Toggle disengage on gas from the settings->toggles screen
* Updates are permanently disabled and must be performed using `ssh` and `git`.

Will you add something?
---
You can certainly ask, but the criteria for adding it is:

* Is it something I would use
* Is it something I consider safe?  I am pretty cautious.
* Is it easy to maintain?  I don't want this to be a chore to maintain.

If the answer to any of those is __no__, then I probably won't add it. 

Distance Profiles
---
Shane's profiles were not quite to my liking.  First, I extrapolated out the speeds, so that the distance is set about every ~5mph.  This just makes it easier to edit.

* Stock - Unchanged, this uses the default settings in openpilot.
* Relaxed - I felt Shane's had barely any noticable difference over stock.  I modified mine to be a 1.5 second following distance across the entire range.  Below ~25 mph this about matches Shane's, above this speed it is a bit closer.  This largely falls halfway between stock and traffic.
* Traffic - At low speeds this feels about right.  But at high speeds, I did not like that it continued to decrease the following distance. Instead, after ~60mph the traffic profile becomes fixed to 1.2 seconds.
  * I particularly don't like the hump that occurs around 68mph - 78mph.  I think this could result non-ideal outcomes.

![Follow Distance Graphs](https://user-images.githubusercontent.com/3046315/139732674-9e3c402e-28fd-421a-976f-d0691b079565.png)

Distance Profile Cost Adjustments
---
As the following distance decreases I have decreased the `jerk` cost and increased the `danger` cost.  This is to be expected, as the follow distance decreases the allowable rate of change in deceleration has to increase, this will make the acceleration more jerky.  Below is an example of this, as you can see the relaxed and traffic profiles start off following the lead closer, and then when the lead starts to slow down, they increase their rate of deceleration much faster:

![deceleration compared](https://user-images.githubusercontent.com/3046315/140407268-9af20805-b07b-425b-a56f-7fa528846c23.png)

Development Process
---

The comma.ai repository is a [complicated beast](https://blog.comma.ai/a-2020-theme-externalization/).  The releases are are compiled stripped down repositories.  I prefer to base my daily driver fork `Rav4-TSS2` off of the `commaai/devel` branch.  However, this branch lacks the suite of automated tests.  So I create my development branches off of `commaai/master`.  I try to pick the commit that is closest to the release version and make a branch `master-x.xx` with x.xx being the release version number.

My branches that start with `feature_` contain additional features or tweaks that have not been upstreamed into `commaai/master`.  My branches that start with `upstream_` contain commits that have been developed by `commaai` but were not included in the last release and are likely to be included in the next release.

Once I am satisfied with a branch and it has passed the automated tests, or failed for understandable reasons, I cherry-pick the commits into `Rav4-TSS2`.  Sometimed I may create a `Rav4-TSS2-____` branch if I want to test changes in the vehicle before commiting them to my daily driver branch.

It is all a mess, and it would make working off of my branches difficult, but since this is primarily for personal use, it works for me.

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
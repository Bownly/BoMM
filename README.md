# BoMM

Welcome to the Binding of Megaman code. 
Ignore any ramblings in the comments, and also ignore the general lack of comments throught the entire rest of the code. Also, forgive the gross, universal inadherance to any particular style conventions. Chalk that up to being "my b".


Here's the deal so far:

-I have plans to completely overhaul the level stitching code, so maybe just avoid that for now.

That's it for now. Holler if you have any questions or comments or concerns or cornucopias.


Oh yeah, and Snaake.hx is actually that one enemy that goes back and forth and speeds up when you're on its same y level.


# FlashDevelop tricks or tips and such

-F4 on a function or class will take you to that fn or class' declaration

-F5 will auto-compile and run

-Switch up top to debug mode rather than release in order to skip the splash screen

-I find building in neko to be fastest over windows, html5, or whatever

-Ctrl + Shift + 1 on a class name will auto import that class


# Style Guidelines
Style Guidelines

Function names:
Functions are to be ordered in two groups. For the first group, new() should always be first, followed by update(), kill(), finishKill(), and destroy(). (Note that not all classes will have a need for all of these functions.) Finally, any further overrides should follow in alphabetical order.
The second group of functions should be all the other functions for that class and should be alphabetized. Oh, and there should be an extra linebreak inbetween the two sets of functions. No other special rules atm.

Variable names:
Nothing concrete yet. Open for suggestions.




# TB Build Roadmap
TB Build Roadmap


:star: Oct 12 - Oct 18 (aka prototype week) :star: 
ART 3 (5?) mc frames (jump, hurt, jump shoot, (fall/fallshoot)
CODE ladders
CODE weapons/equipment system
CODE level select hubworld (incl assigning colors to levels)
CODE movement (inching forward, variable jump height, crouch?)
MEDIA set up accounts on twitter, tumblr, playfield, gamejolt
SKYPE come up with a name for the game and or studio

:star: Oct 19 - Oct 25 (aka design and social media week) :star: 
ART 1 tileset (~25 tiles)
ART 3 mc frames (climbing, ladder shooting, climbup)
ART / CODE / DESIGN 1 enemy (~4 frames per color)
ART / CODE / DESIGN 1 enemy (~4 frames per color)
CODE player flashing when hurt and death sequence/game over
CODE weapon/equipment x 5
DESIGN ogmo rooms x 25
MEDIA tweet x 7, /r/gamedev stuff, basic social media blasts
SKYPE/DESIGN boss

:star: Oct 26 - Nov 1 (aka meat and potatoes week) :star: 
ART boss (~10 frames)
ART / CODE / DESIGN 1 enemy (~4 frames per color)
ART / CODE / DESIGN 1 enemy (~4 frames per color)
CODE boss
CODE weapon/equipment x 5
CODE ~2 gimmicky platforms
CODE enemies to respawn if off screen, but not dead
CODE color picking for levels
DESIGN ogmo rooms x 25
MEDIA tweet x 7, /r/gamedev stuff, basic social media blasts

:star: Nov 2 - Nov 8 (aka misc week) :star: 
ART 3 mc frames (die frames)
ART 1 tileset (~25 tiles)
ART misc stuff (bullets, enemy death anim, hud hp bars, etc)
ART title screen
ART / CODE ~15 collectibles/powerups
CODE beat-boss-get-weapon-endlevel
CODE title screen
CODE parallax
MEDIA tweet x 7, /r/gamedev stuff, basic social media blasts

:star: Nov 9 - Nov 14 (aka crunch week) :star: 
CODE polish up the UI
POLISH the entire game oh god wtf are you doing, hurry up!
ART a trailer for the tb submission
MEDIA tweet x 6, /r/gamedev stuff, basic social media blasts
MEDIA fix up a good landing page for our game to submit to the tb contest

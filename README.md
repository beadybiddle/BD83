# BD83
A fully custom 83 Key mechanical keyboard designed around the way that beadybiddle types. I intend to be able to say that this is truly a keyboard customized to my needs.

### Layout
Every moved, removed, or added key is for the sake of streamlining typing, data entry, and gaming.
##### Space Bar
Normal space bars are dumb. I bet you only use one thumb to press space when typing, and you definitely only use your left thumb when gaming. Why waste 6.25u on a single function when you can have a couple of 2u's for it and make room in the middle for an extra key? After a lot of testing and asking others about their spacebar use it seems that each thumb stays within a pretty tight (~2u) region of the spacebar.
##### Backspace and Delete
Normal backspace is also dumb. It's one of the most used keys when typing, yet it's so far from the home row that you have to move your entire right hand to reach it. No sense whatsoever. So I've added a secondary backspace (which I intend to use primarily) between my split spacebar. This way I can backspace with either thumb and without losing a beat.
I've left the original backspace where it was for the sake of anyone who ever has to use my weird layout but isn't accustomed to the new keys.
##### Caps Lock
I've literally never used caps lock in my life. Begone with it.
##### Numpad
Lefthand numpads make more sense, but take more space. I needed to fit the same functionality into a ~70% form factor, so the fn modifier has taken the place of caps lock. This way I can switch layers with the left hand (while still using the mouse in the right when gaming or entering data). Putting the numpad behind WASD allows me to hold fn and enter numbers with just that hand. FN+1 also acts as KC_CALC to open the calculator. I tend to use the calculator often alongside CAD or whatever else. I have a bad habit of opening when I need it and closing when I'm done, so it's a pain to always open it when that entails so much work (actually just win+"calc"+enter but still more of a pain than I'd like).
##### Nav Cluster
The only time I ever use Home/End/PgUp/PgDn is when writing code, in which case they go to line start, line end, top of page, and bottom of page respectively. So, they are now positioned in a way that makes sense. Home is above the left arrow (since it goes all the way left), and likewise End above the right arrow. Paging up and down is left to the second layer because I never use them but wanted to keep them on the keyboard in case they're ever required or I want to map them to something.
##### F13
No idea what I'll use this for. Just had room for it by shrinking the backspace and figured it'd be fun to have.

### Hardware
TODO.
#### PCB
Designed in KiCad
Fabricated by JLCPCB
TODO
#### Case
Modeled in Fusion360
Going to have it fabricated at the GaTech Invention Studio (TODO)
TODO
#### Keycaps
TODO

### Firmware
I actually haven't written the firmware yet (Nov 24 2021). TODO.
#### NKRO
No NKRO support. I don't know why everyone always goes out of their way to ensure they get NKRO when they all end up typing at a miserable 90 WPM and never hitting more than two keys at once anyways. Unless you are doing stenography, NKRO is a worthless feature.
Seriously though, the primary reason I can't support NKRO is because the current BLE protocol doesn't allow me to.

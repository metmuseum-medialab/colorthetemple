Color The Temple
================

The Color the Temple project is an interactive, projection mapped presentation about Hathor, Horus and Caesar Augustus. The content and software was initially developed by Maria Paula Saba and Matt Felsen during their internship in the Media Lab at the Metropolitan Museum of Art.


## Compile and run the openFrameworks presentation app

Clone the latest release of [OpenFrameworks](http://openframeworks.cc) to your home folder

    $ cd; git clone --depth=1 http://github.com/openFrameworks/openFrameworks

Clone this repository to `~/openFrameworks/apps`

    $ cd ~/openFrameworks/apps && git clone http://github.com/metmuseum-medialab/colorthetemple


Clone [ofxSyphon](https://github.com/astellato/ofxSyphon), [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew), and [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets) to `~/openFrameworks/addons`

    $ cd ~/openFrameworks/addons
    $ git clone https://github.com/astellato/ofxSyphon
    $ git clone https://github.com/Spacebrew/ofxSpacebrew
    $ git clone https://github.com/labatrockwell/ofxLibwebsockets
    
then fix your ofxLibwebsockets version to the one that still has openssl:

    $ cd ofxLibwebsockets
    $ git checkout 30a2d3c5a5d07b80dd5fb1794968df4a89b36ee0

### Building the app (openSpacebrewController.xcodeproj ) Mkae sure to build the DEBUG, not the RELEASE target


* Add the video files to `~/openFrameworks/apps/colorthetemple/ColorTheTemple/bin/data`

## Run madmapper for projection mapping

Install and run [madmapper](http://madmapper.com), after connecting to an external projector.

Open up madmapper, which will be used to deform the projection

* click the colorthetemple syphon plugin
* add a square mesh from the middle icon in the top left corner
* click the 'warp mesh' checkbox in the bottom left, then start tweaking the subdivisions, dragging the mesh points...
* to use on the projector, go to view -> view fullscreen
  * make sure the display mirroring is OFF


## Setup spacebrew for remote control
[note: normally you wouldn't run code right from the Downloads directory. You should probably move both the Spacebrew directory and the colorTheTemple project under a common directory, with its own openframeworks directory structure. But the below will work.

**Note:** This only be needs to be done if you are setting up the project on a new computer or new account. It is already set up on the `undeed` account on the Mac mini

Download and unzip the latest release of [spacebrew](http://spacebrew.cc) to `~/Downloads`

    $ cd ~/Downloads && curl https://codeload.github.com/Spacebrew/spacebrew/legacy.zip/master -o spacebrew.zip
    $ unzip spacebrew.zip
    $ cd spacebrew
    $ npm install       # install libraries

Run spacebrew

**Note:** These folder paths are for the Mac mini. If the account name or folder paths are different on your computer, make sure you `cd` into the right place :)

    $ cd /Users/undeed/colorTheTemple/Spacebrew
    $ npm start         # run spacebrew

Serve up the spacebrew admin page in another terminal and open it up in your web browser

    $ cd /Users/undeed/colorTheTemple/Spacebrew/admin
    $ python -m SimpleHTTPServer 8001
    $ open http://localhost:8001

Serve up the colorthetemple controller page in yet another terminal and open it up in whatever you want to control the app

    $ cd /Users/undeed/colorTheTemple/openFrameworks/apps/colorthetemple/WebInterfaces/colorthetemple
    $ python -m SimpleHTTPServer 8000
    $ open http://localhost:8000

Run the openFrameworks app. On the Mac mini, it is already compiled so you should be able to run SpacebrewController.app from `/Users/undeed/colorTheTemple/openFrameworks/apps/colorthetemple/ColorTheTempler/bin` without having to re-compile it in Xcode.

Finally, with everything running, check the Spacebrew admin page (`http://localhost:8001` on the Mac mini) and make sure thte controller (CTT Remote) is connectd to the OF app. If not, click on one, then the other, and a line connected the two should appear.

Enjoy the show!

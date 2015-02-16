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

### Building the app (openSpacebrewController.xcodeproj )


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

Download and unzip the latest release of [spacebrew](http://spacebrew.cc) to `~/Downloads`

    $ cd ~/Downloads && curl https://codeload.github.com/Spacebrew/spacebrew/legacy.zip/master -o spacebrew.zip
    $ unzip spacebrew.zip

Install the dependencies and run spacebrew

    $ cd ~/Downloads/Spacebrew-spacebrew*
    $ npm install       # install libraries
    $ npm start         # run spacebrew

Serve up the spacebrew admin page in another terminal and open it up in your web browser

    $ cd ~/Downloads/Spacebrew-spacebrew*/admin
    $ python -m SimpleHTTPServer 8000
    $ open http://localhost:8000

Serve up the colorthetemple controller page in yet another terminal and open it up in whatever you want to control the app

    $ cd ~/openFrameworks/apps/colorthetemple/WebInterface
    $ python -m SimpleHTTPServer 8001
    $ open http://localhost:8001

Finally, connect the controller to the receiver by clicking on them and enjoy the show!

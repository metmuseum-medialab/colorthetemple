Color The Temple
================

An project by the MediaLab at The Metropolitan Museum of Art in New York, NY.

## Installation

* Get the latest release of [spacebrew](http://spacebrew.cc), which is used to coordinate the web interface and presentation app.
  * run `npm install` inside this directory to get all the required libraries

* Get the latest release of [OpenFrameworks](http://openframeworks.cc), and rename to `openFrameworks`.
  * Clone this repository to `openFrameworks/apps`.
  * Clone each of the following addons into `openFrameworks/addons/<addon_name>`
    * Anthony Stellato's [ofxSyphon](https://github.com/astellato/ofxSyphon)
    * SpaceBrew's [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)
    * Rockwell Labs' [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets)

## Building the openFrameworks app

* add `Syphon.framework` from `ofxSyphon/libs/Syphon/lib/osx` to the project, under Build Phases -> Copy Files
  * make sure to remove the existing Syphon framework from the copy files
  * make sure to check 'copy file if needed' when adding the syphon framework
* Add the video files to `openFrameworks/apps/ColorTheTemple-master/ColorTheTemple/bin/data`

## Running spacebrew

* In the spacebrew directory, run `npm start`

## Connecting the web controller to the presentation app through spacebrew

* Serve up the static html pages, with `# cd WebInterfaces && python -m SimpleHTTPServer`
* Open up `localhost:8000/colorthetemple` with whatever devices you want to control the presentation app
  * Go to the admin page, accessible from `localhost:8000/admin`
  * Connect the controller to the receiver by clicking on them and enjoy the show!

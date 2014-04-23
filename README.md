Color The Temple
================

An project by the MediaLab at The Metropolitan Museum of Art in New York, NY.

## Requirements

### Software
* [OpenFrameworks](http://openframeworks.cc)
* [spacebrew](http://spacebrew.cc)

### Addons
[How to install addons in openFrameworks](http://ofxaddons.com/howto/)

* Anthony Stellato's [ofxSyphon](https://github.com/astellato/ofxSyphon)
* SpaceBrew's [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)
* Rockwell Labs' [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets)

### Building & Running

#### the openFrameworks app
* add `Syphon.framework` from `ofxSyphon/libs/Syphon/lib/osx` to the project, under Build Phases -> Copy Files
  * make sure to remove the existing Syphon framework from the copy files
  * make sure to check 'copy file if needed' when adding the syphon framework
* Add the video files from `Desktop/ColorTheTempleMedia/` to `apps/ColorTheTemple-master/ColorTheTemple/bin/data`

#### the spacebrew server
* `# npm install && npm start` in spacebrew
* Make sure the IP address in `testApp.cpp` and `WebInterfaces/colorthetemple/js/main.js` point to the spacebrew server

#### the spacebrew admin page and controller page
* `# cd WebInterfaces && python -m SimpleHTTPServer`
First open up `mdig9317.local:8000/colorthetemple` with whatever devices you want to control the application
They will then show up in the admin page, accessible from `mdig9317.local:8000/admin`
Connect the controller to the receiver and enjoy the show!

Color The Temple
================

An project by the MediaLab at The Metropolitan Museum of Art in New York, NY.

## Requirements

### Software
* [OpenFrameworks](openframeworks.cc)
* [spacebrew](spacebrew.cc)

### Addons
* Anthony Stellato's [ofxSyphon](https://github.com/astellato/ofxSyphon)
* SpaceBrew's [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)
* Rockwell Labs' [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets)

### Building & Running

* add `Syphon.framework` from `ofxSyphon/lib/osx` to the project, under Build Phases -> Copy Files
* Make sure the IP address in `testApp.cpp` and `WebInterfaces/colorthetemple/js/main.js` point to the spacebrew server
* `# cd WebInterfaces && python -m SimpleHTTPServer`

Then open up `localhost:8000/admin`, link the controller to the app, and open `localhost:8000/colorthetemple`

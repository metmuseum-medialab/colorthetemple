Color The Temple
==============

A project by the MediaLab at The Metropolitan Museum of Art in New York, NY.

Some of these examples require:

* Anthony Stellato's [ofxSyphon](https://github.com/astellato/ofxSyphon)
* SpaceBrew's [ofxSpacebrew](https://github.com/Spacebrew/ofxSpacebrew)
* Rockwell Labs' [ofxLibwebsockets](https://github.com/labatrockwell/ofxLibwebsockets)

Then you need to make sure to add Syphon.framework (found in ofxSyphon/lib.osx) to the oF project, under Build Phases -> Copy Files.

Make sure the IP address in testApp.cpp and WebInterface/colorthetemple/js/main.js point to your spacebrew ip.

npm install && npm start [spacebrew](spacebrew.cc) somewhere

`python -m SimpleHTTPServer` in WebInterface

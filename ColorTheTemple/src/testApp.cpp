#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetFrameRate(60);
	
	// Spacebrew app setup
    string host = "127.0.0.1";
    string name = "Color the Temple Controller";
    string description = "oF App for Color the Temple by the Met MediaLab";
    
	// Add receivers from different button events
	spacebrew.addPublish( "autoplay-sender", "string" );
	spacebrew.addSubscribe( "receiver", "string" );
	spacebrew.addSubscribe( "autoplay", "boolean" );
	spacebrew.addSubscribe( "autoplay-duration", "range" );
    spacebrew.connect( host, name, description );
    
    // listen to spacebrew events
    Spacebrew::addListener(this, spacebrew);
    
    // Standard OF stuff
    ofBackground(0);
    ofSetVerticalSync(true);
	
	// load up videos
	string path = "./";
	
	vid1.loadMovie(path+"Color & Patterns - Glyphs later.mov");
	vid2.loadMovie(path+"Color & Patterns - with Glyphs.mov");
	vid3.loadMovie(path+"Ectoplasm with Zooming.mov");
	vid4.loadMovie(path+"Offering Scene.mov");
	vid5.loadMovie(path+"Augustus.mov");
	
	// Set movies to not loop
	vid1.setLoopState(OF_LOOP_NONE);
	vid2.setLoopState(OF_LOOP_NONE);
	vid3.setLoopState(OF_LOOP_NONE);
	vid4.setLoopState(OF_LOOP_NONE);
	vid5.setLoopState(OF_LOOP_NONE);
	
	// Set active vid as first one
	activeVid = &vid1;
	bPlaying = false;
	moviePauseTime = 0.1;

	bAutoPlay = false;
	queueIndex = 0;
	autoPlayPauseDuration = 10;
	autoPlayQueue.open("autoplay.json");
	if (autoPlayQueue.isMember("duration")) {
		float duration = autoPlayQueue["duration"].asFloat();
		if (duration != 0) {
			autoPlayPauseDuration = duration;
		}
	}
	
//	drawHeight = ofGetHeight();
//	drawWidth = activeVid->width * ofGetHeight() / activeVid->height;
	
	drawHeight = 797;
	drawWidth = 1065;
	
	syphon.setName(name);
}

//--------------------------------------------------------------
void testApp::update(){
	// If a movie is currently playing...
	if (bPlaying) {
		activeVid->update();

		// Check to see if we hit the pause time...
		if (activeVid->getPosition() * activeVid->getDuration() >= moviePauseTime && activeVid->isPlaying()) {
			activeVid->setPaused(true);
			bPlaying = false;
			lastTime = ofGetElapsedTimef();
		}
		
	} else {
		// Otherwise, if we're paused and autoplay is on, check if we need to
		// advance the queue
		if (bAutoPlay) {
			float now = ofGetElapsedTimef();
			if (now - lastTime > autoPlayPauseDuration) {
				lastTime = now;
				string message = autoPlayQueue["queue"][queueIndex].asString();
				spacebrew.sendString("autoplay-sender", message);
				ofLogNotice() << queueIndex << ": " << message;

				queueIndex++;
				queueIndex = ofWrap(queueIndex, 0, autoPlayQueue["queue"].size());
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	activeVid->draw(0, 0, drawWidth, drawHeight);
	//	activeVid->draw(0, 0);
	
	syphon.publishScreen();
}

//--------------------------------------------------------------
void testApp::onMessage( Spacebrew::Message & m ){

	if (m.name == "autoplay") {
		bAutoPlay = m.valueBoolean();
		ofLogVerbose() << "setting autoplay to " << bAutoPlay;
		return;
	}
	else if (m.name == "autoplay-duration") {
		autoPlayPauseDuration = m.valueRange();
		ofLogVerbose() << "setting autoplay to " << autoPlayPauseDuration;
		return;
	}

	if (bPlaying) {
		ofLogNotice() << "Received message while movie is playing, ignoring: "
			<< m.value;
		return;
	}
	
	vector <string> stringBits = ofSplitString(m.value, "-");
	string prefix = stringBits[0];
	
	
	// check which scene was selected and set the active video pointer
	if (prefix == "cp") {
		activeVid = &vid1;
	}
	if (prefix == "cpg") {
		activeVid = &vid2;
	}
	if (prefix == "ecto") {
		activeVid = &vid3;
	}
	if (prefix == "off") {
		activeVid = &vid4;
	}
	if (prefix == "aug") {
		activeVid = &vid5;
	}
	
	// check for specfic keyframe selections. set the playhead and pause time
	// Color & Patterns - Glyphs later
	if (m.value == "cp-black") {
		activeVid->setPosition(0 / activeVid->getDuration());
		moviePauseTime = 0.1;
	}
	if (m.value == "cp-safe") {
		activeVid->setPosition(1 / activeVid->getDuration());
		moviePauseTime = 2;
	}
	if (m.value == "cp-patterns") {
		activeVid->setPosition(3 / activeVid->getDuration());
		moviePauseTime = 4;
	}
	if (m.value == "cp-glyphs") {
		activeVid->setPosition(5 / activeVid->getDuration());
		moviePauseTime = 6;
	}
	if (m.value == "cp-background") {
		activeVid->setPosition(7 / activeVid->getDuration());
		moviePauseTime = 8;
	}
	if (m.value == "cp-end") {
		activeVid->setPosition(9 / activeVid->getDuration());
		moviePauseTime = 10;
	}
	
	// Color & Patterns - with Glyphs
	if (m.value == "cpg-black") {
		activeVid->setPosition(0 / activeVid->getDuration());
		moviePauseTime = 0.1;
	}
	if (m.value == "cpg-safe") {
		activeVid->setPosition(1 / activeVid->getDuration());
		moviePauseTime = 2;
	}
	if (m.value == "cpg-patterns") {
		activeVid->setPosition(3 / activeVid->getDuration());
		moviePauseTime = 4;
	}
	if (m.value == "cpg-background") {
		activeVid->setPosition(5 / activeVid->getDuration());
		moviePauseTime = 6;
	}
	if (m.value == "cpg-end") {
		activeVid->setPosition(7 / activeVid->getDuration());
		moviePauseTime = 8;
	}
	
	// Ectoplasm with Zooming
	if (m.value == "ecto-start") {
		activeVid->setPosition(0 / activeVid->getDuration());
		moviePauseTime = 0.1;
	}
	if (m.value == "ecto-hathor-glow") {
		activeVid->setPosition(1 / activeVid->getDuration());
		moviePauseTime = 1.5;
	}
	if (m.value == "ecto-hathor-titles") {
		activeVid->setPosition(2.5 / activeVid->getDuration());
		moviePauseTime = 3;
	}
	if (m.value == "ecto-horus-glow") {
		activeVid->setPosition(4 / activeVid->getDuration());
		moviePauseTime = 7.5;
	}
	if (m.value == "ecto-horus-titles") {
		activeVid->setPosition(8.5 / activeVid->getDuration());
		moviePauseTime = 9;
	}
	if (m.value == "ecto-augustus-glow") {
		activeVid->setPosition(10 / activeVid->getDuration());
		moviePauseTime = 13.5;
	}
	if (m.value == "ecto-augustus-cartouches") {
		activeVid->setPosition(14.5 / activeVid->getDuration());
		moviePauseTime = 15;
	}
	if (m.value == "ecto-augustus-offering") {
		activeVid->setPosition(16 / activeVid->getDuration());
		moviePauseTime = 19.5;
	}
	if (m.value == "ecto-gods-response") {
		activeVid->setPosition(20.5 / activeVid->getDuration());
		moviePauseTime = 22.5;
	}
	if (m.value == "ecto-end") {
		activeVid->setPosition(23.5 / activeVid->getDuration());
		moviePauseTime = 24;
	}
	
	// Offering Scene
	if (m.value == "off-start") {
		activeVid->setPosition(0 / activeVid->getDuration());
		moviePauseTime = 0.1;
	}
	if (m.value == "off-augustus-approaches") {
		activeVid->setPosition(1 / activeVid->getDuration());
		moviePauseTime = 7;
	}
	if (m.value == "off-altar-glow") {
		activeVid->setPosition(8 / activeVid->getDuration());
		moviePauseTime = 9;
	}
	if (m.value == "off-3d-rotate") {
		activeVid->setPosition(10 / activeVid->getDuration());
		moviePauseTime = 11;
	}
	if (m.value == "off-rotate-cakes") {
		activeVid->setPosition(12 / activeVid->getDuration());
		moviePauseTime = 13;
	}
	if (m.value == "off-hide-cakes") {
		activeVid->setPosition(14 / activeVid->getDuration());
		moviePauseTime = 15;
	}
	if (m.value == "off-rotate-cakes-back") {
		activeVid->setPosition(16 / activeVid->getDuration());
		moviePauseTime = 17;
	}
	if (m.value == "off-3d-rotate-back") {
		activeVid->setPosition(18 / activeVid->getDuration());
		moviePauseTime = 19;
	}
	if (m.value == "off-end") {
		activeVid->setPosition(20 / activeVid->getDuration());
		moviePauseTime = 21;
	}
	
	// Augustus
	if (m.value == "aug-start") {
		activeVid->setPosition(0 / activeVid->getDuration());
		moviePauseTime = 0.1;
	}
	if (m.value == "aug-glow") {
		activeVid->setPosition(1 / activeVid->getDuration());
		moviePauseTime = 2;
	}
	if (m.value == "aug-background") {
		activeVid->setPosition(3 / activeVid->getDuration());
		moviePauseTime = 4;
	}
	if (m.value == "aug-end") {
		activeVid->setPosition(5 / activeVid->getDuration());
		moviePauseTime = 6;
	}
	
	// Stop all the videos, then play the active one
	vid1.stop();
	vid2.stop();
	vid3.stop();
	vid4.stop();
	vid5.stop();
	
	activeVid->play();
	bPlaying = true;
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == ' ') {
		bPlaying = !bPlaying;
		activeVid->setPaused(!bPlaying);
	}
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	//spacebrew.sendBoolean("name", true);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}
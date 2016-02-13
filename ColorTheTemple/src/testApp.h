#pragma once

#include "ofMain.h"

#include "ofxJSON.h"
#include "ofxSpacebrew.h"
#include "ofxSyphon.h"

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
    
	// create spacebrew object
	Spacebrew::Connection spacebrew;
    
	// listen to spacebrew Messages
	void onMessage( Spacebrew::Message & m );
	
	// create video players
	ofVideoPlayer vid1, vid2, vid3, vid4, vid5;
	ofVideoPlayer *activeVid;
	float drawWidth, drawHeight;
	
	// Boolean for whether the movie should be playing
	bool bPlaying;

	bool bAutoPlay;
	float lastTime;
	float autoPlayPauseDuration;
	int queueIndex;
	ofxJSON autoPlayQueue;

	float moviePauseTime;
	
	// Create Syphon server output
	ofxSyphonServer syphon;
    
};

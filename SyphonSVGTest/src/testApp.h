#pragma once

#include "ofMain.h"
#include "ofxSvg.h"
#include "ofxSyphon.h"

class testApp : public ofBaseApp{
	
public:
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofImage background;
	
	ofxSVG isis;
	ofxSVG horus;
	ofxSVG augustus;
	ofxSVG table;
	ofxSVG hieroglphyics;
	
	ofxSyphonServer mainOutputSyphonServer;
	
	vector <ofPath> horusPaths;
	
};

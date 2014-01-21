#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"
#include "MLSVGObject.h"

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
	
	MLSVGObject hathor;
	MLSVGObject horus;
	MLSVGObject augustus;
	MLSVGObject table;
	MLSVGObject glyphs;
	MLSVGObject glyphZoom;
	
	ofxSyphonServer mainOutputSyphonServer;
	ofPolyline line;
	
	bool mouseScalesGlyph;
	float scale, scaleAt, scaleTarget;
	
	ofPoint drawAt, drawTarget;
	

};

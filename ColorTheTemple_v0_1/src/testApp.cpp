#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0);
	
	mainOutputSyphonServer.setName("Color the Temple Glyph");
	
	//background.loadImage("background.jpg");
	
	hathor.load("hathor.svg");
	horus.load("horus.svg");
	augustus.load("augustus.svg");
	table.load("table.svg");
	glyphs.load("glyphs.svg");
	glyphZoom.load("glyphs1.svg");
	
	//glyphs.setFilled(true);
	//glyphs.setFillColor(ofColor(0, 127, 255));
	
	mouseScalesGlyph = false;
	scale = scaleAt = scaleTarget = 0.4;
	
	drawAt = drawTarget = ofPoint(200, 500);
	//drawAt = ofPoint(0, 0);
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	float speed = 0.94;
	drawAt.x = drawAt.x * speed + drawTarget.x * (1-speed);
	drawAt.y = drawAt.y * speed + drawTarget.y * (1-speed);
	scaleAt = scaleAt * speed + scaleTarget * (1-speed);
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//	ofPushMatrix();
	//	ofScale(0.25, 0.25);
	//	background.draw(0, 0);
	//	ofPopMatrix();
	
	ofPushMatrix();
	{
		//ofScale(0.4, 0.4);
		
		ofTranslate(drawAt);
		
		//ofScale(scale, scale);
		ofScale(scaleAt, scaleAt);
//		hathor.draw();
//		horus.draw();
//		augustus.draw();
//		table.draw();
//		glyphs.draw();
		glyphZoom.draw();
	}
	ofPopMatrix();
	
	
	// scale horus & fade background based on mouse x
	/*
	float mappedScale = ofMap(mouseX, 0, ofGetWidth(), 0.3, 0.6);
	float mappedOpacity = ofMap(mappedScale, 0.3, 0.6, 0, 255);
	
	ofSetColor(0, mappedOpacity);
	ofRect(0, 0, ofGetWidth(), ofGetHeight());
	
	ofScale(mappedScale, mappedScale);
	horus.draw();
	 */
	
	
	mainOutputSyphonServer.publishScreen();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	if (key == ' ') {
		mouseScalesGlyph = !mouseScalesGlyph;
	}
	
	if (!mouseScalesGlyph) {
		cout << scale << endl;
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	if (mouseScalesGlyph) {
		scale = ofMap(x, 0, ofGetWidth(), 0.3, 0.8);
		ofClamp(scale, 0.3, 0.8);
	}
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if (drawTarget != ofGetWindowSize()/2) {
		drawTarget = ofPoint(ofGetWindowSize()/2);
		scaleTarget = 0.7;
	} else {
		drawTarget = ofPoint(200, 500);
		scaleTarget = 0.3;
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
	
}

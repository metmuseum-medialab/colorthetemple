#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0);
	
	mainOutputSyphonServer.setName("Color the Temple");
	
	background.loadImage("background.jpg");
	
	hathor.load("hathor.svg");
	horus.load("horus.svg");
	augustus.load("augustus.svg");
	table.load("table.svg");
	glyphs.load("glyphs.svg");
	
	//	glyphs.setFilled(true);
	//	glyphs.setFillColor(ofColor(0, 127, 255));
	
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//	ofPushMatrix();
	//	ofScale(0.25, 0.25);
	//	background.draw(0, 0);
	//	ofPopMatrix();
	
	ofPushMatrix();
	{
		ofScale(0.4, 0.4);
		hathor.draw();
		horus.draw();
		augustus.draw();
		table.draw();
		glyphs.draw();
	}
	ofPopMatrix();
	
	mainOutputSyphonServer.publishScreen();
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
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

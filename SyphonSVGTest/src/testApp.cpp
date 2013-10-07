#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	mainOutputSyphonServer.setName("Screen Output");
	
	
	background.loadImage("background.jpg");
	
	horus.load("horus.svg");
	
	for (int i = 0; i < horus.getNumPath(); i++) {
		cout << i << endl;
		ofPath p = horus.getPathAt(i);
		p.setFilled(false);
		p.setStrokeColor(ofColor(255));
		p.setStrokeWidth(2);
		horusPaths.push_back(p);
	}
	
//	ofPath path1 = horus.getPathAt(0);
//	cout << "is filled? " << path1.isFilled() << endl;
//	cout << "fill color: " << path1.getFillColor() << endl;
//	cout << "stroke color: " << path1.getStrokeColor() << endl;
//	cout << "stroke width: " << path1.getStrokeWidth() << endl;
//	
//	path1.setFilled(false);
//	
//	cout << "is filled? " << path1.isFilled() << endl;
//	cout << "fill color: " << path1.getFillColor() << endl;
}

//--------------------------------------------------------------
void testApp::update(){
	
	//horus.getPathAt(<#int n#>)
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofPushMatrix();
	ofScale(0.25, 0.25);
	background.draw(0, 0);
	ofPopMatrix();
	
	ofPushMatrix();
	ofScale(0.4, 0.4);
//	horus.draw();
	
	for (int i = 0; i < horusPaths.size(); i++) {
		horusPaths[i].draw();
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

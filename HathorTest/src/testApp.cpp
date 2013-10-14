#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0);
	
	mainOutputSyphonServer.setName("Color the Temple");

    

    vector<ofColor> glyphColors;
    glyphColors.resize(7);
    
    glyphColors[0] = ofColor(239,50,40);
    glyphColors[1] = ofColor(255,180,0);
    glyphColors[2] = ofColor(75,190,255);
    glyphColors[3] = ofColor(90,205,0);
    glyphColors[4] = ofColor(140,50,110);
    glyphColors[5] = ofColor(170,25,25);
    glyphColors[6] = ofColor(80,120,20);

    vector<ofColor> hathorColors;
    hathorColors.resize(13);
 
    
    hathorColors[0] = ofColor(255,255,255);
    hathorColors[1] = ofColor(255,227,157);
    hathorColors[2] = ofColor(255,200,0);
    hathorColors[3] = ofColor(255,0,45);
    hathorColors[4] = ofColor(0,175,245);
    hathorColors[5] = ofColor(170,25,25);
    hathorColors[6] = ofColor(80,120,20);
    hathorColors[7] = ofColor(200,200,200);
    hathorColors[8] = ofColor(0,0,80);
    hathorColors[9] = ofColor(255,0,55);
    hathorColors[10] = ofColor(90,205,0);
    hathorColors[11] = ofColor(0,0,80);
    hathorColors[12] = ofColor(255,200,0);


	for(int i = 0; i < 13; i++){
        ofColor c = hathorColors[i];
        string name = "hathor" + ofToString(i) + ".svg";
        
        
        MLSVGObject h;
        h.load(name, c);
        hathor.push_back(h);
        
    }

    for(int i = 0; i < 7; i++){
        
        
        ofColor c = glyphColors[i];
        string name = "glyph" + ofToString(i) + ".svg";
        
        
        MLSVGObject g;
        g.load(name, c);
        glyph.push_back(g);
    }
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	

	ofPushMatrix();
	{
        ofScale(0.4, 0.4);

		for(int i = 0; i < hathor.size(); i++){
		hathor[i].draw();
        }
        
        for(int i = 0; i < glyph.size(); i++){
            glyph[i].draw();
        }
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

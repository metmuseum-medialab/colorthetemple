#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofBackground(0);
	
	mainOutputSyphonServer.setName("Color the Temple");
    
    names.resize(25);
    drawingsColors.resize(25);
    
    names[0] = "Bg-white.svg";
    names[1] = "Bg-stripes.svg";
    names[2] = "dark-skin.svg";
    names[3] = "light-skin.svg";
    names[4] = "brown-table.svg";
    names[5] = "white_clothing.svg";
    names[6] = "red-clothing.svg";
    names[7] = "yellow-clothing.svg";
    names[8] = "green-scepter.svg";
    names[9] = "blue-scepter.svg";
    names[10] = "blue_bracelets.svg";
    names[11] = "yellow_bracelets.svg";
    names[12] = "blue_hair.svg";
    names[13] = "white_top.svg";
    names[14] = "red_top.svg";
    names[15] = "yellow_top.svg";
    names[16] = "black_crown.svg";
    names[17] = "blue-glyphs.svg";
    names[18] = "yellow-glyphs.svg";
    names[19] = "red-glyphs.svg";
    names[20] = "green-glyphs.svg";
    names[21] = "brown-glyphs.svg";
    names[22] = "white-glyphs.svg";
    names[23] = "light-blue-glyphs.svg";
    names[24] = "crowns.svg";
   

    
    drawingsColors[0] = ofColor(255,255,255);
    drawingsColors[1] = ofColor(0, 170, 120);//ofColor(30,40,78);
    drawingsColors[2] = ofColor(140,70,32);
    drawingsColors[3] = ofColor(255,235,150);
    drawingsColors[4] = ofColor(30,20,20);
    drawingsColors[5] = ofColor(255,255,255);
    drawingsColors[6] = ofColor(150, 60, 35); //150, 75, 60); // ofColor(3, 100, 32);
    drawingsColors[7] = ofColor(190,160,40);
    drawingsColors[8] = ofColor(0,115,100);
    drawingsColors[9] = ofColor(0, 140, 120);
    drawingsColors[10] = ofColor(0, 140, 120); //ofColor(0, 170, 120);//ofColor(30,40,80);
    drawingsColors[11] = ofColor(255,200,0);
    drawingsColors[12] = ofColor(0,80,80);// ofColor(0, 170, 120);
    drawingsColors[13] = ofColor(255,255,255);
    drawingsColors[14] = ofColor(165,10,10);
    drawingsColors[15] = ofColor(255,200,0);
    drawingsColors[16] = ofColor(0,0,0);
    drawingsColors[17] = ofColor(0, 140, 120); //ofColor(0, 170, 120);//ofColor(30,40,80);
    drawingsColors[18] = ofColor(180,160,30);//ofColor(255,200,0);
    drawingsColors[19] = ofColor(165,10,10);
    drawingsColors[20] = ofColor(0,115,100);
    drawingsColors[21] = ofColor(30,20,17);
    drawingsColors[22] = ofColor(255,255,255);
    drawingsColors[23] = ofColor(255,200,0);
    drawingsColors[24] = ofColor(10, 120, 32);


	for(int i = 0; i < 25; i++){
        
        
        MLSVGObject h;
        h.load(names[i], drawingsColors[i]);
        drawings.push_back(h);
        
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

		for(int i = 0; i < drawings.size(); i++){
		drawings[i].draw();
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

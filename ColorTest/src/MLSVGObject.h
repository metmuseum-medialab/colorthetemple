//
//  MLSVGObject.h
//  ColorTheTemple_v0_1
//
//  Created by Matt on 10/3/13.
//
//

#pragma once
#include "ofxSvg.h"


class MLSVGObject {
	
public:
	
	bool filled;
	ofColor fillColor;
	ofColor strokeColor;
	float strokeWidth;
	
	ofxSVG svg;
	vector <ofPath> paths;

	void load(string fileName, ofColor c);
	void draw();
	
	void setFilled(bool isFilled);
	void setFillColor(ofColor color);
	void setStrokeColor(ofColor color);
	void setStrokeWidth(float width);
	
};
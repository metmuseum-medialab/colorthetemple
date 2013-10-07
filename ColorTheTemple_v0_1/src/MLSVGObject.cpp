//
//  MLSVGObject.cpp
//  ColorTheTemple_v0_1
//
//  Created by Matt on 10/3/13.
//
//

#include "MLSVGObject.h"

void MLSVGObject::load(string fileName) {
	
	svg.load(fileName);
	
	filled = false;
	fillColor = ofColor(0);
	strokeColor = ofColor(255);
	strokeWidth = 2;
	
	for (int i = 0; i < svg.getNumPath(); i++) {
		ofPath p = svg.getPathAt(i);
		p.setFilled(filled);
		p.setFillColor(fillColor);
		p.setStrokeColor(strokeColor);
		p.setStrokeWidth(strokeWidth);
		paths.push_back(p);
	}
	
}

void MLSVGObject::draw() {
	
	for (int i = 0; i < paths.size(); i++) {
		paths[i].draw();
	}
	
}

void MLSVGObject::setFilled(bool isFilled) {
	filled = isFilled;
	
	for (int i = 0; i < paths.size(); i++) {
		paths[i].setFilled(filled);
	}
}

void MLSVGObject::setFillColor(ofColor color) {
	fillColor = color;
	
	for (int i = 0; i < paths.size(); i++) {
		paths[i].setFillColor(fillColor);
	}
}

void MLSVGObject::setStrokeColor(ofColor color) {
	strokeColor = color;
	
	for (int i = 0; i < paths.size(); i++) {
		paths[i].setStrokeColor(strokeColor);
	}
}

void MLSVGObject::setStrokeWidth(float width) {
	strokeWidth = width;
	
	for (int i = 0; i < paths.size(); i++) {
		paths[i].setStrokeWidth(strokeWidth);
	}
}
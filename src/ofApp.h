#pragma once

#include "ofMain.h"

#include "ofxGui.h"

class ofApp : public ofBaseApp{

	float margin;
	ofParameter<ofFloatColor> a, b, c, d;
	ofParameterGroup aGroup, bGroup, cGroup, dGroup;

	ofShader shader;
	ofxPanel aPanel, bPanel, cPanel, dPanel;

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
		
};
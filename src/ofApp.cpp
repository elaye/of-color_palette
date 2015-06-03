#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	margin = 10.0;

	aGroup.add(a.set("a", ofFloatColor(0.5, 0.5, 0.5, 1.0), 
	      		ofFloatColor(0.0, 0.0, 0.0, 0.0), 
	      		ofFloatColor(2.0, 2.0, 2.0, 1.0)));
	bGroup.add(b.set("b", ofFloatColor(0.5, 0.5, 0.5, 1.0), 
	      		ofFloatColor(0.0, 0.0, 0.0, 0.0), 
	      		ofFloatColor(2.0, 2.0, 2.0, 1.0)));
	cGroup.add(c.set("c", ofFloatColor(1.0, 0.7, 0.4, 1.0), 
	      		ofFloatColor(0.0, 0.0, 0.0, 0.0), 
	      		ofFloatColor(2.0, 2.0, 2.0, 1.0)));
	dGroup.add(d.set("d", ofFloatColor(0.0, 0.15, 0.2, 1.0), 
	      		ofFloatColor(0.0, 0.0, 0.0, 0.0), 
	      		ofFloatColor(2.0, 2.0, 2.0, 1.0)));

	aPanel.setup(aGroup);
	aPanel.setPosition(margin, margin);
	bPanel.setup(bGroup);
	bPanel.setPosition(aPanel.getPosition().x + aPanel.getWidth() + margin, margin);
	cPanel.setup(cGroup);
	cPanel.setPosition(bPanel.getPosition().x + bPanel.getWidth() + margin, margin);
	dPanel.setup(dGroup);
	dPanel.setPosition(cPanel.getPosition().x + cPanel.getWidth() + margin, margin);

	shader.load("shaders/shader_vert.glsl", "shaders/shader_frag.glsl");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);

	float h = 200.0;
	

	float ySquares = aPanel.getHeight() + 2 * margin + h / 2.0;
	float yBand = ySquares + h + margin;
	
	float xBand = ofGetWidth() / 2.0;
	float wBand = ofGetWidth() - 2 * margin;

	ofFloatColor ac = a.get();
	ofFloatColor bc = b.get();
	ofFloatColor cc = c.get();
	ofFloatColor dc = d.get();

	ofSetColor(ac);
	ofDrawPlane(aPanel.getPosition().x + aPanel.getWidth()/2.0, ySquares, h, h);
	ofSetColor(bc);
	ofDrawPlane(bPanel.getPosition().x + bPanel.getWidth()/2.0, ySquares, h, h);
	ofSetColor(cc);
	ofDrawPlane(cPanel.getPosition().x + cPanel.getWidth()/2.0, ySquares, h, h);
	ofSetColor(dc);
	ofDrawPlane(dPanel.getPosition().x + dPanel.getWidth()/2.0, ySquares, h, h);

	shader.begin();
		shader.setUniform4f("a", ac.r, ac.g, ac.b, ac.a);
		shader.setUniform4f("b", bc.r, bc.g, bc.b, bc.a);
		shader.setUniform4f("c", cc.r, cc.g, cc.b, cc.a);
		shader.setUniform4f("d", dc.r, dc.g, dc.b, dc.a);
		shader.setUniform2f("pos", xBand - wBand / 2.0, margin);
		shader.setUniform2f("dim", wBand, h);

		ofSetColor(ofColor::white);
		ofDrawPlane(xBand, yBand, wBand, h);

	shader.end();

	aPanel.draw();
	bPanel.draw();
	cPanel.draw();
	dPanel.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

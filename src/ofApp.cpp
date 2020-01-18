#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	scrWidth = ofGetScreenWidth();
	scrHeight = ofGetScreenHeight();

	startTime = ofGetElapsedTimeMillis();

	DebugView = false;

	refreshCurrentHour();
	playVideo();
}

//--------------------------------------------------------------
void ofApp::update() {
	clipPlayer.update();
	updateTimer();
}

//--------------------------------------------------------------
void ofApp::updateTimer()
{
	timer = ofGetElapsedTimeMillis() - startTime;
	//every two seconds
	if (timer >= 2000) {
		startTime = ofGetElapsedTimeMillis();
		refreshCurrentHour();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	clipPlayer.draw(0, 0, scrWidth, scrHeight);

	//GUI
	if (DebugView) {
		ofDrawBitmapString("Current Hour: " + ofToString(currHour), 10, 10);
		ofDrawBitmapString("Current Timer: " + ofToString(timer), 10, 30);
		ofDrawBitmapString("Current FPS: " + ofToString(ofGetFrameRate()), 10, 50);
		//ofDrawBitmapString("Counter: " + ofToString(sch.counter), 10, 20);
	}
}

void ofApp::refreshCurrentHour() {
	if (currHour != ofGetHours())
	{
		currHour = ofGetHours();
		playVideo();
	}
}

void ofApp::playVideo() {
	clipPlayer.load("loops/" + ofToString(ofGetHours()) + ".mp4");
	clipPlayer.play();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ')
	{
		DebugView = !DebugView;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

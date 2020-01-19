#include "ofApp.h"
//#include "ofGstVideoPlayer.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofEnableAlphaBlending();
	//clipPlayer.setPlayer(ofPtr<ofGstVideoPlayer>(new ofGstVideoPlayer));
	//clipPlayer2.setPlayer(ofPtr<ofGstVideoPlayer>(new ofGstVideoPlayer));
	clipPlayer.setPixelFormat(OF_PIXELS_NATIVE);
	clipPlayer2.setPixelFormat(OF_PIXELS_NATIVE);

	startTime = ofGetElapsedTimeMillis();
	DebugView = false;
	ManualTime = false;
	alphaValue = 0;
	currFrame = 0;
	updateDimensions();
	refreshCurrentHour();

	ofSetVerticalSync(false);
	//clipPlayer.setUseTexture(false);
	//clipPlayer2.setUseTexture(false);
	playVideo();
}

//--------------------------------------------------------------
void ofApp::update() {
	clipPlayer.update();
	clipPlayer2.update();
	if (!ManualTime) {
		updateTimer();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255, 255 - alphaValue);
	clipPlayer.draw(0, 0, scrWidth, scrHeight);
	ofSetColor(255, 255, 255, alphaValue);
	clipPlayer2.draw(0, 0, scrWidth, scrHeight);

	//GUI
	if (DebugView) {
		ofSetColor(255, 255, 255, 255);
		ofDrawBitmapString("Current Hour: " + ofToString(currHour), 10, 10);
		ofDrawBitmapString("Current Minutes and Seconds: " + ofToString(ofGetMinutes()) + ":" + ofToString(ofGetSeconds()), 10, 30);
		ofDrawBitmapString("Current Alpha Value: " + ofToString(alphaValue), 10, 50);
		ofDrawBitmapString("Current Timer: " + ofToString(timer), 10, 70);
		ofDrawBitmapString("Current FPS: " + ofToString(ofGetFrameRate()), 10, 90);
		ofDrawBitmapString("Manual Time: " + ofToString(ManualTime), 10, 110);
		ofDrawBitmapString("\"m\" to toggle manual time, then q/e to change the current hour \nand a/d to change alpha value)", 10, 130);
		ofDrawBitmapString("(\"f\" to toggle fullscreen)", 10, 170);
	}
}
//--------------------------------------------------------------

// helper methods

void ofApp::refreshCurrentHour() {
	alphaValue = ofMap(ofGetMinutes(), 0, 60, 0, 255, false);

	if (currHour != ofGetHours())
	{
		currHour = ofGetHours();
		playVideo();
	}
}

void ofApp::playVideo() {
	currFrame = clipPlayer.getCurrentFrame();
	clipPlayer.load("loops/" + ofToString(currHour) + ".mp4");
	clipPlayer2.load("loops/" + ofToString(currHour + 1) + ".mp4");
	clipPlayer.setFrame(currFrame);
	clipPlayer2.setFrame(currFrame);
	clipPlayer.play();
	clipPlayer2.play();
}

void ofApp::updateDimensions() {
	scrWidth = ofGetWindowWidth();
	scrHeight = ofGetWindowHeight();
}

void ofApp::updateTimer()
{
	timer = ofGetElapsedTimeMillis() - startTime;
	//every five seconds
	if (timer >= 5000) {
		startTime = ofGetElapsedTimeMillis();
		refreshCurrentHour();
	}
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ')
	{
		DebugView = !DebugView;
	}
	else if (key == 'm')
	{
		ManualTime = !ManualTime;
	}
	else if (key == 'f')
	{
		ofToggleFullscreen();
		updateDimensions();
	}
	else {
		if (ManualTime) {
			if (key == 'e') {
				currHour++;
				alphaValue = 0;
				playVideo();
			}
			else if (key == 'q') {
				currHour--;
				alphaValue = 255;
				playVideo();
			}
			else if (key == 'd') {
				alphaValue = alphaValue + 25 <= 255 ? alphaValue + 25 : 255;
			}
			else if (key == 'a') {
				alphaValue = alphaValue - 25 >= 0 ? alphaValue - 25 : 0;
			}
		}
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
	updateDimensions();
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

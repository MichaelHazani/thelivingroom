#pragma once

#include "ofMain.h"

//class Scheduler : public ofThread {
//public:
//	unsigned long counter = 0;
//
//	Scheduler() {
//		timer.setPeriodicEvent(1000000000); // 1 second
//		startThread();
//	}
//private:
//	ofTimer timer;
//	void threadedFunction() {
//		while (isThreadRunning()) {
//			timer.waitNext();
//			counter++;
//		}
//	}
//};

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	// custom methods and variables
	bool DebugView;
	bool ManualTime;
	float scrWidth;
	float scrHeight;
	int currHour;
	float startTime;
	float timer;

	ofVideoPlayer clipPlayer;
	ofVideoPlayer clipPlayer2;

	void refreshCurrentHour();
	void playVideo();
	void updateTimer();
	void updateDimensions();

	int currFrame;
	float alphaValue;
	//Scheduler sch;
};

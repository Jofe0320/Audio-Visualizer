#pragma once

#include "ofMain.h"
#include "AudioVisualizer.h"
#include <vector>

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		ofEasyCam cam;
		ofBoxPrimitive newBox;
		void drawMode1(vector<float> amplitudes);
		void drawMode2(vector<float> amplitudes);
		void drawMode3(vector<float> amplitudes);
		void drawMode4(vector<float> amplitudes);
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
		void playSong(string file);
		void replayKeys(char key);

	private:
		ofSoundPlayer sound;
		AudioVisualizer visualizer;
		bool playing = false;
		char mode = '1';
		bool visualizer_running = true;
		// Each mode Random color
		float rgbMode1[3] = {ofRandom(256), ofRandom(256), ofRandom(256)};
		double rgbMode2[2] = {ofRandom(255), ofRandom(255)};
		float rgbMode3[3] = {ofRandom(256), ofRandom(256), ofRandom(256)};
		float rgbMode4[3] = {ofRandom(256), ofRandom(256), ofRandom(256)};
		// Vector that contain all songs and variable to locate them
		vector<string> songs  = {"beat.wav","geesebeat.wav","LaCura.wav","lasanta.wav","pigeon-coo.wav","rock-song.wav","thespins.wav","walkingdream.wav"};
		int songPosition = 0;
		string loaded_sound = songs[songPosition];
		//Record and replay global variables
		bool record = false;
		vector <char> actions;
		bool playback = false;
		int updateCounter = 119;
		int replayFlag = 2;

};

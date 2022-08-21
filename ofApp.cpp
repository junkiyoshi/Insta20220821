#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetLineWidth(0.25);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(19);	
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	int size = span * 0.75;

	vector<ofColor> color_list = { ofColor(255, 255, 0), ofColor(0, 255, 255), ofColor(255, 0, 255) };

	for(int i = 0; i < color_list.size(); i++){

		auto color = color_list[i];
		auto noise_seed = ofRandom(1000);

		for (int x = span * 1.5; x <= ofGetWidth() - span * 1.5; x += span) {

			auto noise_y = ofMap(ofNoise(noise_seed, x * 0.003 + ofGetFrameNum() * 0.0025), 0, 1, 0, ofGetHeight());

			for (int y = span * 1.5; y <= ofGetWidth() - span * 1.5; y += span) {

				auto gap_y = abs(noise_y - y);
				auto alpha = 0;
				if (gap_y <= span * 4) {

					alpha = ofMap(gap_y, 0, span * 4, 255, 0);
				}

				if (alpha > 0) {

					ofFill();
					ofSetColor(color, alpha);
					ofDrawRectangle(x, y, size, size);

					ofNoFill();
					ofSetColor(color);
					ofDrawRectangle(x, y, size, size);
				}

				ofSetColor(32);
				ofDrawRectangle(x, y, size, size);
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}
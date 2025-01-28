#include "ofApp.h"
#include "cstdlib"
#include "ctime"

//--------------------------------------------------------------
void ofApp::setup(){
	randomNumber();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < circles.size(); i++) {
		ofDrawCircle(200*i , 200, circles[i]);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key == 'r') {
		randomNumber();

		for (int i = 0; i < circles.size(); i++) {
			std::cout << circles[i] << std::endl;
		}
		std::cout << "\n";
	}
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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

void ofApp::randomNumber() {
	circles.clear();

	std::srand(time(0));
	for (int i = 0; i < 5; i++) {
		int n = 10 + std::rand() % 91;
		circles.push_back(n);
	}
}


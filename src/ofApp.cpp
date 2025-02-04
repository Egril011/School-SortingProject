#include "ofApp.h"
#include "cstdlib"
#include "ctime"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	randomizeNumber();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//Dessiner les cercles
	ofSetColor(255, 255, 255);
	int xPos = 1;
	for (int i = 0; i < circles.size(); i++) {
		ofDrawCircle(180*xPos, 200, circles[i]);
		xPos++;
	}

	//Ecrire le radius des circles
	ofSetColor(0);
	xPos = 1;
	for (int i = 0; i < circles.size(); i++) {
		ofDrawBitmapString(circles[i], 180 * xPos - 10, 200);
		xPos++;
	}	

	ofSetColor(255);
	text = "Informations:\n"
		"\"r\" Pour randomiser les nombres\n"
		"\"b\" Bubble Sort\n"
		"\"i\" Insertion Sort\n"
		"\"m\" Merge Sort\n"
		"\"q\" Quick Sort\n"
		"\"s\" Fisher-Yates shuffle\n"
		"\t Le programme a execute: " + execute;
	ofDrawBitmapString(text, 100, 600);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//Pour Randomiser les nombres 
	if (key == 'r') {
		execute = "Randomisation des nombres";

		randomizeNumber();
	}

	//Bubble sort 
	else if (key == 'b') {
		execute = "Bubble sort";

		for (int i = 0; i < circles.size() - 1; i++) {
			for (int j = 0; j < circles.size() - i - 1; j++) {
				if (circles[j] > circles[j + 1])
				{
					std::swap(circles[j], circles[j + 1]);
				}
			}
		}
	}

	//Insertion sort
	else if (key == 'i') {
		execute = "Insertion sort";

		int key, j;
		for (int i = 1; i < circles.size(); i++) {
			key = circles[i];
			j = i - 1;

			while (j >= 0 && circles[j] > key) {
				circles[j + 1] = circles[j];
				j--;
				circles[j + 1] = key;
			}
		}
	}

	//Merge sort
	else if (key == 'm') {
		execute = "Merge sort";

		mergeSort(circles, 0, circles.size() - 1);
	}

	//Quick sort
	else if (key == 'q') {
		execute = "Quick sort";

		quickSort(circles, 0, circles.size() - 1);
	}

	//Fisher-Yates shuffle
	//J'ai regarde comment faire pour faire ce tri: 
	// https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
	else if (key == 's') {
		execute = "Fisher-Yatest";

		std::srand(time(0));

		for (int i = circles.size() - 1; i > 0; i--) {
			int j = std::rand() % (i + 1);
			swap(circles[i], circles[j]);
		}
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

void ofApp::randomizeNumber() {
	circles.clear();

	std::srand(time(0));
	for (int i = 0; i < 5; i++) {
		int n = 10 + std::rand() % 91;
		circles.push_back(n);
	}
}

void ofApp::merge(std::vector<int>& vector, int left, int mid, int right) {
	//Je me suis a ide des notes decours quand j'avais un blanc memoire

	std::vector<int> temp;
	int i = left, j = mid + 1;

	while (i <= mid && j <= right) {
		if (vector[i] <= vector[j]) {
			temp.push_back(vector[i++]);
		}
		else {
			temp.push_back(vector[j++]);
		}
	}

	while (i <= mid) {
		temp.push_back(vector[i++]);
	}
	while (j <= right) {
		temp.push_back(vector[j++]);
	}

	for (int k = 0; k < temp.size(); k++) {
		vector[left + k] = temp[k];
	}
}

void ofApp::mergeSort(std::vector<int>& vector, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSort(vector, left, mid);
		mergeSort(vector, mid + 1, right);

		merge(vector, left, mid, right);
	}
}

int ofApp::partition(std::vector<int>& arr, int low, int high) {
	//Je me suis aide des notes de cours quand j'avais un blanc memoire

	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void ofApp::quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


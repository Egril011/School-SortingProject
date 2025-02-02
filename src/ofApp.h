#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{
	private:
		vector<int> circles;
		std::string text;
		std::string execute;

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void randomizeNumber();
		void merge(std::vector<int>& vector, int left, int mid, int right);
		void mergeSort(std::vector<int>& vector, int left, int right);
		int partition(std::vector<int>& arr, int low, int high);
		void quickSort(std::vector<int>& arr, int low, int high);
		
};

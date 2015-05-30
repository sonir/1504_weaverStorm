#pragma once

//#define PORT_PERFORMANCE_MANAGER 64137

#define SC_WIDTH 340//1024
#define SC_HEIGHT 768
#define MERGINE_TOP 20
#define MERGINE_LEFT 20
#define LINE_HEIGHT 18

#include "ofMain.h"
#include "PerformanceManager.h"

class ofApp : public ofBaseApp{

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
		
        PerformanceManager *pm;
        bool lock = true;
};  

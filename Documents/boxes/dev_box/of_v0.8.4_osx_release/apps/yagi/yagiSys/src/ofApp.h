#pragma once

#define SC_WIDTH 240
#define SC_HEIGHT 240

#define OSC_PORT 7401
//#define OSC_PORT 7402
#define SEND_OSC_PORT OSC_PORT

#include <vector>
#include "ofMain.h"
#include "Osc.h"
#include "Yagi.h"

class Osc;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void test();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        //Deconstructor
        ~ofApp(){
            
            system("killall Terminal");
            
        }

        YagiApp yagi;
    
    private:
        Osc *osc;
        ofxOscSender sender;

    
};

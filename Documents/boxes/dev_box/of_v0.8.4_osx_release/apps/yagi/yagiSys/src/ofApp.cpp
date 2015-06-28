#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //SetupScreen
    ofSetFrameRate(120);
    ofBackground(0);
    ofSetCircleResolution(50);
    
    //SetupNode (osc-hub)
    ofSystem("open ../../../data/launch");
    //Setup OSC
    osc = new Osc(OSC_PORT,this);

    //Yagi
    notice = slNotice::instance();
    notice->addEvent("changeScreenColor", this);
    notice->addEvent("TRG_ADSR", this);
    yagi.setup();
    
    sender.setup("224.0.0.1", SEND_OSC_PORT);

#ifdef DEBUG
    test();
#endif

    
}

//--------------------------------------------------------------
void ofApp::update(){

    osc->update();
    yagi.update();

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    
    //Draw Color Rect
    switch(sc_color){
    
        case RED:
            ofSetColor(255,0,0);
            ofRect(0.0f, 0.0f, 100.0f, 100.0f);
            break;

        case GREEN:
            ofSetColor(0, 255, 0);
            ofRect(0.0f, 0.0f, 100.0f, 100.0f);
            break;

        case BLUE:
            ofSetColor(0, 0, 255);
            ofRect(0.0f, 0.0f, 100.0f, 100.0f);
            break;

        case BLACK:
            ofSetColor(0, 0, 0);
            ofRect(0.0f, 0.0f, 100.0f, 100.0f);
            break;
            
        default:
            ofSetColor(255, 255, 0);
            ofRect(0.0f, 0.0f, 100.0f, 100.0f);
            break;
            
    }
    
    //draw circle
    ofSetColor(255,255,255,220);
    ofCircle(ofGetWidth()/2.0f, ofGetHeight()/2.0f, CIRCLE_SIZE*adsr.update());
    
    
    
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    
}

//--------------------------------------------------------------
void ofApp::test(){
    cout << "test" << endl;
    //Send test message to me
    ofxOscMessage m;
    m.setAddress("/seq/event");
    time_t start_time;
    time(&start_time);
    start_time+=4;
    m.addIntArg((int)start_time);
    m.addIntArg(4); //number of sequence

    m.addIntArg(0); //Delta time
    m.addIntArg(0); //CMD
    m.addFloatArg(0.); //Delta time
    m.addFloatArg(0.6); //Delta time
    m.addFloatArg(0.7); //Delta time

    m.addIntArg(2000); //Delta time
    m.addIntArg(0); //CMD
    m.addFloatArg(1.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    m.addIntArg(4000); //Delta time
    m.addIntArg(0); //CMD
    m.addFloatArg(2.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    m.addIntArg(6000); //Delta time
    m.addIntArg(0); //CMD
    m.addFloatArg(4.); //Delta time
    m.addFloatArg(0.9); //Delta time
    m.addFloatArg(1.0); //Delta time

    
    
    sender.sendMessage(m);

    
}

//--------------------------------------------------------------
void ofApp::event(event_type tag, void *param){
    //using void type EXAMPLE: int *num = (int *)param;

    if(tag=="changeScreenColor"){
        color_e *tmp = (color_e *)param;
        sc_color = *tmp;
    }else if (tag=="TRG_ADSR"){
        
        command_e *pcmd = (command_e *)param;
        command_e cmd = *pcmd;

        adsr_t param;
        
        switch(cmd){
                
            case FAST:
                cout << "TRG_FAST" << endl;
                param.attack = 0;
                param.decay = 150;
                param.sustain = 0.5f;
                param.duration = 0;
                param.release = 0;
                adsr.setup(param);
                adsr.bang();
                break;

            case MID:
                cout << "TRG_MID" << endl;
                param.attack = 190;
                param.decay = 630;
                param.sustain = 0.5f;
                param.duration = 1200;
                param.release = 1200;
                adsr.setup(param);
                adsr.bang();
                break;

            case SLOW:
                cout << "TRG_SLOW" << endl;
                param.attack = 1250;
                param.decay = 2400;
                param.sustain = 0.5f;
                param.duration = 4000;
                param.release = 2500;
                adsr.setup(param);
                adsr.bang();
                break;

            default:
                break;
                
                
        }
        
        
    }
    

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == 't')test();
    
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

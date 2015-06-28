#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(120);
    
    //SetupNode (osc-hub)
    ofSystem("open ../../../data/launch");
    //Setup OSC
    osc = new Osc(OSC_PORT,this);

    //Yagi
    notice = slNotice::instance();
    notice->addEvent("changeScreenColor", this);
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
    
//    switch(yagi.sqcr.sc_color){
    switch(sc_color){
    
        case RED:
            ofBackground(255,0,0);
            break;

        case GREEN:
            ofBackground(0, 255, 0);
            break;

        case BLUE:
            ofBackground(0, 0, 255);
            break;

        case BLACK:
            ofBackground(0, 0, 0);
            break;
            
        default:
            ofBackground(255, 255, 0);
            break;
            
    }
    
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

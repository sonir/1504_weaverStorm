#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackgroundHex(0);

    pm = new PerformanceManager(64137);
    pm->setup();
    
    ofxOscSender sender;
    sender.setup(MULTICAST,PORT_FIS);
    ofxOscMessage m;
    m.setAddress("/fis/go");
    m.addIntArg(0);
    sender.sendMessage(m);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    pm->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofDrawBitmapString("performanceManager" , MERGINE_LEFT , MERGINE_TOP);

    //Draw LOCK
    ( lock ? ofSetColor(255) : ofSetColor(120));
    ofDrawBitmapString("[ LOCK ]" , MERGINE_LEFT , MERGINE_TOP+LINE_HEIGHT);

    //Draw Phase
    string phase = "PHASE: ";
    phase += pm->phase_str; ofSetColor(255,0,0);
    ofDrawBitmapString(phase , MERGINE_LEFT , MERGINE_TOP+LINE_HEIGHT*2);

    //Last Address
    ofSetColor(255);
    string tmp = "IN: ";
    tmp += pm->last_adr;
    ofDrawBitmapString(tmp , MERGINE_LEFT , MERGINE_TOP+LINE_HEIGHT*3);

    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    
    if(key==' '){
        
        lock = 1- lock;
        
    }else if(key==OF_KEY_LEFT){
        
        if(!lock) pm->setPhase(GLITCH);
        
    }else if(key==OF_KEY_UP){
        
        if(!lock) pm->setPhase(CATCHBALL);

    }else if(key==OF_KEY_RIGHT){
        
        if(!lock) pm->setPhase(BLINK);
        
    }else if(key==OF_KEY_DOWN){
        
        if(!lock) pm->setPhase(CALM);        
        
    }else if(key=='f'){
        
        if(!lock) pm->setPhase(FINAL);
        
    }

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

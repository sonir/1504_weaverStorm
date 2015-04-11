#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    storm.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

    storm.update(mouseX, mouseY);
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    storm.draw(mouseX, mouseY);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {

        storm.reset();
        
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

    storm.setAttraction(true);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    storm.setAttraction(false);
    
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

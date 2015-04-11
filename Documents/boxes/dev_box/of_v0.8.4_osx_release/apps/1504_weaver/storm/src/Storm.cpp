//
//  Storm.cpp
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#include "Storm.h"

void Storm::setup(){

    // 画面基本設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    // メッシュを点で描画
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(1.0);
    
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.002;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }

    
}

void Storm::update(int mouseX, int mouseY){
    
    // パーティクルの数だけ計算
    for (int i = 0; i < particles.size(); i++){
        // 力をリセット
        particles[i].resetForce();
        // もし引力がはたらいていたら
        if (atraction) {
            // マウスの位置に引力を加える
            particles[i].addAttractionForce(mouseX, mouseY, ofGetWidth(), 0.1);
        }
        // パーティクル更新
        particles[i].update();
        // 画面の端にきたら反対側へ
        particles[i].throughOfWalls();
    }

    
}


void Storm::draw(int mouseX, int mouseY){
    
    // メッシュを点で描く
    mesh.clear();
    ofSetColor(255);
    for (int i = 0; i < particles.size(); i++) {
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, 0));
    }
    mesh.draw();
    
    // 重力の点を描く
    if (atraction) {
        ofSetColor(255, 0, 0);
    } else {
        ofSetColor(0, 255, 255);
    }
    ofCircle(mouseX, mouseY, 4);
    
    //文字の背景
    ofSetColor(0, 127);
    ofRect(0, 0, 200, 60);
    
    // ログを表示
    ofSetColor(255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("Particle num = " + ofToString(particles.size()), 10, 40);    
    
}

void Storm::setAttraction(bool val){
    
    atraction = val;
    
}



void Storm::reset(){
    
    particles.clear();
    for (int i = 0; i < NUM; i++) {
        Particle p;
        p.friction = 0.002;
        p.setup(ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight())), ofVec2f(0, 0));
        particles.push_back(p);
    }

    
}
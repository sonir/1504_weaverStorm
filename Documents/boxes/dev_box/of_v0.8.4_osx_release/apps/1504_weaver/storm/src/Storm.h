//
//  Storm.h
//  Vector
//
//  Created by sonir on 4/11/15.
//
//

#ifndef __Vector__Storm__
#define __Vector__Storm__

#include <stdio.h>
#include "slAppManager.h"
#include "Particle.h"


class Storm {
    
public:
    
    void setup();
    void update(int mouseX, int mouseY);
    void draw(int mouseX, int mouseY);
    void setAttraction(bool val);
    void reset();
    
    
    // パーティクルクラスをインスタンス化
    vector<Particle> particles;
    // メッシュ
    ofVboMesh mesh;
    // 引力が働いているか
    bool atraction;
    // パーティクルの数
    static const int NUM = 100000;
    
    
    
};
#endif /* defined(__Vector__Storm__) */

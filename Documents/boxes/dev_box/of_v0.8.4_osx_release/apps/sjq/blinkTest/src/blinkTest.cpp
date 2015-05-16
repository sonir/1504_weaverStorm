//
//  blinkTest.cpp
//  blinkTest
//
//  Created by sonir on 5/15/15.
//
//

#include "blinkTest.h"

void blinkTest::setup(){
    
    //Set random_index with -1 to flg first step
    pre_rnd_index = -1;
    
}

void blinkTest::update(){
    

    
}




bool blinkTest::checkSpecial(int index){
    
    
    if(special_nodes[index]== true){
        
        special_nodes[index] = false;
        return true;
        
    }
    
    return false;
    
}


void blinkTest::createSpecialNode(){
    
    int rnd_index;
    bool doubled = true;
    
    do{
        rnd_index = (int)ofRandom(NODE_NUM);

    }while( theSpecialNodeExits(rnd_index) );

    special_nodes[rnd_index] = true;
    
    
    
}

void blinkTest::createSpecialNodes(int node_num){
    
    for(int i=0; i<node_num;i++){
    
        createSpecialNode();
        
    }
    
}


bool blinkTest::theSpecialNodeExits(int index){

    for(int i=0; i<NODE_NUM; i++){
        
        if(special_nodes[i]==true && i==index){
            
            return true;
            
        }
        
    }
    
    return false;
    
    
}

void blinkTest::resetSpecials(){
    
    for(int i=0; i<NODE_NUM; i++){

        special_nodes[i] = false;
        
    }
}

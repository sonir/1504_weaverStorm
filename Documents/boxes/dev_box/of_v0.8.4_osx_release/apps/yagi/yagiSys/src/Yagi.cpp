//
//  Yagi.cpp
//  yagiSys
//
//  Created by sonir on 6/22/15.
//
//

#include "Yagi.h"

//FunctionProtoType
void setAdsrWithDuration(note_t note, adsr_t *param);
void setAdsr(command_e cmd, adsr_t *param);

void YagiApp::setup(){

    //Setup Event Manager
    notice = slNotice::instance();
    notice->addEvent("changeScreenColor", this);
    notice->addEvent("TRG_ADSR", this);
    
    //Setup Sequencer
    sqcr.setup();

    
}


void YagiApp::update(){
    
    sqcr.update();
    
}

void YagiApp::draw(){
    
    drawRects();
    drawCircles();

    
}

void YagiApp::drawRects(){
    
    //Draw Color Rect
    switch(sc_color){
            
        case RED:
            ofSetColor(255,0,0);
            break;
            
        case GREEN:
            ofSetColor(0, 255, 0);
            break;
            
        case BLUE:
            ofSetColor(0, 0, 255);
            break;
            
        case BLACK:
            ofSetColor(0, 0, 0);
            break;
            
        default:
            ofSetColor(255, 255, 0);
            break;
            
    }
    ofRect(SC_MARGIN_WIDTH, SC_MARGIN_HEIGHT, SQUARE_SIZE, SQUARE_SIZE);

}

void YagiApp::drawCircles(){
    
    //draw circle
    for(int i=0;i<CIRCLE_NUM; i++){
        float adsr_val = adsr[i].update();
        ofSetColor(255*adsr_val,255*adsr_val,255*adsr_val,220*adsr_val);
//                ofSetColor(255,255,255,220);

        float circle_x = (CIRCLE_MARGIN*i)+(SC_MARGIN_WIDTH+CIRCLE_SIZE);
        float row = 0;
        if(i>=CIRCLE_COLUMN){
            row = 1;
            circle_x -= CIRCLE_MARGIN*CIRCLE_COLUMN;
        }
        ofCircle(circle_x, CIRCLE_MARGIN*row+CIRCLE_MARGIN_TOP, CIRCLE_SIZE*adsr_val);
//        ofCircle(circle_x, CIRCLE_MARGIN*row+CIRCLE_MARGIN_TOP, CIRCLE_SIZE);
    }
    
    
}


//--------------------------------------------------------------
void YagiApp::event(event_type tag, void *param){
    //using void type EXAMPLE: int *num = (int *)param;
    
    if(tag=="changeScreenColor"){
        color_e *tmp = (color_e *)param;
        sc_color = *tmp;
    }else if (tag=="TRG_ADSR"){
        

#ifdef APP_BASIC
        command_e *pcmd = (command_e *)param;
        command_e cmd = *pcmd;
        
        adsr_t param;
        int num=ofRandom(CIRCLE_NUM);
        setAdsr(cmd, &param);
        
#elif defined APP_ASUNA
        note_t *note = (note_t *)param;
        note_t tmp_note = *note;
        
        adsr_t param;
        int num=ofRandom(CIRCLE_NUM);
        
        setAdsrWithDuration(tmp_note, &param);        
#endif
        
        //Trigger circle with specified ADSR
        adsr[num].setup(param);
        adsr[num].bang();

        
        
    }
    
    
}


// C Func //////////////////////

void setAdsr(command_e cmd, adsr_t *param){
    
    switch(cmd){
            
        case FAST:
#ifdef DEBUG
            cout << "TRG_FAST" << endl;
#endif
            param->attack = 0;
            param->decay = 150;
            param->sustain = 0.5f;
            param->duration = 0;
            param->release = 0;
            break;
            
        case MID:
#ifdef DEBUG
            cout << "TRG_MID" << endl;
#endif
            param->attack = 190;
            param->decay = 630;
            param->sustain = 0.5f;
            param->duration = 1200;
            param->release = 1200;
            break;
            
        case SLOW:
#ifdef DEBUG
            cout << "TRG_SLOW" << endl;
#endif
            param->attack = 1250;
            param->decay = 2400;
            param->sustain = 0.5f;
            param->duration = 4000;
            param->release = 2500;
            break;
            
        default:
            break;
            
            
    }

    
}

void setAdsrWithDuration(note_t note, adsr_t *param){
    
    switch(note.cmd){
            
        case FAST:
#ifdef DEBUG
            cout << "TRG_FAST" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration = note.duration*1000;
            param->release = 13800;
            break;
            
        case MID:
#ifdef DEBUG
            cout << "TRG_MID" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration = note.duration*1000;
            param->release = 13800;
            break;
            
        case SLOW:
#ifdef DEBUG
            cout << "TRG_SLOW" << endl;
#endif
            param->attack = 4300;
            param->decay = 1;
            param->sustain = 1.0f;
            param->duration = note.duration*1000;
            param->release = 13800;
            break;
            
        default:
            break;
            
            
    }
    
#ifdef DEBUG
    cout << "adsr=" << num << endl;
#endif
    
}

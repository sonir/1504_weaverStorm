//
//  Osc.h
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#pragma once
//#ifndef __sjqPlayer__Osc__
//#define __sjqPlayer__Osc__

#include <stdio.h>
#include "slOscManager.h"
#include "ofApp.h"
#include "setup.h"

class ofApp;

class Osc : public slOscManager{

    public:

        Osc(int port, ofApp *app_adr):slOscManager(port){
        
            ofapp = app_adr;
            
#ifdef APP_BASIC
            seq_adr = "/seq/event";
#elif defined APP_ASUNA
            seq_adr = "/seq/event/asuna";
#endif
            
        }

        ofApp *ofapp;
        void fireMessage(ofxOscMessage *m);
    
    private:
        string seq_adr;

    
};

//#endif /* defined(__sjqPlayer__Osc__) */

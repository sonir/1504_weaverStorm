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
#include "setup.h"
#include "ofApp.h"

class ofApp;


class Osc : public slOscManager{

    public:

        Osc(int port, ofApp *app_adr):slOscManager(port){
        
            ofapp = app_adr;
//            trg.inst = PF;
//            trg.note = POINT;
            
        }

        ofApp *ofapp;
        void fireMessage(ofxOscMessage *m);

    
};

//#endif /* defined(__sjqPlayer__Osc__) */

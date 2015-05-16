//
//  Osc.cpp
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#include "Osc.h"

void Osc::fireMessage(ofxOscMessage *m){
    
    if(m->getAddress() == "/test1"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(test1, fnum);
        
    }else if(m->getAddress() == "/sjq/blink/set"){
        
        specials_t s;
        s.node_num = m->getArgAsInt32(0);
        
        for(int i = 0; i<s.node_num;i++){
            
            s.specials[i] = m->getArgAsInt32(i+1);
            
        }
        ofapp->setSpecials(s);
        
            
        
    }else if (m->getAddress() == "/sjq/blink/bang"){
        
        ofapp->blink(m->getArgAsInt32(0));
        
    }
    
//    else if(m->getAddress() == "/sjq/mobile/catchball"){
//        
//        trg.inst = (player_type_e)m->getArgAsInt32(0);
//        trg.note = (note_type_e)m->getArgAsInt32(1);
//        ofapp->noteTrigger(trg);
//        
//    }else if(m->getAddress() == "/sjq/mobile/glitch"){
//        
//        trg.inst = (player_type_e)m->getArgAsInt32(0);
//        trg.note = (note_type_e)m->getArgAsInt32(1);
//        ofapp->noteTrigger(trg);
//        
//    }else if(m->getAddress() == "/sjq/performer/play"){
//        
//        player_type_e performer = (player_type_e)m->getArgAsInt32(0);
//        ofapp->reload(performer);
//        
//    }

    
}
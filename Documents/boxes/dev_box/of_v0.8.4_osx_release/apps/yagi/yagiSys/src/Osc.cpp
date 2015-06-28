//
//  Osc.cpp
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#include "Osc.h"

void Osc::fireMessage(ofxOscMessage *m){
    
    if(m->getAddress() == "/test137"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(test1, fnum);
        
    }else if(m->getAddress() == "/seq/event"){
        
        cout << "/seq/event" << endl;
        SequenceData s;
        s.st = (time_t)m->getArgAsInt32(0);
        s.qtm_count = m->getArgAsInt32(1);
        
        for(int i=0; i< s.qtm_count; i++){
            
            int focused_seg = (QUANTUMS_TOP_INDEX+(QUANTUM_ELEMENTS_NUM*i));
            quantum q;
            q.done = false;
            q.delta = m->getArgAsInt32(focused_seg);
            q.cmd = (command)m->getArgAsInt32(focused_seg+1);
            q.param1 = m->getArgAsFloat(focused_seg+2);
            q.param2 = m->getArgAsFloat(focused_seg+3);
            q.param3 = m->getArgAsFloat(focused_seg+4);
            s.quantums.push_back(q);
        }
        
        ofapp->yagi.sqcr.sequences.push_back(s);
        
    }
    
}
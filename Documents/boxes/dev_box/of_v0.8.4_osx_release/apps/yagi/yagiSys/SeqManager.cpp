//
//  SeqManager.cpp
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#include "SeqManager.h"

void SeqManager::executeOneQuantum(quantum *q){
    
    command_e cmd = (command_e)q->cmd;
    
 
    switch(cmd){
            
        case TEST2:
            sc_color = (color_e)q->param1;
            notice->notify("changeScreenColor", &sc_color);
            break;
                        
        case FAST:
            notice->notify("TRG_ADSR", &cmd); //invoke animation in ofApp.cpp
            break;
        
        case MID:
            notice->notify("TRG_ADSR", &cmd); //invoke animation in ofApp.cpp
            break;
            
        case SLOW:
            notice->notify("TRG_ADSR", &cmd); //invoke animation in ofApp.cpp
            break;
            
            
    }

    
//    if((command_e)q->cmd==TEST2){
//         sc_color = (color_e)q->param1;
//         notice->notify("changeScreenColor", &sc_color);
//         q->done = true;
//    }
    
    
}
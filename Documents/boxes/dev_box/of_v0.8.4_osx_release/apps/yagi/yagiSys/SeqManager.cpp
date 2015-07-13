//
//  SeqManager.cpp
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#include "SeqManager.h"

void SeqManager::executeOneQuantum(quantum *q){
    
    //change behavior according to the app type
#ifdef APP_BASIC
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
    
#elif defined APP_ASUNA
    
    note_t note;
    note.cmd = (command_e)q->cmd;
    note.number = (int)q->param1;
    note.duration = q->param2;
    
    
    switch(note.cmd){
            
        case TEST2:
            sc_color = (color_e)q->param1;
            notice->notify("changeScreenColor", &sc_color);
            break;
            
        case FAST:
            notice->notify("TRG_ADSR", &note); //invoke animation in ofApp.cpp
            break;
            
        case MID:
            notice->notify("TRG_ADSR", &note); //invoke animation in ofApp.cpp
            break;
            
        case SLOW:
            notice->notify("TRG_ADSR", &note); //invoke animation in ofApp.cpp
            break;
            
            
    }
    
#endif

    

    
    
}
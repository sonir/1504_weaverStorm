//
//  SeqManager.cpp
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#include "SeqManager.h"

void SeqManager::executeOneQuantum(quantum *q){
    
    
     sc_color = (color_e)q->param1;
     notice->notify("changeScreenColor", &sc_color);
     q->done = true;

    
    
}
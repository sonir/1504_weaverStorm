//
//  SeqManager.h
//  yagiSys
//
//  Created by sonir on 6/28/15.
//
//

#ifndef __yagiSys__SeqManager__
#define __yagiSys__SeqManager__

#include <stdio.h>
#include "slSequencer.h"
#include "setup.h"

typedef enum {TEST2, FAST, MID, SLOW} command_e;
typedef enum {RED,GREEN,BLUE,BLACK} color_e;
typedef struct note_t { //Using trigger with duration (=sustain_time)
    
    command_e cmd;
    int number;
    float duration;
    
}note_t;

class SeqManager : public slSequencer {
  
    public:
        void executeOneQuantum(quantum *q);
        color_e sc_color = BLACK;

};

#endif /* defined(__yagiSys__SeqManager__) */

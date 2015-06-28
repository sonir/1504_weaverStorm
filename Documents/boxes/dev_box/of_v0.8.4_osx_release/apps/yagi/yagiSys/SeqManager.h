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

typedef enum {RED,GREEN,BLUE,BLACK} color_e;

class SeqManager : public slSequencer {
  
    public:
        void executeOneQuantum(quantum *q);
        color_e sc_color = BLACK;

};

#endif /* defined(__yagiSys__SeqManager__) */

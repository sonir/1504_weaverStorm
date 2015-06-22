//
//  Yagi.h
//  yagiSys
//
//  Created by sonir on 6/22/15.
//
//

#ifndef __yagiSys__Yagi__
#define __yagiSys__Yagi__

#include <stdio.h>
#include "slAppManager.h"
#include "ygSequencer.h"


class YagiApp : public slAppManager {
    
    public:
        Sequencer sqcr;
        void setup();
        void update();
    
};

#endif /* defined(__yagiSys__Yagi__) */

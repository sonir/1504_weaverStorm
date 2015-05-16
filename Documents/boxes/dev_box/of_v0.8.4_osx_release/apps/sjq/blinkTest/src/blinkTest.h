//
//  blinkTest.h
//  blinkTest
//
//  Created by sonir on 5/15/15.
//
//

#ifndef __blinkTest__blinkTest__
#define __blinkTest__blinkTest__

#define SQ_COLUMN 8
#define SQ_ROW 4
#define NODE_NUM SQ_COLUMN * SQ_ROW
#define NUM_SPECICAL_NODE 3
#define SQ_SIZE 60.0
#define SQ_MARGIN 0.3


#include <stdio.h>
#include "slAppManager.h"

class blinkTest: slAppManager {
    
    public:
        void setup();
        void update();
        bool checkSpecial(int index);
        void createSpecialNode();
        void createSpecialNodes(int node_num);
        bool theSpecialNodeExits(int index);
        void resetSpecials();
    
        int pre_rnd_index;
        bool special_nodes[NODE_NUM];

    
};



#endif /* defined(__blinkTest__blinkTest__) */

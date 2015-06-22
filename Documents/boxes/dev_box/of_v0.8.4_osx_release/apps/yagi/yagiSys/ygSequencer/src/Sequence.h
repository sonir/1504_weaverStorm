//
//  Sequence.h
//  yagiSys
//
//  Created by sonir on 6/16/15.
//
//

#ifndef __yagiSys__Sequence__
#define __yagiSys__Sequence__

#define QUANTUM_ELEMENTS_NUM 5
#define QUANTUMS_TOP_INDEX 2


#include <stdio.h>
#include <iostream>
#include <vector>
#include "slChrono.h"

//Function prototype
int64_t mergeInt32to64(unsigned int hi, unsigned int low);


typedef enum {TEST} command;

typedef struct quantum {
    
    bool done;
    int delta;
    command cmd;
    float param1;
    float param2;
    float param3;
    
} quantum ;


//C Func for merge ints
int64_t mergeInt32to64(unsigned int hi, unsigned int low){
    
    int64_t int64;
    
    int64 = (int64_t)hi;
    int64 = int64 << 32; //Bitshift to HiBit
    int64 += (int64_t)low; //Write remainbit to
    
    return int64;
    
}


class Sequence {

    public:
        Sequence(){
            
            
        };
        void print();
    
        bool finished = false;
        time_t st;
        chrono_t st_usec = -1;
        int qtm_count = 0;
        std::vector<quantum> quantums;
    
    
};

#endif /* defined(__yagiSys__Sequence__) */

#define DEBUG
#define MSEC_TO_CHRONO 1000

#include <stdio.h>
#include <iostream>
#include <vector>
#include <time.h>
#include "Sequence.h"

typedef enum {RED,GREEN,BLUE,BLACK} color_e;

class Sequencer{
    
    public:
        Sequencer(){
            
            sc_color = BLACK;
            
        }
        void setup();
        void update();
        void execute(Sequence *s);
        bool checkTheSequenceIsFinished(Sequence *s);
    
        std::vector<Sequence> sequences;
        time_t now;
        chrono_t now_usec;
        slChrono chrono;
        color_e sc_color;

    
    
};
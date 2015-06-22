//
//  PerformanceManager.h
//  mtPerformanceManager
//
//  Created by sonir on 5/29/15.
//
//

#ifndef __mtPerformanceManager__PerformanceManager__
#define __mtPerformanceManager__PerformanceManager__

#define MULTICAST "224.0.0.1"
#define PORT_MOBILE 65137
#define PORT_FIS 54322
#define PORT_ABLETON 63137
#define CH_CATCH_BALL_TRIGGER_FOR_M4L "/ch4"


#define INIT_PHASE GLITCH
#define PLAYER_NUM 6

#include <stdio.h>
#include <assert.h>
#include "slOscManager.h"
#include "Desitination.h"

enum phase_e {GLITCH, CATCHBALL, BLINK, CALM, FINAL};
enum player_type_e {NONE, PF, TB, GT, BA, DR};
enum color_e{WHITE, RED, YELLOW, BLUE, GREEN} flush_color;

class PerformanceManager: public slOscManager{
    
    public:
        PerformanceManager(int port) : slOscManager(port) {
            
            mobile = new Destination(MULTICAST, PORT_MOBILE);
            fis = new Destination(MULTICAST, PORT_FIS);
            ableton = new Destination(MULTICAST, PORT_ABLETON);
            
        
        };
        
        void setup(){
            
            setPhase(INIT_PHASE);
            
        };
        
        void update(){
            
            slOscManager::update();
            
        }
        
        void fireMessage(ofxOscMessage *m);
        void atkEvent(player_type_e player, phase_e ph);
        void setPhase(phase_e ph);
    
        Destination *mobile;
        Destination *fis;
        Destination *ableton;
        phase_e phase;
        string phase_str;
        string last_adr = "n/a";
        int note;
    
    
};

#endif /* defined(__mtPerformanceManager__PerformanceManager__) */

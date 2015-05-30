//
//  PerformanceManager.cpp
//  mtPerformanceManager
//
//  Created by sonir on 5/29/15.
//
//

#include "PerformanceManager.h"

using namespace std;

void PerformanceManager::fireMessage(ofxOscMessage *m){
    
    last_adr = m->getAddress();

    
    if(m->getAddress() == "/test1"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(test1, fnum);
    } else if(m->getAddress() == "/sjq/performance/phase"){
        setPhase((phase_e)m->getArgAsInt32(0));
        
    } else if(m->getAddress() == "/sjq/performer/play"){
        
        if(phase==CATCHBALL){ //This massage was utilized by CATCHBALL only.
            string adr = "/fis/comes";
            fis->send(adr,(player_type_e)m->getArgAsInt32(0));
        }
        
    } else if(m->getAddress() == "/sjq/performance/blink/hit"){
        if(phase==BLINK){
            player_type_e player = (player_type_e)m->getArgAsInt32(0);
            string adr = "/fis/blink";
            color_e color;
            switch(player){
                    
                case NONE:
                    color = WHITE;
                    break;

                case PF:
                    color = RED;
                    break;
                    
                case TB:
                    color = GREEN;
                    break;
                    
                case GT:
                    color = WHITE;
                    break;
                   
                case BA:
                    color = BLUE;
                    break;

                case DR:
                    color = YELLOW;
                    break;
                    
            }
            fis->send(adr,player,color);
        }
        
    } else if(m->getAddress() == "/performance/square/removed"){
        cout << "foo" << endl;
            player_type_e player = (player_type_e)m->getArgAsInt32(0);
            int count_removed = m->getArgAsInt32(1);
            mobile->send("/sjq/mobile/catchball/bang", player, count_removed);
        
    } else if(m->getAddress() == "/sjq/performance/atk"){
        player_type_e player = (player_type_e)m->getArgAsInt32(0);
        if(phase==GLITCH){
            note=m->getArgAsInt32(1);
        }
        atkEvent(player, phase);
//        std::string str = std::to_string(player);
//        last_adr+=std::to_string(player);
    }
    
    
}


void PerformanceManager::atkEvent(player_type_e player, phase_e ph){
    
    //Write destribution code here.
    //TODO: here
    
    switch(ph){
            
        case GLITCH:
            if(note<0)note =0;
            mobile->send("/sjq/mobile/glitch/bang" , player, note);
            break;

        case CATCHBALL:
            fis->send("/fis/go", player, WHITE);
            break;

        case BLINK:
            if(player==DR)mobile->send("/sjq/mobile/blink/bang" , player);
            break;

        case CALM:
            break;
            
        case FINAL:
            break;

        default:
            cout << "unknown attack event" << endl;
            break;
            
    }
    
}



void PerformanceManager::setPhase(phase_e ph){
    
    switch(ph){
            
        case GLITCH:
            phase_str = "GLITCH";
            break;
            
        case CATCHBALL:
            phase_str = "CATCHBALL";
            break;
            
        case BLINK:
            phase_str = "BLINK";
            break;
        
        case CALM:
            phase_str = "CALM";
            break;
            
        case FINAL:
            phase_str = "FINAL";
            break;
            
        default:
            cout << "ERR:unknown attack event" << endl;
                return;
            break;
            
    }
    
    phase = ph;

    
}

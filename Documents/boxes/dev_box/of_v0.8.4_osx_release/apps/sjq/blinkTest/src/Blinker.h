//
//  Blinker.h
//  blinkTest
//
//  Created by sonir on 5/16/15.
//
//

#ifndef __blinkTest__Blinker__
#define __blinkTest__Blinker__

#include <stdio.h>

class Blinker {

    public:
        Blinker(int dur){
            
            duration = dur;
        }
    
        int update (){
        
            if(counter<duration){
                
                counter++;
                if(positive) return 1;
                else return 0;
                
            }else{
                
                //Invert
                if(positive)positive = false;
                else positive = true;
                counter = 0; // reset counter
                if(positive) return 1;
                else return 0;
                
            }
            
        }
    
        int now(){

            if(positive) return 1;
            else return 0;
            
        }
    
        int counter = 0;
        bool positive = true;
        int duration;
    
    
};

#endif /* defined(__blinkTest__Blinker__) */

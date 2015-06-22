//
//  Sequence.cpp
//  yagiSys
//
//  Created by sonir on 6/16/15.
//
//

#include "Sequence.h"

using namespace std;


void Sequence::print(){

    
    cout << "finished:" << finished << endl;
    cout << "st:" << st << endl;
    cout << "qtm_count:" << qtm_count << endl;
    
    for(int i=0; i<qtm_count; i++){
        
        quantum q = quantums[i];
        
        cout << "--Quantm " << i << " --" << endl;
        cout << "delta:" << q.delta << endl;
        cout << "command:" << q.cmd << endl;
        cout << "param1:" << q.param1 << endl;
        cout << "param2:" << q.param2 << endl;
        cout << "param3:" << q.param3 << endl;
        
    }
    
    
}
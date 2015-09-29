//
//  Time.h
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#ifndef __Project4__Time__
#define __Project4__Time__

#include <iostream>
#include <string>

using namespace std;

class Time

{
public:
    
    short hour;
    short minute;
    
    
    Time();
    
    Time(short hour, short minute) throw (logic_error);
    
    static short elapsedMin(Time t1, Time t2);
    
    string toString();
    
    
};

#endif /* defined(__Project4__Time__) */
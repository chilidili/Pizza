//
//  Time.cpp
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#include "Time.h"


using namespace std;

Time::Time()
{
    hour = minute = 0;
}


Time::Time(short hour, short minute) throw (logic_error)

{
    if( hour< 0 || hour > 23 || minute < 0 || minute > 59)
    {
        logic_error err1 ("Invalid hour or minute");
        throw (err1);
    }
        this-> hour = hour;
    this-> minute = minute;
    
}

 short Time:: elapsedMin(Time t1, Time t2)

{
    return (60 * (t2.hour-t1.hour) + (t2.minute - t1.minute));
}


string Time:: toString()
{
    return( to_string(hour) + ":" + to_string(minute));
    
}


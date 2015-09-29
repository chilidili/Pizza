//
//  Order.h
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#ifndef __Project4__Order__
#define __Project4__Order__

#include <iostream>
#include <string>
#include "Time.h"

using namespace std;

class Order
{
    
public:
    
    
    enum state {AT_RESTAURANT, SERVED, DELIVERING, DELIVERED};
    
    state s; 
    
    Time orderTime;
    
    Time deliverTime;
    
    string info;
    
    Order();
    
    Order(Time time, string info);
    
    void depart() throw (logic_error);
    
    void deliver(Time time) throw (logic_error);
    
    short getMinToDelivery() throw (logic_error);
    
    string toString();
    
};

#endif /* defined(__Project4__Order__) */

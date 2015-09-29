//
//  Order.cpp
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#include "Order.h"
#include "Time.h"

using namespace std;

Order::Order()
{
    orderTime.hour = orderTime.minute = 0;
    
    deliverTime.hour = deliverTime.minute = 0;
    
    s = AT_RESTAURANT;
    
    info = " ";
    
    
}

Order::Order(Time time, string info)
{
    orderTime = time;
    
    deliverTime.hour = deliverTime.minute = 0;
    
    s = AT_RESTAURANT;
    
    this->info = info;
}

void Order::depart() throw (logic_error)

{
    if( s == AT_RESTAURANT)
    {
        
    logic_error err1 ("This order is not at the restaurant. ");
        throw(err1);
    }
    
    s = DELIVERING;
}

short Order::getMinToDelivery() throw (logic_error)

{
    if( s != DELIVERED)
    {
        
        logic_error err1 ("This order is not currently being");
        throw(err1);
    }

    return (Time::elapsedMin(orderTime, deliverTime));
    
}

string Order::toString()
{
    return ("State: " + to_string(s) + "\nOrder Time: " + orderTime.toString() + "\nDeliver Time: " + deliverTime.toString() + "Info: " + info);
}





//
//  Restaurant.h
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#ifndef __Project4__Restaurant__
#define __Project4__Restaurant__

#include <iostream>
#include <string>
#include "Time.h"
#include "Order.h"
#include <vector>
#include <queue>

using namespace std;

class Restaurant
{
public:
    
    vector<Driver> drivers;
    
    queue<Order> cooking;
    
    queue<Order> departure;
    
    Restaurant();
    
    void status();
    
    void summary();
    
    Driver * getDriver(string name);
    
    void addDriver(Driver * driver);
    
    void addOrder(Order * order);
    
    void serveNextOrder() throw(logic_error);
    
    Order * departNextOrder() throw(logic_error);
    
    void deliver(Driver * driver, Time time, float tip);
    
};





#endif /* defined(__Project4__Restaurant__) */

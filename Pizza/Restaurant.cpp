//
//  Restaurant.cpp
//  Project4
//
//  Created by Lab User on 4/23/14.
//  Copyright (c) 2014 Kiera Dobbs. All rights reserved.
//

#include "Restaurant.h"
#include <iostream>
#include <string>
#include "Time.h"
#include "Order.h"
#include <vector>
#include <queue>

using namespace std;


Restaurant:: Restaurant()
{
    drivers = {0};
}

void Restaurant:: status()
{
    queue<Order> tempC (cooking);
    
    cout << "Orders waiting to cook:\n" << endl;
    
    for (int x = 0; x < tempC.size(); x++)
    {
        cout << "Position " << x << " in the cooking queue: " << &tempC.front() << endl;
        tempC.pop();
    }
    
    
    queue<Order> tempD (departure);
    
    cout << "\nOrders waiting to depart:\n" << endl;
    
    for (int x = 0; x < tempD.size(); x++)
    {
        cout << "Position " << x << " in the departure queue: " << &tempD.front() << endl;
        tempD.pop();
    }

    
    cout << "\nLogged-in drivers and their status:\n" << endl;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        if (drivers[x].isLoggedIn())
        {
            cout << drivers[x].toString() << endl;
        }
    }

}



void Restaurant:: summary()
{
    cout << "\nTotal number of deliveries completed:" << endl;
    
    int sum = 0;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        sum += drivers[x].getTotalDeliveries();
    }
    
    cout << sum << endl;
    
    
    cout << "\nAverage time per order:\n" << endl;
    
    
    
    
    
    
    cout << "\nNumber of deliveries completed by each driver:\n" << endl;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        cout << drivers[x].getName() << " delivered " << drivers[x].getTotalDeliveries() << " deliveries." << endl;
    }

    //Second is the part of the method:
    //void Restaurant:: summary()
    //where you have to print out the average time per order (from "order" to "deliver").
    //I think this might involve the getMinToDelivery() method in the Order class, but I couldn't get anything working.
    cout << "\nAverage time from depart to deliver for each driver:\n" << endl;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        cout << drivers[x].getName() << ": " << (drivers[x].getTotalMinDelivering())/(drivers[x].getTotalDeliveries()) << " minutes." << endl;
    }
    
    
    cout << "\nTotal minutes spent driving for each driver:\n" << endl;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        cout << drivers[x].getName() << ": " << drivers[x].getTotalMinDriving() << " minutes." << endl;
    }
    
    
    cout << "\nTotal tips received by each driver:\n" << endl;
    
    for (int x = 0; x < drivers.size(); x++)
    {
        cout << drivers[x].getName() << ": " << drivers[x].getTotalTips() << " dollars." << endl;
    }
}

Driver * Restaurant:: getDriver(string name)
{
    for (int x = 0; x < drivers.size(); x++)
    {
        if (drivers[x] == name)
        {
            return *drivers[x];
        }
    }
}

void Restaurant:: addDriver(Driver * driver)
{
    drivers.push_back(driver);
}

void Restaurant:: addOrder(Order * order)
{
    cooking.push(*order);
}

void Restaurant:: serveNextOrder() throw(logic_error)
{
    if (cooking.size() == 0)
    {
        logic_error err1 ("The cooking queue is empty.");
        throw(err1);
    }
    
    departure.push(cooking.front());
    
    cooking.pop();
}

Order * Restaurant:: departNextOrder() throw(logic_error)
{
    if (departure.size() == 0)
    {
        logic_error err1 ("The departure queue is empty.");
        throw(err1);
    }
    
    return departure.front();
    
    departure.pop();
}

void Restaurant:: deliver(Driver * driver, Time time, float tip)
{
    driver.deliver(time, tip);
}

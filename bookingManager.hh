#include<string>
#include<list>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include "flightManager.hh"
#include "Bookings.hh"
#include "Flights.hh"
using namespace std;
#ifndef BOOKINGMANAGER
#define BOOKINGMANAGER

class bookingManager
{
    list<Bookings *> myBookings;
    public:
    bookingManager(){}
    void readBookings(string filename);
    list<Bookings *> get_bookingsList();

};
#endif
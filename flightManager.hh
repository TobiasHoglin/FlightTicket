#include<iostream>
#include<cstdlib>
#include<iterator>
#include<list>
#include<fstream>
#include<fstream>
#include<sstream>
#include<cstring>
#include "Flights.hh"
#include "Bookings.hh"
using namespace std;
#ifndef FLIGHTMANAGER
#define FLIGHTMANAGER

class flightManager
{
    list<Flights *> myFlights;
    
    public:
    flightManager(){}
    void readFlights(string filename);
    list<Flights *> get_flighList();
   
};
#endif
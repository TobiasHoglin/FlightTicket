#ifndef TICKETMANAGER
#define TICKETMANAGER
#include<iostream>
#include<cstdlib>
#include<iterator>
#include<list>
#include<fstream>
#include<sstream>
#include<cstring>
#include "Flights.hh"
#include "Bookings.hh"
using namespace std;

class ticketManager
{
public:
    void seatMap(list<Flights *> myFlights);
    void canceledflights(list<Flights *> myFlights);
    void matchseat(list<Flights *> myFlights, list<Bookings *> myBookings);


};
#endif

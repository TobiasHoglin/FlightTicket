/**
 * @file flightTickets.cpp
 * @author Tobias Höglin (tobias.hoglin@gmail.com)
 * @brief Ticket program, prints tickets from bookings and flights csv files
 * @version 0.1
 * @date 2022-11-23
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<cstdlib>
#include<iterator>
#include<list>
#include<fstream>
#include<sstream>
#include<cstring>
#include<unistd.h>
#include "Flights.hh"
#include "Bookings.hh"
#include "flightManager.hh"
#include "ticketManager.hh"
#include "bookingManager.hh"
using namespace std;

/**
 * @brief Main entry flighTickets.cpp 
 * 
 * @return int 
 */

int main(int argc, char** argv)
{   
    flightManager fm;
    bookingManager bm;
    int opt;
    while((opt=getopt(argc, argv, "f:b:"))!=-1)
    {
        switch (opt)
        {
            case 'f': 
            fm.readFlights(optarg);
            break;

            case 'b':
            bm.readBookings(optarg);
            break;

        }
    
    }
    
    //fm.readFlights("flights.csv");
    //bm.readBookings("bookings.csv");
    ticketManager tm;
    tm.matchseat(fm.get_flighList(), bm.get_bookingsList());
    tm.canceledflights(fm.get_flighList());
    tm.seatMap(fm.get_flighList());
    cout << "Tickets and seatmaps printed"<< endl;
    
    return 0;
}


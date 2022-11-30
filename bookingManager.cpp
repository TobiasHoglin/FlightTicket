#include<string>
#include<list>
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include "flightManager.hh"
#include "Bookings.hh"
#include "Flights.hh"
#include "bookingManager.hh"
using namespace std;
/**
 * @brief 
 * 
 */
    
void bookingManager::readBookings(string filename)
{
    ifstream infile(filename);
    string line;
    if(infile.is_open())
    {
        while(getline(infile,line))
        {
            stringstream sstr(line);
            Bookings *b = new Bookings;
            string temp;
            getline(sstr,temp,',');
            b->set_bookingno(atoi(temp.c_str()));
            getline(sstr,temp,',');
            b->set_datestr(temp);
            getline(sstr,temp,',');
            b->set_timestr(temp);
            getline(sstr,temp,',');
            b->set_dep(temp);
            getline(sstr,temp,',');
            b->set_des(temp);
            getline(sstr,temp,',');
            b->set_sclasss(temp);
            getline(sstr,temp,',');
            b->set_fname(temp);
            getline(sstr,temp,',');
            b->set_lname(temp);
                
            myBookings.push_back(b);
        } 
        infile.close();              
    }
} 
list<Bookings *> bookingManager::get_bookingsList()
{
return myBookings;
}


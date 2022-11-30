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

        
void flightManager::readFlights(string filename)
{
    ifstream infile(filename);
    string line;
    if(infile.is_open())
    {
        while(getline(infile,line))
        {
            stringstream sstr(line);
            Flights *f = new Flights;
            string temp;

            getline(sstr,temp,',');
            f->set_flightno(atoi(temp.c_str()));

            getline(sstr,temp,',');
            f->set_dep(temp);
            getline(sstr,temp,',');
            f->set_des(temp);
            getline(sstr,temp,',');
            f->set_datestr(temp);
            getline(sstr,temp,',');
            f->set_timestr(temp);
            getline(sstr,temp,',');
            f->set_nfs(atoi(temp.c_str()));
            getline(sstr,temp,',');
            f->set_nbs(atoi(temp.c_str()));
            getline(sstr,temp,',');
            f->set_nes(atoi(temp.c_str()));
                
            myFlights.push_back(f);
        } 
        infile.close();              
    } 
}

list<Flights *> flightManager::get_flighList()
{
    return myFlights;
}


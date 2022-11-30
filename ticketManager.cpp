#include<iostream>
#include<cstdlib>
#include<iterator>
#include<list>
#include<fstream>
#include<sstream>
#include<cstring>
#include "ticketManager.hh"
#include "Flights.hh"
#include "Bookings.hh"
#include "flightManager.hh"
using namespace std;


    /**
     * @brief printing seat maps for each bookingclass using counters nfs, nbs and es. Resizing plane to
     * normal size to make better looking seatmaps.
     * 
     * @param myFlights 
     */

    void ticketManager::seatMap(list<Flights *> myFlights)
    {

        list<Flights *>::iterator fit;
        char filename[100];
        for(fit = myFlights.begin(); fit != myFlights.end(); ++fit)
        {
		    sprintf(filename, "Flightmap-%d, %s", (*fit)->get_flightno(), (*fit)->get_timestr().c_str());
		    ofstream outfile(filename);
            if(outfile.is_open())
            {
                int nfs = (*fit)->get_nfs();
                int fs = (*fit)->get_fs();
                nfs /= 7;
                outfile << "First class" << endl;
			    for(int i = 0; i < nfs; i++)
			    {
                        if((i+1)%7==3 || (i+1)%7==6){outfile << " ";}
                        if(i<fs) outfile << "[1]";
                        else outfile << "[0]"; 
                        if((i+1)%7==0){outfile << "\n";}
                }  
                
                int nbs = (*fit)->get_nbs();
                int bs = (*fit)->get_bs();
                nbs /= 7;
                outfile << "\nBusiness class" << endl;
                for(int i = 0; i < nbs; i++)
			    {
                        if((i+1)%7==3 || (i+1)%7==6){outfile << " ";}
                        if(i<bs) outfile << "[1]";
                        else outfile << "[0]"; 
                        if((i+1)%7==0){outfile << "\n";}
                }
                int nes = (*fit)->get_nes();
                int es = (*fit)->get_es();
                nes /= 7;
                outfile << "\nEconomy class" << endl;
                for(int i = 0; i < nes; i++)
			    {
                        if((i+1)%7==3 || (i+1)%7==6){outfile << " ";}
                        if(i<es) outfile << "[1]";
                        else outfile << "[0]"; 
                        if((i+1)%7==0){outfile << "\n";}
                }    
            }
        }
    }


    
    void ticketManager::canceledflights(list<Flights *> myFlights)
    {
        list<Flights *>::iterator fit;
        for(fit = myFlights.begin() ; fit != myFlights.end() ; ++fit)
        if((*fit)->get_fs() == 0 && (*fit)->get_bs() == 0 && (*fit)->get_es() == 0)
        {
            ofstream outfile("canceled-flights.txt", std::ios_base::app);
            if(outfile.is_open())
            {
                outfile << "Flight nr " << (*fit)->get_flightno() << " " << (*fit)->get_timestr() << " is canceled" << endl;
            }
        }
    }

/**
 * @brief 
 * Finds matching flight allocate seat and print flight and booking information to ticket file.
 * @param myFlights 
 * @param myBookings 
 */
    void ticketManager::matchseat(list<Flights *> myFlights, list<Bookings *> myBookings)
    {
        
        list<Bookings *>::iterator bit;
        list<Flights *>::iterator fit;
        
        for(bit = myBookings.begin() ; bit != myBookings.end(); ++bit)
        { 
            for(fit = myFlights.begin() ; fit != myFlights.end() ; ++fit)
            {
                if((*bit)->get_dep() == (*fit)->get_dep() && (*bit)->get_des() == (*fit)->get_des() && (*bit)->get_datestr() == (*fit)->get_datestr() && (*bit)->get_timestr() == (*fit)->get_timestr() )
                {   
                    int seat;
                    int row;
                    if((*bit)->get_sclass() == "first")
                    {
                        (*fit)->increaseFs();
                        row = (*fit)->get_fs()/7+1;
                        seat = (*fit)->get_fs();
                    }


                    if((*bit)->get_sclass() == "business")
                    {
                        (*fit)->increaseBs();
                        seat = (*fit)->get_bs()+(*fit)->get_nfs();
                        row = seat/7+1;
                    }
                    if((*bit)->get_sclass() == "economy")
                    {
                        (*fit)->increaseEs();
                        seat = (*fit)->get_es()+(*fit)->get_nfs()+(*fit)->get_nbs();
                        row = seat/7+1;
                    }
                    char filename[20]; 
                    sprintf(filename, "ticket-%d.txt", (*bit)->get_bookingsno());
                    ofstream outfile(filename);
                    if(outfile.is_open())
                    {
                        outfile << "BOOKING:" << (*bit)->get_bookingsno() << endl;
                        outfile << "FLIGHT:" << (*fit)->get_flightno();
                        outfile << " DEPARTURE:" << (*fit)->get_dep();
                        outfile << " DESTINATION:" <<(*fit)->get_des();
                        outfile << " " << (*fit)->get_datestr() << " ";
                        outfile << (*fit)->get_timestr() << endl;
                        outfile << "PASSENGER " << (*bit)->get_fname() << " " << (*bit)->get_lname();
                        outfile << " CLASS: " << (*bit)->get_sclass() << endl;
                        outfile << "ROW: " << row << " SEAT " << seat << endl;

                    }
                }
            }
        }
    }

#include<string>
using namespace std;
#ifndef BOOKINGS_CLASS
#define BOOKINGS_CLASS


/**
 * @brief Bookings class. Containing booking information.
 * 
 */

class Bookings
{
private:
    int bookingno;
    string datestr;
    string timestr;
    string dep;
    string des;
    string sclass;
    string fname;
    string lname;

public:
    Bookings(){}
    /**
     * @brief Setters to the bookings objects attributes.
     */
    void set_bookingno(int bookingno){this->bookingno = bookingno;}
    void set_datestr(string datestr){this->datestr = datestr; }
    void set_timestr(string timestr){this->timestr = timestr;}
    void set_dep(string dep){this->dep = dep;}
    void set_des(string des){this->des = des;}
    void set_sclasss(string sclass){this->sclass = sclass;}
    void set_fname(string fname){this->fname = fname;}
    void set_lname(string lname){this->lname = lname;}
    // getters
    int get_bookingsno(){return bookingno;}
    string get_datestr(){return datestr;}
    string get_timestr(){return timestr;}
    string get_dep(){return dep;}
    string get_des(){return des;}
    string get_sclass(){return sclass;}
    string get_fname(){return fname;}
    string get_lname(){return lname;}
};
#endif

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>

class Clock
{
    //Overload dataStream operators
        friend std::ostream& operator<<(std::ostream&, const Clock&);
        friend std::istream& operator>>(std::istream&, Clock&);
    //Overload increment operator
        friend Clock operator++(Clock&);
    //Overload boolean comparison operators
        friend bool operator==(const Clock&, const Clock&);
        friend bool operator!=(const Clock&, const Clock&);
        friend bool operator<=(const Clock&, const Clock&);
        friend bool operator< (const Clock&, const Clock&);
        friend bool operator>=(const Clock&, const Clock&);
        friend bool operator> (const Clock&, const Clock&);
    public:
    //Constructor
        Clock();
        Clock(int);
        Clock(int, int);
        Clock(int, int, int);
        Clock(Clock&);
    //Get methods
        int getHour();
        int getMinute();
        int getSecond();
    //Set methods
        void setHour(int);
        void setMinute(int);
        void setSecond(int);
    private:
        int hour;
        int minute;
        int second;
};
#endif
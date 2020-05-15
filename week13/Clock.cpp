#include "Clock.h"
#include <iostream>

//Constructors
Clock::Clock()
{
    hour = 0;
    minute = 0;
    second = 0;
}
Clock::Clock(int a)
{
    hour = a;
    minute = 0;
    second = 0;
}
Clock::Clock(int a, int b)
{
    hour = a;
    minute = b;
    second = 0;
}
Clock::Clock(int a, int b, int c)
{
    hour = a;
    minute = b;
    second = c;
}
Clock::Clock(Clock& clock)
{
    hour = clock.getHour();
    minute = clock.getMinute();
    second = clock.getSecond();
}

//Get methods
int Clock::getHour()
{
    return hour;
}
int Clock::getMinute()
{
    return minute;
}
int Clock::getSecond()
{
    return second;
}

//Set methods
void Clock::setHour(int inputHour)
{
    hour = inputHour;
    return;
}
void Clock::setMinute(int inputMinute)
{
    minute = inputMinute;
    return;
}
void Clock::setSecond(int inputSecond)
{
    second = inputSecond;
    return;
}

//Overload dataStream operators
std::ostream& operator<<(std::ostream& output, const Clock& clock)
{
    output << std::endl << clock.hour << " : " << clock.minute << " : " << clock.second;
    return output;
}

std::istream& operator>>(std::istream& input, Clock& clock)
{
    input >> clock.hour >> clock.minute >> clock.second;
    return input;
}

//Overload increment operator
Clock operator++(Clock& clock)
{
    //increment seconds
    ++clock.second;
    //increment minutes if second >= 60 and reset second
    if(clock.second >= 60)
    {
        ++clock.minute;
        clock.second = 0;
    }
    //increment hour if minute >= 60 and reset minute
    if(clock.minute >= 60)
    {
        ++clock.hour;
        clock.minute = 0;
    }
    //if minute >= 24, reset hour
    if(clock.hour >= 24)
    {
        clock.hour = 0;
    }

    return clock;
}

//Overload boolean comparison operators
bool operator==(const Clock& clock1, const Clock& clock2)
{
    if(clock1.hour == clock2.hour && clock1.minute == clock2.minute && clock1.second == clock2.second)
    {
        return true;
    }
    return false;
}

bool operator!=(const Clock& clock1, const Clock& clock2) 
{
    if(clock1.hour == clock2.hour && clock1.minute == clock2.minute && clock1.second == clock2.second)
    {
        return false;
    }

    return true;
}

bool operator<=(const Clock& clock1, const Clock& clock2) 
{
    if(clock1.hour < clock2.hour)
    {
        return true;
    }
    else if(clock1.hour == clock2.hour)
    {
        if(clock1.minute < clock2.minute)
        {
            return true;
        }
        else if(clock1.minute == clock2.minute)
        {
            if(clock1.second <= clock2.second)
            {
                return true;
            }
        }
    }
    return false;
}

bool operator<(const Clock& clock1, const Clock& clock2) 
{
    if(clock1.hour < clock2.hour)
    {
        return true;
    }
    else if(clock1.hour == clock2.hour)
    {
        if(clock1.minute < clock2.minute)
        {
            return true;
        }
        else if(clock1.minute == clock2.minute)
        {
            if(clock1.second < clock2.second)
            {
                return true;
            }
        }
    }
    return false;
}

bool operator>=(const Clock& clock1, const Clock& clock2) 
{
    if(clock1.hour > clock2.hour)
    {
        return true;
    }
    else if(clock1.hour == clock2.hour)
    {
        if(clock1.minute > clock2.minute)
        {
            return true;
        }
        else if(clock1.minute == clock2.minute)
        {
            if(clock1.second >= clock2.second)
            {
                return true;
            }
        }
    }
    return false;
}

bool operator>(const Clock& clock1, const Clock& clock2) 
{
    if(clock1.hour > clock2.hour)
    {
        return true;
    }
    else if(clock1.hour == clock2.hour)
    {
        if(clock1.minute > clock2.minute)
        {
            return true;
        }
        else if(clock1.minute == clock2.minute)
        {
            if(clock1.second > clock2.second)
            {
                return true;
            }
        }
    }
    return false;
}
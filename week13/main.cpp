#include "Clock.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int tempHour, tempMinute, tempSecond;
    Clock realTimeClock,alarmClock;

    cout << "Input accurate time: ";
    cin >> realTimeClock;
    cout << "Input alarm time: ";
    cin >> alarmClock;

    while(realTimeClock != alarmClock)
    {
        //system("CLS"); does not work on my operating system but I tried :)
        cout << realTimeClock << flush;
        ++realTimeClock;
    }
    cout << "\n\n*-*-*-*-*-*-*-*-*-*ALARM*-*-*-*-*-*-*-*-*-*";

    return 0;
};
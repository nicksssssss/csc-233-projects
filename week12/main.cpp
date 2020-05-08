#include <iostream>
#include <string>
#include <vector>
#include "Course.h"
#include "CurriculumCourse.h"
#include "ContinuingCourse.h"

using namespace std;

int main()
{
    int menuOption = 0, totalClasses = 0;
    vector <Course*> schedule;

    while(menuOption != 4)
    {
        cout << "\nMain Menu";
        cout << "\n1. Add a curriculum class to schedule";
        cout << "\n2. Add a continuing education class to schedule";
        cout << "\n3. Display all records";
        cout << "\n4. Exit\n\n";

        cin >> menuOption;
        if(menuOption == 1)
        {
            CurriculumCourse * cc = new CurriculumCourse();
            (*cc).setInfo();
            schedule.push_back(cc);
            totalClasses++;
        }
        else if(menuOption == 2)
        {
            ContinuingCourse * cc = new ContinuingCourse();
            (*cc).setInfo();
            schedule.push_back(cc);
            totalClasses++;
        }
        else if(menuOption == 3)
        {
            for(int i = 0; i < totalClasses; i++)
            {
                (*schedule[i]).show();
            }
        }
        else if(menuOption == 4)
        {
            break;
        }
        else
        {
            cout << "\nIncorrect input. Try again.\n\n";
        }
    }


    return 0;
}
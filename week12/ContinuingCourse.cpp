#include "Course.h"
#include "ContinuingCourse.h"
#include <iostream>
#include <string>


float fee;

ContinuingCourse::ContinuingCourse(){}
ContinuingCourse::ContinuingCourse(int courseId, std::string title, int roomNumber, float contactHours, float fee)
: Course(courseId, title, roomNumber, contactHours)
{
    this->fee = fee;
}

void ContinuingCourse::setInfo()
{
    Course::setInfo();
    std::cout << "\nEnter course fee.\n";
    std::cin >> fee;
}

void ContinuingCourse::show()
{
    Course::show();
    std::cout << "Course Fee: " << fee;
}
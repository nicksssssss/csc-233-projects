#include "Course.h"
#include <iostream>



Course::Course()
{}
Course::Course(int courseId, std::string title, int roomNumber, float contactHours)
{
    (*this).courseId = courseId;
    this->title = title;
    this->roomNumber = roomNumber;
    this->contactHours = contactHours;
}

void Course::setInfo()
{
    std::cout << "\nEnter course id, course title, room number, and contact hours.\n";
    std::cin >> courseId >> title >> roomNumber >> contactHours;
}

void Course::show()
{
    std::cout << "\n\nCourse ID: " << courseId;
    std::cout << "\nCourse Title: " << title;
    std::cout << "\nRoom Number: " << roomNumber;
    std::cout << "\nAmount of Contact Hours Available: " << contactHours;
}

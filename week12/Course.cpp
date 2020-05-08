#include "Course.h"
#include <iostream>


class Course
{
    private:
        int courseId;
        std::string title;
        int roomNumber;
        float contactHours;

    public:
        Course(int courseId, std::string title, int roomNumber, float contactHours)
        {
            this->courseId = courseId;
            this->title = title;
            this->roomNumber = roomNumber;
            this->contactHours = contactHours;
        }
        void show()
        {
            std::cout << "\n\nCourse ID: " << courseId;
            std::cout << "\nCourse Title: " << title;
            std::cout << "\nRoom Number: " << roomNumber;
            std::cout << "\nAmount of Contact Hours Available: " << contactHours;
        }
};
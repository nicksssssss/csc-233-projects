#include "Course.h"
#include "CurriculumCourse.h"
#include <iostream>



    float creditHours;
    float tuitionRate;

    CurriculumCourse::CurriculumCourse()
    {}
    CurriculumCourse::CurriculumCourse(int courseId, std::string title, int roomNumber, float contactHours, float creditHours, float tuitionRate) 
    : Course(courseId, title, roomNumber, contactHours)
    {
        this->creditHours = creditHours;
        this->tuitionRate = tuitionRate;
    }

    void CurriculumCourse::setInfo()
    {
        Course::setInfo();
        std::cout << "\nEnter credit hours and tuition rate.\n";
        std::cin >> creditHours >> tuitionRate;
    }

    void CurriculumCourse::show()
    {
        Course::show();
        std::cout << "\nCredit Hours: " << creditHours;
        std::cout << "\nTuition Rate: " << tuitionRate;
    }
    float CurriculumCourse::calculateTuition()
    {
        return creditHours * tuitionRate;
    }
#include "Course.h"
#include <string>

#ifndef CURRICULUMCOURSE_H
#define CURRICULUMCOURSE_H

class CurriculumCourse : public Course
{
    private:
        float creditHours;
        float tuitionRate;
    
    public:
        CurriculumCourse();
        CurriculumCourse(int, std::string, int, float, float, float);
        virtual void setInfo();
        virtual void show();
        float calculateTuition();
};
#endif
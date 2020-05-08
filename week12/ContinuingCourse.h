#include "Course.h"
#include <string>

#ifndef CONTINUINGCOURSE_H
#define CONTINUINGCOURSE_H

class ContinuingCourse : public Course
{
    private:
        float fee;
    
    public:
        ContinuingCourse();
        ContinuingCourse(int, std::string, int, float, float);
        virtual void setInfo();
        virtual void show();
};
#endif
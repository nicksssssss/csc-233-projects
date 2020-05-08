#include <string>

#ifndef COURSE_H
#define COURSE_H

class Course
{
    private:
        int courseId;
        std::string title;
        int roomNumber;
        float contactHours;
    
    public:
        Course();
        Course(int courseId, std::string title, int roomNumber, float contactHours);
        virtual void setInfo();
        virtual void show();
};
#endif
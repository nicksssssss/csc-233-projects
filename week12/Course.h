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
        Course(int, std::string, int, float);
        void show();
};
#endif
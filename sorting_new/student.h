#ifndef SORT_STUDENT_H
#define SORT_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class student
{
public:
    string name;
    int score;

    bool operator<(const student &otherstudent)
    {
        if(this->score < otherstudent.score)
            return true;
        if(this->score == otherstudent.score)
            return this->name < otherstudent.name;
        return false;
    }
    bool operator>(const student &otherstudent)
    {
        if(this->score > otherstudent.score)
            return true;
        if(this->score == otherstudent.score)
            return this->name > otherstudent.name;
        return false;
    }
    friend ostream &operator<<(ostream &os, const student &student)
    {
        os << "student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif
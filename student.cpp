#include "student.h"
#include <QString>



student::student(int ID, QString student_name, QString subject, QString marks)
{

    this->id = ID;
    this->name = student_name;
    this->subject = subject;
    this->marks = marks;

}

student::~student() {}

int student::getID()
{
    return id;
}

const QString &student::getStudentName() const
{
    return name;
}

const QString &student::getStudentSubject() const
{
    return subject;
}

const QString &student::getStudentMarks() const
{
    return marks;
}





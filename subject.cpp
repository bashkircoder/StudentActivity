#include "subject.h"



subject::subject(QString subject_name, QString marks)
{

    this->subject_name = subject_name;
    this->marks = marks;

}

subject::~subject() {}

const QString &subject::getSubjectName() const
{

    return subject_name;

}

const QString &subject::getMarks() const
{

    return marks;

}

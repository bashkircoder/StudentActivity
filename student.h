#ifndef STUDENT_H
#define STUDENT_H
#include <QList>


class student
{

private:

    int id;
    QString name;
    QString subject;
    QString marks;


public:
    student(int ID, QString student_name, QString subject, QString marks);
    ~student();


    int getID();
    const QString &getStudentName() const;
    const QString &getStudentSubject() const;
    const QString &getStudentMarks() const;


};

#endif // STUDENT_H

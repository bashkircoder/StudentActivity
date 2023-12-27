#ifndef SUBJECT_H
#define SUBJECT_H
#include <qstring.h>

class subject
{
private:

    QString subject_name;
    QString marks;

public:
    subject(QString subject_name, QString marks);
    ~subject();

    const QString &getSubjectName() const;
    const QString &getMarks() const;


};

#endif // SUBJECT_H

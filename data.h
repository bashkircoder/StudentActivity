#ifndef DATA_H
#define DATA_H
#include <QtSql/QSql>
#include <QString>
#include <QList>
#include <student.h>

class Data
{
private:

    QString input_path;

public:
    Data(QString input_path);
    ~Data();

    const QList<student> GetALL() const;
    const QList<student> FindByStudentName(QString student_name) const;
    const QList<student> FindBySubject(QString subject) const;


};

#endif // DATA_H

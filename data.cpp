#include "data.h"
#include <data.h>
#include <QtSql/QSql>
#include "QtSql/qsqldatabase.h"
#include "QtSql/QSqlQuery"
#include "QString"
#include "QtSql/QSqlDriverCreatorBase"

Data::Data(QString input_path)
{
    this->input_path = input_path;
}

Data::~Data() {}

const QList<student> Data::GetALL() const
{
    QList<student> students = *new QList<student>();

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(input_path);

    if (!db.open()){

    }

    auto sql = "SELECT id, full_name, subject_matter, assessments FROM students_table";
    QSqlQuery query(sql);
    while (query.next()){

        auto id = query.value(0).toInt();
        auto full_name = query.value(1).toString();
        auto subject = query.value(2).toString();
        auto marks = query.value(3).toString();

        students.push_back(student(id, full_name, subject, marks));
    }

    db.close();

    return students;
}

const QList<student> Data::FindByStudentName(QString student_name) const
{
    QList<student> students = *new QList<student>();

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(input_path);

    if (!db.open()){

    }

    auto sql = "SELECT id, full_name, subject_matter, assessments FROM students_table WHERE full_name = '" + student_name + "'";
    QSqlQuery query(sql);
    while (query.next()){

        auto id = query.value(0).toInt();
        auto student_name = query.value(1).toString();
        auto subject = query.value(2).toString();
        auto marks = query.value(3).toString();

        students.append(student(id, student_name, subject, marks));
    }

    db.close();

    return students;
}

const QList<student> Data::FindBySubject(QString subject) const
{
    QList<student> students = *new QList<student>();

    auto db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(input_path);

    if (!db.open()){

    }

    auto sql = "SELECT id, full_name, subject_matter, assessments FROM students_table WHERE subject_matter = '"  + subject + "'";
    QSqlQuery query(sql);
    while (query.next()){

        auto id = query.value(0).toInt();
        auto student_name = query.value(1).toString();
        auto subject = query.value(2).toString();
        auto marks = query.value(3).toString();

        students.append(student(id, student_name, subject, marks));
    }

    db.close();

    return students;
}



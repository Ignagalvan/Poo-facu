#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB& getInstance();
    QSqlDatabase getDatabase();

private:
    AdminDB(QObject *parent = nullptr);
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;
    ~AdminDB();

    QSqlDatabase db;
};

#endif // ADMINDB_H

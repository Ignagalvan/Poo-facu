#include "admindb.h"

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/ignad/Documents/POO/Ejercicios/Ejercicio 25/db.sqlite");

    if (!db.open())
    {
        QMessageBox::critical(nullptr, "Error", "No se pudo abrir la base de datos");
    }
}

AdminDB& AdminDB::getInstance()
{
    static AdminDB instance;
    return instance;
}

QSqlDatabase AdminDB::getDatabase()
{
    return db;
}

AdminDB::~AdminDB()
{
    if (db.isOpen()) {
        db.close();
    }
}

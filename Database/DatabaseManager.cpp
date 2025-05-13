#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent) {}

bool DatabaseManager::initialize(const QString &databasePath) {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(databasePath);

    if (!m_db.open()) {
        qCritical() << "Error al abrir DB:" << m_db.lastError();
        return false;
    }
    return createTables();
}

bool DatabaseManager::createTables() {
    QSqlQuery query;
    return query.exec(
        "CREATE TABLE IF NOT EXISTS components ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "type TEXT NOT NULL,"
        "quantity INTEGER NOT NULL,"
        "location TEXT NOT NULL,"
        "purchase_date TEXT NOT NULL)"
        );
}

bool DatabaseManager::addComponent(const QString &name, const QString &type,
                                   int quantity, const QString &location,
                                   const QDate &purchaseDate) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO components (name, type, quantity, location, purchase_date) "
        "VALUES (:name, :type, :quantity, :location, :date)"
        );
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    query.bindValue(":quantity", quantity);
    query.bindValue(":location", location);
    query.bindValue(":date", purchaseDate.toString(Qt::ISODate));

    if (!query.exec()) {
        qCritical() << "Error al insertar:" << query.lastError();
        return false;
    }
    return true;
}

bool DatabaseManager::actualizarComponente(int id, const QString& nombre,
                                           const QString& tipo, int cantidad,
                                           const QString& ubicacion,
                                           const QDate& fecha) {
    QSqlQuery query;
    query.prepare(
        "UPDATE components SET "
        "name = :name, "
        "type = :type, "
        "quantity = :quantity, "
        "location = :location, "
        "purchase_date = :date "
        "WHERE id = :id"
        );

    query.bindValue(":id", id);
    query.bindValue(":name", nombre);
    query.bindValue(":type", tipo);
    query.bindValue(":quantity", cantidad);
    query.bindValue(":location", ubicacion);
    query.bindValue(":date", fecha.toString(Qt::ISODate));

    return query.exec();
}

QVector<QStringList> DatabaseManager::getAllComponents() const {
    QVector<QStringList> components;
    QSqlQuery query("SELECT * FROM components ORDER BY name");

    while (query.next()) {
        QStringList component;
        component << query.value("id").toString()
                  << query.value("name").toString()
                  << query.value("type").toString()
                  << query.value("quantity").toString()
                  << query.value("location").toString()
                  << query.value("purchase_date").toString();
        components.append(component);
    }
    return components;
}
bool DatabaseManager::eliminarComponente(const QString &id) {
        QSqlQuery query;
        query.prepare("DELETE FROM components WHERE id = :id");
        query.bindValue(":id", id);
        return query.exec();
}

QSqlError DatabaseManager::lastError() const {
    return m_db.lastError();
}

DatabaseManager::~DatabaseManager() {
    if (m_db.isOpen()) {
        m_db.close();
    }
}

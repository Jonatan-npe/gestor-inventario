#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDate>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool initialize(const QString &databasePath = "inventario.db");
    bool addComponent(const QString &name, const QString &type,
                      int quantity, const QString &location,
                      const QDate &purchaseDate);
    bool actualizarComponente(int id, const QString& nombre, const QString& tipo,
                              int cantidad, const QString& ubicacion,
                              const QDate& fecha);
    bool eliminarComponente(const QString &id);

    QVector<QStringList> getAllComponents() const;


    QSqlError lastError() const;

private:
    QSqlDatabase m_db;
    bool createTables();
};

#endif // DATABASEMANAGER_H

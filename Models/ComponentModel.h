#ifndef COMPONENTMODEL_H
#define COMPONENTMODEL_H

#include <QAbstractTableModel>
#include <QVector>
#include "../Database/DatabaseManager.h"

class ComponentModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ComponentModel(DatabaseManager* dbManager, QObject* parent = nullptr);

    // Métodos requeridos
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QStringList getComponentData(int row) const {
        if (row >= 0 && row < m_components.size())
            return m_components[row];
        return QStringList();
    }
    // Actualizar datos
    void refresh();

private:
    DatabaseManager* m_dbManager;
    QVector<QStringList> m_components;
};

#endif // COMPONENTMODEL_H

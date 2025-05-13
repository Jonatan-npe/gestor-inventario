#include "ComponentModel.h"
#include <QColor>

ComponentModel::ComponentModel(DatabaseManager* dbManager, QObject* parent)
    : QAbstractTableModel(parent), m_dbManager(dbManager)
{
    refresh();
}

int ComponentModel::rowCount(const QModelIndex&) const {
    return m_components.size();
}

int ComponentModel::columnCount(const QModelIndex&) const {
    return 6; // ID, Nombre, Tipo, Cantidad, Ubicación, Fecha
}

QVariant ComponentModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        return m_components[index.row()][index.column()];
    }

    // Resaltar stock bajo
    if (role == Qt::BackgroundRole && index.column() == 3) { // Columna de cantidad
        int cantidad = m_components[index.row()][3].toInt();
        if (cantidad < 5) return QColor(Qt::red);
    }

    return QVariant();
}

QVariant ComponentModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        static QStringList headers = {"ID", "Nombre", "Tipo", "Cantidad", "Ubicación", "Fecha"};
        return headers[section];
    }
    return QVariant();
}

void ComponentModel::refresh()
{
    beginResetModel(); // Notifica a la vista que el modelo va a cambiar
    m_components = m_dbManager->getAllComponents();
    endResetModel(); // Notifica que el cambio terminó

    // Opcional: emitir señal de datos cambiados
    emit dataChanged(createIndex(0, 0),
                     createIndex(rowCount()-1, columnCount()-1));
}

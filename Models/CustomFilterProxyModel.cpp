#include "CustomFilterProxyModel.h"

#include <QModelIndex>

CustomFilterProxyModel::CustomFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{}

bool CustomFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    // Filtro por tipo
    QModelIndex typeIndex = sourceModel()->index(sourceRow, 2, sourceParent); // Columna de tipo
    QString type = sourceModel()->data(typeIndex).toString();

    if (!filterRegExp().pattern().isEmpty()) {
        bool matchesSearch = false;
        for (int col = 0; col < sourceModel()->columnCount(); ++col) {
            QModelIndex idx = sourceModel()->index(sourceRow, col, sourceParent);
            if (idx.data().toString().contains(filterRegExp())) {
                matchesSearch = true;
                break;
            }
        }
        if (!matchesSearch) return false;
    }

    // Filtro por tipo (si está activo)
    if (!m_filterTipo.isEmpty() && type != m_filterTipo) {
        return false;
    }

    return true;
}

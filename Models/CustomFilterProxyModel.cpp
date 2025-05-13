#include "CustomFilterProxyModel.h"
#include <QModelIndex>

CustomFilterProxyModel::CustomFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{}

bool CustomFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const
{
    if (filterRegExp().isEmpty())
        return true;

    QModelIndex index;
    QString searchTerm = filterRegExp().pattern().toLower();

    // Busca en las columnas 1 (nombre), 2 (tipo) y 4 (ubicación)
    for (int col : {1, 2, 4}) {
        index = sourceModel()->index(sourceRow, col, sourceParent);
        if (index.data().toString().toLower().contains(searchTerm)) {
            return true;
        }
    }

    return false;
}

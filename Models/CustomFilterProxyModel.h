#ifndef CUSTOMFILTERPROXYMODEL_H
#define CUSTOMFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>
#include <QString>

class CustomFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit CustomFilterProxyModel(QObject *parent = nullptr);

    // Método para establecer el filtro por tipo
    void setFilterTipo(const QString &tipo);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_filterTipo;
};

#endif // CUSTOMFILTERPROXYMODEL_H

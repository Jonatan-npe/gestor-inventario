#include <QSortFilterProxyModel>

class CustomFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit CustomFilterProxyModel(QObject *parent = nullptr);

protected:
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;
};

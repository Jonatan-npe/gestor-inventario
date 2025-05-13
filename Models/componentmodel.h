#ifndef COMPONENTMODEL_H
#define COMPONENTMODEL_H

#include <QObject>

class ComponentModel : public QObject
{
    Q_OBJECT
public:
    explicit ComponentModel(QObject *parent = nullptr);

signals:
};

#endif // COMPONENTMODEL_H

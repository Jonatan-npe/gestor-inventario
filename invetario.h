#ifndef INVETARIO_H
#define INVETARIO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Inventario; }
QT_END_NAMESPACE

class Inventario : public QMainWindow
{
    Q_OBJECT

public:
    Inventario(QWidget *parent = nullptr);
    ~Inventario();

private:
    Ui::Inventario *ui;
};
#endif // INVENTARIO_H
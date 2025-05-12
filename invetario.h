#ifndef INVETARIO_H
#define INVETARIO_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Invetario;
}
QT_END_NAMESPACE

class Invetario : public QMainWindow
{
    Q_OBJECT

public:
    Invetario(QWidget *parent = nullptr);
    ~Invetario();

private:
    Ui::Invetario *ui;
};
#endif // INVETARIO_H

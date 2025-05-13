#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Database/DatabaseManager.h"

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

private slots:
    void on_buscarTextoCambiado(const QString &texto);
    void on_anadirClicked();
    void on_editarClicked();
    void on_eliminarClicked();
    void on_reporteClicked();

private:
    Ui::Inventario *ui;
    DatabaseManager *m_dbManager;
};
#endif // INVENTARIO_H

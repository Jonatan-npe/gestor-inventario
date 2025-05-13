#ifndef COMPONENTDIALOG_H
#define COMPONENTDIALOG_H

#include <QDialog>
#include <QDate>

namespace Ui {
class ComponentDialog;
}

class ComponentDialog : public QDialog
{
    Q_OBJECT

public:
    // Constructor único para añadir/editar
    explicit ComponentDialog(QWidget *parent = nullptr,
                             const QString& nombre = "",
                             const QString& tipo = "",
                             int cantidad = 1,
                             const QString& ubicacion = "",
                             const QDate& fecha = QDate::currentDate());
    ~ComponentDialog();

    // Getters para los datos del formulario
    QString nombre() const;
    QString tipo() const;
    int cantidad() const;
    QString ubicacion() const;
    QDate fechaAdquisicion() const;

private:
    Ui::ComponentDialog *ui;
};

#endif // COMPONENTDIALOG_H

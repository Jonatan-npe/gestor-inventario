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
    explicit ComponentDialog(QWidget *parent = nullptr);
    ~ComponentDialog();

    // Getters para los datos del formulario
    QString nombre() const;
    QString tipo() const;
    int cantidad() const;
    QString ubicacion() const;
    QDate fechaAdquisicion() const;

    // Setters para edición
    void setDatos(const QString& nombre, const QString& tipo,
                  int cantidad, const QString& ubicacion,
                  const QDate& fecha);

private:
    Ui::ComponentDialog *ui;
};

#endif // COMPONENTDIALOG_H

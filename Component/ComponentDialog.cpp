#include "ComponentDialog.h"
#include "ui_ComponentDialog.h"
#include <QDebug>

ComponentDialog::ComponentDialog(QWidget *parent,
                                 const QString& nombre,
                                 const QString& tipo,
                                 int cantidad,
                                 const QString& ubicacion,
                                 const QDate& fecha)
    : QDialog(parent), ui(new Ui::ComponentDialog)
{
    ui->setupUi(this);

    // Configuración inicial del UI
    ui->comboTipo->addItems({"Electrónico", "Mecánico", "Herramienta", "Consumible"});
    ui->spinCantidad->setMinimum(1);
    ui->spinCantidad->setMaximum(9999);
    ui->dateEdit->setCalendarPopup(true);

    // Establecer valores (para edición o valores por defecto)
    ui->lineEditNombre->setText(nombre);
    ui->comboTipo->setCurrentText(tipo);
    ui->spinCantidad->setValue(cantidad);
    ui->lineEditUbicacion->setText(ubicacion);
    ui->dateEdit->setDate(fecha);

    // Título dinámico según el modo
    setWindowTitle(nombre.isEmpty() ? "Añadir Componente" : "Editar Componente");
}

ComponentDialog::~ComponentDialog()
{
    delete ui;
}

// Implementación de los getters
QString ComponentDialog::nombre() const {
    return ui->lineEditNombre->text().trimmed();
}

QString ComponentDialog::tipo() const {
    return ui->comboTipo->currentText();
}

int ComponentDialog::cantidad() const {
    return ui->spinCantidad->value();
}

QString ComponentDialog::ubicacion() const {
    return ui->lineEditUbicacion->text().trimmed();
}

QDate ComponentDialog::fechaAdquisicion() const {
    return ui->dateEdit->date();
}

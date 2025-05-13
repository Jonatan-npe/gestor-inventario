#include "ComponentDialog.h"
#include "ui_ComponentDialog.h"

ComponentDialog::ComponentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComponentDialog)
{
    ui->setupUi(this);

    // Configuración inicial
    ui->dateEdit->setDate(QDate::currentDate());
    setWindowTitle("Añadir Componente");

    // Puedes añadir tipos predefinidos
    ui->comboTipo->addItems({"Electrónico", "Mecánico", "Herramienta", "Consumible"});
}

ComponentDialog::~ComponentDialog()
{
    delete ui;
}

// Implementación de los getters
QString ComponentDialog::nombre() const {
    return ui->lineEditNombre->text();
}

QString ComponentDialog::tipo() const {
    return ui->comboTipo->currentText();
}

int ComponentDialog::cantidad() const {
    return ui->spinCantidad->value();
}

QString ComponentDialog::ubicacion() const {
    return ui->lineEditUbicacion->text();
}

QDate ComponentDialog::fechaAdquisicion() const {
    return ui->dateEdit->date();
}

// Setter para modo edición
void ComponentDialog::setDatos(const QString& nombre, const QString& tipo,
                               int cantidad, const QString& ubicacion,
                               const QDate& fecha) {
    ui->lineEditNombre->setText(nombre);
    ui->comboTipo->setCurrentText(tipo);
    ui->spinCantidad->setValue(cantidad);
    ui->lineEditUbicacion->setText(ubicacion);
    ui->dateEdit->setDate(fecha);
    setWindowTitle("Editar Componente");
}

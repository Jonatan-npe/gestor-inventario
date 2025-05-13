#include "inventario.h"
#include "ui_inventario.h"
#include <QMessageBox>
#include <QDebug>

Inventario::Inventario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inventario)
{
    ui->setupUi(this);

    // Conectar señales y slots
    connect(ui->lineEditBuscar, &QLineEdit::textChanged,
            this, &Inventario::on_buscarTextoCambiado);

    connect(ui->btnAnadir, &QPushButton::clicked,
            this, &Inventario::on_anadirClicked);

    connect(ui->btnEditar, &QPushButton::clicked,
            this, &Inventario::on_editarClicked);

    connect(ui->btnEliminar, &QPushButton::clicked,
            this, &Inventario::on_eliminarClicked);

    connect(ui->btnReporte, &QPushButton::clicked,
            this, &Inventario::on_reporteClicked);
}

Inventario::~Inventario()
{
    delete ui;
}

// Implementación de los slots
void Inventario::on_buscarTextoCambiado(const QString &texto)
{
    qDebug() << "Texto de búsqueda cambiado:" << texto;
    // Aquí implementarás la lógica de filtrado más adelante
}

void Inventario::on_anadirClicked()
{
    QMessageBox::information(this, "Añadir", "Función Añadir seleccionada");
    // Aquí abrirás el diálogo para añadir nuevos items
}

void Inventario::on_editarClicked()
{
    QMessageBox::information(this, "Editar", "Función Editar seleccionada");
    // Aquí implementarás la edición de items existentes
}

void Inventario::on_eliminarClicked()
{
    QMessageBox::information(this, "Eliminar", "Función Eliminar seleccionada");
    // Aquí implementarás la eliminación de items
}

void Inventario::on_reporteClicked()
{
    QMessageBox::information(this, "Reporte", "Función Reporte seleccionada");
    // Aquí generarás los reportes PDF/CSV
}

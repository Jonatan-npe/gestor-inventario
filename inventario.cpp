#include "inventario.h"
#include "ui_inventario.h"
#include "./Component/ComponentDialog.h"
#include "./Models/CustomFilterProxyModel.h"
#include <QMessageBox>
#include <QDebug>

Inventario::Inventario(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Inventario),
    m_dbManager(new DatabaseManager(this)),
    m_componentModel(new ComponentModel(m_dbManager, this)),
    m_proxyModel(new CustomFilterProxyModel(this))
{
    ui->setupUi(this);

    // 1. Configuración inicial de la base de datos
    if (!m_dbManager->initialize()) {
        QMessageBox::critical(this, "Error", "No se pudo iniciar la base de datos");
        qApp->exit(1);
        return;
    }

    // 2. Configuración del modelo y proxy
    m_proxyModel->setSourceModel(m_componentModel);
    m_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    m_proxyModel->setFilterKeyColumn(-1); // Buscar en todas las columnas
    ui->tableView->setModel(m_proxyModel);

    // 3. Cargar datos iniciales
    m_componentModel->refresh(); // ¡Esta es la línea clave que faltaba!

    // 4. Configuración de la tabla
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);

    // 5.conexiones:
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

    connect(ui->tableView, &QTableView::doubleClicked,
            this, &Inventario::on_editarClicked);
}

Inventario::~Inventario()
{
    delete ui;
}
void Inventario::configurarBusqueda()
{
    // Configura el proxy model para buscar en todas las columnas
    m_proxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    m_proxyModel->setFilterKeyColumn(-1); // -1 busca en todas las columnas

    // Conectar señal de búsqueda
    connect(ui->lineEditBuscar, &QLineEdit::textChanged,
            this, &Inventario::on_buscarTextoCambiado);
}
// Implementación de los slots
void Inventario::on_buscarTextoCambiado(const QString &texto)
{
    if (!m_proxyModel || !m_componentModel) return;

    QRegExp regex(texto, Qt::CaseInsensitive, QRegExp::FixedString);
    m_proxyModel->setFilterRegExp(regex);

    // Actualizar vista si es necesario
    ui->tableView->viewport()->update();
}
void Inventario::on_anadirClicked() {
    ComponentDialog dialog(this); // Usará los valores por defecto
    if (dialog.exec() == QDialog::Accepted) {
        if (m_dbManager->addComponent(
                dialog.nombre(),
                dialog.tipo(),
                dialog.cantidad(),
                dialog.ubicacion(),
                dialog.fechaAdquisicion()))
        {
            m_componentModel->refresh(); // Actualización manual
            QMessageBox::information(this, "Éxito", "Componente añadido correctamente");
        } else {
            QMessageBox::warning(this, "Error", "No se pudo añadir el componente");
        }
    }
}

void Inventario::on_editarClicked()
{
    // Obtener el índice del proxy model
    QModelIndex proxyIndex = ui->tableView->currentIndex();

    if (!proxyIndex.isValid()) {
        QMessageBox::warning(this, "Error", "Selecciona un componente para editar");
        return;
    }

    // Mapear al modelo fuente
    QModelIndex sourceIndex = m_proxyModel->mapToSource(proxyIndex);

    // Obtener datos del componente seleccionado
    int id = m_componentModel->data(m_componentModel->index(sourceIndex.row(), 0)).toInt();
    QString nombre = m_componentModel->data(m_componentModel->index(sourceIndex.row(), 1)).toString();
    QString tipo = m_componentModel->data(m_componentModel->index(sourceIndex.row(), 2)).toString();
    int cantidad = m_componentModel->data(m_componentModel->index(sourceIndex.row(), 3)).toInt();
    QString ubicacion = m_componentModel->data(m_componentModel->index(sourceIndex.row(), 4)).toString();
    QDate fecha = QDate::fromString(
        m_componentModel->data(m_componentModel->index(sourceIndex.row(), 5)).toString(),
        Qt::ISODate
        );

    // Mostrar diálogo de edición
    ComponentDialog dialog(this, nombre, tipo, cantidad, ubicacion, fecha);

    if (dialog.exec() == QDialog::Accepted) {
        if (m_dbManager->actualizarComponente(
                id,
                dialog.nombre(),
                dialog.tipo(),
                dialog.cantidad(),
                dialog.ubicacion(),
                dialog.fechaAdquisicion()))
        {
            m_componentModel->refresh();
            QMessageBox::information(this, "Éxito", "Componente actualizado correctamente");
        } else {
            QMessageBox::warning(this, "Error", "No se pudo actualizar el componente");
        }
    }
}

void Inventario::on_eliminarClicked() {
    QModelIndex index = ui->tableView->currentIndex();
    if (index.isValid()) {
        QString id = m_componentModel->data(m_componentModel->index(index.row(), 0)).toString();
        if (m_dbManager->eliminarComponente(id)) {
            m_componentModel->refresh(); // Actualización manual después de eliminar
            QMessageBox::information(this, "Éxito", "Componente eliminado correctamente");
        } else {
            QMessageBox::warning(this, "Error", "No se pudo eliminar el componente");
        }
    }
}
void Inventario::on_reporteClicked()
{
    QMessageBox::information(this, "Reporte", "Función Reporte seleccionada");
    // Aquí generarás los reportes PDF/CSV
}

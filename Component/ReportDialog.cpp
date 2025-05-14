#include "ReportDialog.h"
#include "ui_ReportDialog.h"

ReportDialog::ReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportDialog)
{
    ui->setupUi(this);
    setWindowTitle("Generar Reporte");
}

ReportDialog::~ReportDialog()
{
    delete ui;
}

bool ReportDialog::generarPDF() const
{
    return ui->radioPDF->isChecked();
}

bool ReportDialog::generarCSV() const
{
    return ui->radioCSV->isChecked();
}

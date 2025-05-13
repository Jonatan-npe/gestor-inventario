#include "invetario.h"
#include "./ui_invetario.h"

Inventario::Inventario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Inventario)
{
    ui->setupUi(this);
}

Inventario::~Inventario()
{
    delete ui;
}
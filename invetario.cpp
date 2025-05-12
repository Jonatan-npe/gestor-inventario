#include "invetario.h"
#include "./ui_invetario.h"

Invetario::Invetario(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Invetario)
{
    ui->setupUi(this);
}

Invetario::~Invetario()
{
    delete ui;
}

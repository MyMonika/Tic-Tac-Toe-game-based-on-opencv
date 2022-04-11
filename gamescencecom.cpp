#include "gamescencecom.h"
#include "ui_gamescencecom.h"

gameScenceCom::gameScenceCom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameScenceCom)
{
    ui->setupUi(this);
}

gameScenceCom::~gameScenceCom()
{
    delete ui;
}

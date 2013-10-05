#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "getpath.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_path = new GetPath(ui);
}

MainWindow::~MainWindow()
{
    delete m_path;
    delete ui;
}

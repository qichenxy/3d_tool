#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{

    glwidget_ = new GLWidget(this);
    ui_->setupUi(this);
    this->setCentralWidget(glwidget_);
}

MainWindow::~MainWindow()
{
    delete ui_;
    delete glwidget_;
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    count = 0;

    ui->setupUi(this);
    layout = new QVBoxLayout();
    button = new QPushButton("Tap Here", this);
    label = new QLabel("Count is: " + QString::number(count));

    button->setStyleSheet("background-color: orange; color: black");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("color: red;");

    layout->addWidget(button);
    layout->addWidget(label);

    QWidget *centralWidget = new QWidget();
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    this->setWindowTitle("Click counter");
    this->setFixedSize(230,100);
    connect(button, &QPushButton::clicked, this, &MainWindow::increment);
}
void MainWindow::increment()
{
    ++count;
    label->setText("Count is: " + QString::number(count));

}
MainWindow::~MainWindow()
{
    delete ui;
    delete button;
    delete layout;
    delete label;
}

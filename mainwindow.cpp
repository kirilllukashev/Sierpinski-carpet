#include "mainwindow.h"
#include "ui_mainwindow.h"

int i = 0;
int val = std::pow(3, 7);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Serp(double x, double y, double width, double height)
{
    if (val > width) {
        return;
    }
    scene->addRect(x, y, width, height, QPen(Qt::black), QBrush(Qt::black));
    scene->addRect(width / 3 + x, height / 3 + y, width / 3, height / 3, QPen(Qt::black), QBrush(Qt::white));

    Serp(x, y, width / 3, height / 3);
    Serp(width / 3 + x, y, width / 3, height / 3);
    Serp(2 * width / 3 + x, y, width / 3, height / 3);
    Serp(x, height / 3 + y, width / 3, height / 3);
    Serp(x, 2 * height / 3 + y , width / 3, height / 3);
    Serp(width / 3 + x, 2 * height / 3 + y, width / 3, height / 3);
    Serp(2 * width / 3 + x, 2 * height / 3 + y, width / 3, height / 3);
    Serp(2 * width / 3 + x, height / 3 + y, width / 3, height / 3);
}


void MainWindow::on_pushButton_clicked()
{
    if (val < 27) {
        return;
    }
    val /= 3;
    qDebug() << val << '\n';
    Serp(0, 0, this->width(), this->height());
}

void MainWindow::on_pushButton_2_clicked()
{
    if (val > std::pow(3, 8)) {
        return;
    }
    val *= 3;
    qDebug() << val << '\n';
    Serp(0, 0, this->width(), this->height());
}

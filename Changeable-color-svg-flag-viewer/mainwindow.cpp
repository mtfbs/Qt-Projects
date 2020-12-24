#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QResizeEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // set central widget
    this->setCentralWidget(ui->horizontalLayoutWidget);

    // define the left and right graphics view default background color
        // left
    ui->graphicsView_left->setBackgroundBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));
        // right
    ui->graphicsView_right->setBackgroundBrush(QBrush(Qt::darkGreen, Qt::SolidPattern));

    // shows default flags //
        // left
            // creates the scene and sets it to the be the graphics view scene
    QGraphicsScene *scene1;
    scene1 = new QGraphicsScene(this);
    ui->graphicsView_left->setScene(scene1);
            // loads svg and adds it to the scene
    QGraphicsSvgItem *item1 = new QGraphicsSvgItem(":/resources/images/flagA.svg");
    scene1->addItem(item1);
    ui->graphicsView_left->fitInView(item1->boundingRect(), Qt::KeepAspectRatio);

        // right
    QGraphicsScene *scene2;
    scene2 = new QGraphicsScene(this);
    ui->graphicsView_right->setScene(scene2);
            // loads svg and adds it to the scene
    QGraphicsSvgItem *item2 = new QGraphicsSvgItem(":/resources/images/flagB.svg");
    scene2->addItem(item2);
//    item2->setScale(5);
    ui->graphicsView_right->fitInView(item2->boundingRect(), Qt::KeepAspectRatio);


}

MainWindow::~MainWindow()
{
    delete ui;
}



// CLICK EVENT HANDELING//

    // color buttons //
        // left
void MainWindow::on_pushButton_change_color_left_clicked()
{
    // opens the color piker
    QColor color = QColorDialog::getColor(Qt::white, this);
    ui->graphicsView_left->setBackgroundBrush(QBrush(color, Qt::SolidPattern));
}
        // right
void MainWindow::on_pushButton_change_color_right_clicked()
{
     // opens the color piker
    QColor color = QColorDialog::getColor(Qt::white, this);
    ui->graphicsView_right->setBackgroundBrush(QBrush(color, Qt::SolidPattern));
}

    // open file buttons //
        // left
void MainWindow::on_pushButton_open_file_left_clicked()
{
    // gets file name
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.svg)"));

    // if filename is not empty
    if(QString::compare(filename, QString()) != 0){

        // creates the scene and sets it to the be the graphics view scene
        QGraphicsScene *scene;
        scene = new QGraphicsScene(this);
        ui->graphicsView_left->setScene(scene);

        // loads svg and adds it to the scene
        QGraphicsSvgItem *item = new QGraphicsSvgItem(filename);
        item->setScale(1);
        scene->addItem(item);
    }

}
        // right
void MainWindow::on_pushButton_open_file_right_clicked()
{
    // gets file name
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images(*.svg)"));

    // if filename is not empty
    if(QString::compare(filename, QString()) != 0){

        // creates the scene and sets it to the be the graphics view scene
        QGraphicsScene *scene;
        scene = new QGraphicsScene(this);
        ui->graphicsView_right->setScene(scene);

        // loads svg and adds it to the scene
        QGraphicsSvgItem *item = new QGraphicsSvgItem(filename);
        item->setScale(1);
        scene->addItem(item);
    }
}

// RESIZE EVENT HANDLING //
void MainWindow::resizeEvent(QResizeEvent *e)
{

    foreach(auto &x, ui->graphicsView_left->items()){
        ui->graphicsView_left->fitInView(x->boundingRect(), Qt::KeepAspectRatio);
    }

    foreach(auto &x, ui->graphicsView_right->items()){
        ui->graphicsView_right->fitInView(x->boundingRect(), Qt::KeepAspectRatio);
    }



}

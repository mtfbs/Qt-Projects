#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include <QtSvg/QSvgRenderer>
#include <QGraphicsSvgItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_change_color_left_clicked();

    void on_pushButton_change_color_right_clicked();

    void on_pushButton_open_file_left_clicked();

    void on_pushButton_open_file_right_clicked();

//protected:
    void resizeEvent(QResizeEvent *e);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

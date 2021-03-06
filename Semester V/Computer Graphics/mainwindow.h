#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void Mouse_Pressed();
    void showMousePosition(QPoint& pos);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_show_axes_clicked();

    void on_setgridbutton_clicked();

    void on_resetButton_clicked();

    void on_setpoint1_clicked();

    void on_setpoint2_clicked();

    void on_DDAline_clicked();

    void drawDDALine (int r, int g, int b);

    void on_bresenhamLine_clicked();

//    void on_pushButton_clicked();

//    void on_pushButton_2_clicked();

//    void on_pushButton_3_clicked();

    void on_Midpoint_clicked();

    void on_Bresenhamcircle_clicked();

    void on_polar_clicked();

    void on_centre_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int x,int y,int r, int g, int b);
};

#endif // MAINWINDOW_H

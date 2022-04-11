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

    void on_pushButton_clicked();

    void on_polar_btn_clicked();

    void on_pushButton_2_clicked();

    void on_ellipseCentre_clicked();

    void on_ellipseMidPoint_clicked();

    void on_ellipsePolarMethod_clicked();

    void on_fillScanline_clicked();

    void on_setFillPoint_clicked();

    void on_floodFillBtn_clicked();

    void on_boundaryFill_clicked();

    void on_setBoundary_clicked();

    void on_drawClippingFrame_clicked();

    void on_clipScreen_clicked();

    void on_markCentre_clicked();

private:
    Ui::MainWindow *ui;
    QPoint p1,p2;
    void point(int x,int y,int r, int g, int b);
    void sleeper(int time);
    void flood(int x, int y, int lm, int rm, int incrementFactor);
    void boundaryFill(int x, int y, int lm, int rm, int incrementFactor);
    void delay(int n);
};

#endif // MAINWINDOW_H

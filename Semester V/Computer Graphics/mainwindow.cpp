#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>

#include <cmath>
#include<bits/stdc++.h>


using namespace std;
using namespace std::chrono;

int gridsize=1;

QImage img=QImage(451,451,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->x_axis->hide();
    ui->y_axis->hide();
    ui->time_Bresenhum->setText(" ");
    ui->time_dda->setText(" ");
    connect(ui->frame,SIGNAL(Mouse_Pos()),this,SLOT(Mouse_Pressed()));
    connect(ui->frame,SIGNAL(sendMousePosition(QPoint&)),this,SLOT(showMousePosition(QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::point(int x,int y, int r=230, int g=115, int b=0)
{
    if(gridsize == 1) img.setPixel(x,y,qRgb(r,g,b));
    else {
        x = (x/gridsize)*gridsize;
        y = (y/gridsize)*gridsize;
        for(int i=x+1;i <  x + gridsize;i++) {
            for(int j=y+1;j < y + gridsize;j++) {
                img.setPixel(i,j,qRgb(r,g,b));
            }
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));

}

void MainWindow::showMousePosition(QPoint &pos)
{
    int x = (pos.x() - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - pos.y())/gridsize;
    ui->mouse_movement->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
}
void MainWindow::Mouse_Pressed()
{
    int x = (ui->frame->x - ui->frame->width()/2)/gridsize;
    int y = (ui->frame->height()/2 - ui->frame->y)/gridsize;
    ui->mouse_pressed->setText(" X : "+QString::number(x)+", Y : "+QString::number(y));
    point(ui->frame->x,ui->frame->y);
}

//method to display the axes
void MainWindow::on_show_axes_clicked()
{
    if(ui->show_axes->isChecked())
    {
        for(int j=0;j<=ui->frame->width();j+=gridsize)
        {
            point(img.width()/2,j,0,153,153);
        }
        for(int i=0;i<=ui->frame->height();i+=gridsize)
        {
            point(i,img.height()/2,0,153,153);
        }
    }
    else{
        on_resetButton_clicked();
    }
}

//method to clear the screen
void MainWindow::on_resetButton_clicked()
{
    for(int j=0;j<img.height();j++)
    {
        for(int i=0;i<img.width();i++)
        {
            img.setPixel(i,j,qRgb(0,0,0));
        }
    }
    ui->frame->setPixmap(QPixmap::fromImage(img));
    ui->time_Bresenhum->setText(" ");
    ui->time_dda->setText(" ");
}

//method to set the grid
void MainWindow::on_setgridbutton_clicked()
{
    gridsize=ui->gridspinbox->value();
    if(gridsize>1)
    {
        for(int i=0;i<img.width();i+=gridsize)
        {
            for(int j=0;j<img.height();j++)
            {
                img.setPixel(i,j,qRgb(153,153,0));
                img.setPixel(j,i,qRgb(153,153,0));
            }
        }
        ui->frame->setPixmap(QPixmap::fromImage(img));
    }
}

//method to set the first point of the straight line
void MainWindow::on_setpoint1_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
}

//method to set the second point of the straight line
void MainWindow::on_setpoint2_clicked()
{
    p2.setX(ui->frame->x);
    p2.setY(ui->frame->y);
}




void MainWindow::on_DDAline_clicked()
{
    drawDDALine(51,204,0);
}

//implementation of the DDA Algorithm
void MainWindow::drawDDALine (int r, int g, int b){
       double x0 = p1.x() / gridsize;
       double xn = p2.x() / gridsize;
       double y0 = p1.y() / gridsize;
       double yn = p2.y() / gridsize;

       //required for evaluating the step count in the algorithm
       double dx = fabs(xn - x0);
       double dy = fabs(yn - y0);

       double Dx, Dy;

       if (dx > dy ) { //y coordinate will increase backward or forward by the slope value
           Dx = 1;
           Dy = dy / dx;
       }

       else { // x coordinate will increase backward or forward by the inverse slope value
           Dx = dx / dy;
           Dy = 1;
       }
       //change the direction of movement accordingly
       if (x0 > xn) Dx *= -1;
       if (y0 > yn) Dy *= -1;

       double x = x0*gridsize + gridsize / 2;
       double y = y0*gridsize + gridsize / 2;

       auto start = high_resolution_clock::now(); //start the timer

       for (int k =0; k <= (dx > dy ? dx : dy); k++) {
           point (x, y, r, g, b);
           x += Dx * gridsize;
           y += Dy * gridsize;
       }
       auto end = high_resolution_clock::now();

       auto duration = duration_cast<microseconds>(end - start);
       long executionTime = duration.count();
       ui->time_dda->setText(QString::number(executionTime,'f',3));
}

void MainWindow::on_bresenhamLine_clicked()
{

    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    int xn = p2.x()/gridsize;
    int yn = p2.y()/gridsize;

    //required for evaluating the step count of the algorithm
    int dx = fabs(xn - x0);
    int dy = fabs(yn - y0);

    int Dx = (x0 > xn ? -1 : 1);
    int Dy = (y0 > yn ? -1 : 1);
    bool flag = 1;
    int x = x0*gridsize + gridsize/2;
    int y = y0*gridsize + gridsize/2;
    if(dy > dx) { // if slope > 1, then swap the elements
        swap(dx,dy);
        swap(x,y);
        swap(Dx,Dy);
        flag = 0;
    }
    int decision = 2*dy - dx;
    auto start = high_resolution_clock::now();
    for(int i=0;i<=dx;i++) {
        if(flag) {
            point(x,y,255,255,0);
        }

        else point(y,x,255,255,0);

        if(decision < 0) {
            x += Dx*gridsize;
            decision += 2*dy;
        } else {
            x += Dx*gridsize;
            y += Dy*gridsize;
            decision += 2*dy - 2*dx;
        }
    }
    auto end = high_resolution_clock::now();
    long timeOfExecution = duration_cast<microseconds>(end - start).count();
    ui->time_Bresenhum->setText(QString::number(timeOfExecution,'f',3));
}

void MainWindow::on_Midpoint_clicked()
{
    int radius = ui->radius->value();
    int x0 = p1.x() / gridsize;
    int y0 = p1.y() / gridsize;

    x0 = x0 * gridsize + gridsize / 2;
    y0 = y0 * gridsize + gridsize / 2;

    int x = radius * gridsize;
    int y = 0;

    int p = (1 - radius) * gridsize;

    auto start = high_resolution_clock::now();
    while(x >= y) {
            point(x0 - x, y0 - y, 219, 3, 252);
            point(x0 + x, y0 - y, 219, 3, 252);
            point(x0 - x, y0 + y, 219, 3, 252);
            point(x0 + x, y0 + y, 219, 3, 252);
            point(x0 - y, y0 - x, 219, 3, 252);
            point(x0 + y, y0 - x, 219, 3, 252);
            point(x0 - y, y0 + x, 219, 3, 252);
            point(x0 + y, y0 + x, 219, 3, 252);

            y += gridsize;
            if(p <= 0) {
                p += 2*y + 1;
            } else {
                p += 2*y + 1 - 2*x;
                x -= gridsize;
            }
    }
    auto end = high_resolution_clock::now();
    long executionTime = duration_cast<microseconds>(end - start).count();
    ui->timemidpoint->setText(QString::number(executionTime,'f',3));
}

void MainWindow::on_Bresenhamcircle_clicked()
{
    int radius = ui->radius->value();
    int x0 = p1.x()/gridsize;
    int y0 = p1.y()/gridsize;
    x0 = x0*gridsize + gridsize/2;
    y0 = y0*gridsize + gridsize/2;

    int x = 0;
    int y = radius *gridsize;
    int p = (3 - 2*radius)*gridsize;
    auto start = high_resolution_clock::now();
    while(y >= x) {
        point(x0 - x, y0 - y, 255, 255, 0);
        point(x0 + x, y0 - y, 255, 255, 0);
        point(x0 - x, y0 + y, 255, 255, 0);
        point(x0 + x, y0 + y, 255, 255, 0);
        point(x0 - y, y0 - x, 255, 255, 0);
        point(x0 + y, y0 - x, 255, 255, 0);
        point(x0 - y, y0 + x, 255, 255, 0);
        point(x0 + y, y0 + x, 255, 255, 0);
        x += gridsize;
        if(p <= 0) {
            p += 4*x + 6;

        } else {
            p += 4*(x-y) + 10;
            y -= gridsize;
//            x += gridsize;
        }
    }
    auto end = high_resolution_clock::now();
    int executionTime = duration_cast<microseconds>(end - start).count();
    ui->timebresenham->setText(QString::number(executionTime,'f',3));

}

void MainWindow::on_polar_clicked()
{
    int radius = ui->radius->value();
    int x_center = p1.x();
    int y_center = p1.y();
    auto start = high_resolution_clock::now();
    for (int theta_degrees = 0; theta_degrees <= 360; theta_degrees++) {
        double theta_radians = M_PI * theta_degrees / 180;
        int xk = x_center + radius * cos (theta_radians) * gridsize;
        int yk = y_center + radius * sin (theta_radians) * gridsize;
        point (xk, yk, 255, 0, 0);
    }
    auto end = high_resolution_clock::now();
    int executionTime = duration_cast<microseconds>(end - start).count();
    ui->timepolar->setText(QString::number(executionTime,'f',3));
}

void MainWindow::on_centre_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
}

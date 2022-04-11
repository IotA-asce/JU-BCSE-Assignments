#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QImage>
#include <iostream>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintDevice>
#include <QPoint>
#include <QMessageBox>

#include <cmath>
#include <iostream>

#include <chrono>
#include <thread>
//#include <boost/thread/thread.hpp>

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


void MainWindow::point(int x,int y, int r=200, int g=20, int b=0)
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
//    sleeper(200000);
    ui->frame->setPixmap(QPixmap::fromImage(img));
//    sleeper(200000);

}

void MainWindow::sleeper(int time){

    auto start = high_resolution_clock::now();
    auto end = high_resolution_clock::now();

    cout << "Sleeper starts" << endl;

    while(duration_cast<microseconds>(end - start).count() < time){
        end = high_resolution_clock::now();
    }

    cout << "Sleeper ends" << endl;
}

void MainWindow::delay(int n) {
//    QTime dieTime= QTime::currentTime().addSecs(n);
    QTime dieTime= QTime::currentTime().addMSecs(n);
    while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
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
            point(img.width()/2,j,120, 213, 240);
        }
        for(int i=0;i<=ui->frame->height();i+=gridsize)
        {
            point(i,img.height()/2,120, 213, 240);
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
        for (int x = 0; x < img.width(); x++) {
            for(int y = 0; y < img.height(); y++){
                img.setPixel(x,y,qRgb(0,0,0));
            }
        }

        ui->frame->setPixmap(QPixmap::fromImage(img));

        for(int i=0;i<img.width();i+=gridsize)
        {
            for(int j=0;j<img.height();j++)
            {
                img.setPixel(i,j,qRgb(100,100,100));
                img.setPixel(j,i,qRgb(100,100,100));
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
    drawDDALine(145,70,200);
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

       auto tstart = high_resolution_clock::now();
       auto tend = high_resolution_clock::now();

       for (int k =0; k <= (dx > dy ? dx : dy); k++) {
           tstart = high_resolution_clock::now(); // time taken by system call
           point (x, y, r, g, b);
           tend = high_resolution_clock::now();
           x += Dx * gridsize;
           y += Dy * gridsize;
       }
       auto end = high_resolution_clock::now();

       auto duration = duration_cast<microseconds>(end - start - (tend - tstart));
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

    auto tstart = high_resolution_clock::now();
    auto tend = high_resolution_clock::now();

    for(int i=0;i<=dx;i++) {
        tstart = high_resolution_clock::now();
        if(flag) {
            point(x,y,255,165,20);
        }

        else point(y,x,255,165,20);
        tend = high_resolution_clock::now();

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
//    std::cout << "with system call " << (end - start) << std::endl;
//    std::cout << "system call " << (tend - tstart) << std::endl;
    long timeOfExecution = duration_cast<microseconds>(end - start - (tend - tstart)).count();
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
        point(x0 - x, y0 - y, 255,165,20);
        point(x0 + x, y0 - y, 255,165,20);
        point(x0 - x, y0 + y, 255,165,20);
        point(x0 + x, y0 + y, 255,165,20);
        point(x0 - y, y0 - x, 255,165,20);
        point(x0 + y, y0 - x, 255,165,20);
        point(x0 - y, y0 + x, 255,165,20);
        point(x0 + y, y0 + x, 255,165,20);
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

void MainWindow::on_pushButton_clicked()
{
// // // // // // // // // / / / / / / / / / / / / / / / / / / /. / / / / / / /  / /
}


void MainWindow::on_polar_btn_clicked()
{
    int radius = ui->radius->value();
    int x_center = p1.x();
    int y_center = p1.y();
    auto start = high_resolution_clock::now();
    for (int theta_degrees = 0; theta_degrees <= 360; theta_degrees++) {
        double theta_radians = M_PI * theta_degrees / 180;
        int xk = x_center + radius * cos (theta_radians) * gridsize;
        int yk = y_center + radius * sin (theta_radians) * gridsize;
        point (xk, yk, 0, 200, 50);
    }
    auto end = high_resolution_clock::now();
    int executionTime = duration_cast<microseconds>(end - start).count();
//    ui->timepolar->setText(QString::number(executionTime,'f',3));
    ui->time_circle_polar->setText(QString::number(executionTime,'f',3));
}


void MainWindow::on_pushButton_2_clicked()
{
//    QMessageBox::critical(this, "Title", "this section is not ready yet");
    delay(10000);
}


void MainWindow::on_ellipseCentre_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);
}


void MainWindow::on_ellipseMidPoint_clicked()
{
    int rx = ui->ellipseMajorAxis->value() * gridsize;
    int ry = ui->ellipseMinorAxis->value() * gridsize;

    int xc = p1.x();
    int yc = p1.y();


    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) +
                         (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    auto start = high_resolution_clock::now();
    // For region 1
    while (dx < dy)
    {

            // Print points based on 4-way symmetry
//        cout << x + xc << " , " << y + yc << endl;
//        cout << -x + xc << " , " << y + yc << endl;
//        cout << x + xc << " , " << -y + yc << endl;
//        cout << -x + xc << " , " << -y + yc << endl;
        delay(100);
        point(x+xc,y+yc,200,200,100);
        point(-x+xc,y+yc,200,200,100);
        point(x+xc,-y+yc,200,200,100);
        point(-x+xc,-y+yc,200,200,100);
        // Checking and updating value of
        // decision parameter based on algorithm
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    // Decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
         ((rx * rx) * ((y - 1) * (y - 1))) -
          (rx * rx * ry * ry);

    // Plotting points of region 2
    while (y >= 0)
    {
        delay(100);

        // Print points based on 4-way symmetry
//        cout << x + xc << " , " << y + yc << endl;
//        cout << -x + xc << " , " << y + yc << endl;
//        cout << x + xc << " , " << -y + yc << endl;
//        cout << -x + xc << " , " << -y + yc << endl;
        point(x+xc,y+yc,200,200,100);
        point(-x+xc,y+yc,200,200,100);
        point(x+xc,-y+yc,200,200,100);
        point(-x+xc,-y+yc,200,200,100);

        // Checking and updating parameter
        // value based on algorithm
        if (d2 > 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }

    auto end = high_resolution_clock::now();

    int executionTime = duration_cast<microseconds>(end - start).count();
    //    ui->timepolar->setText(QString::number(executionTime,'f',3));
    //    ui->time_circle_polar->setText(QString::number(executionTime,'f',3));
    ui->timeEllipseMidpoint->setText(QString::number(executionTime, 'f', 3));
}


void MainWindow::on_ellipsePolarMethod_clicked()
{
    int xr = ui->ellipseMajorAxis->value() * gridsize;
    int yr = ui->ellipseMinorAxis->value() * gridsize;

    int xc = p1.x();
    int yc = p1.y();

    double dth = 1/(double)((xr+yr)/2);
    double th = 0;
    double pi = 3.1416;

    double x,y;

    auto start = high_resolution_clock::now();

    while(th <= 2*pi)
    {

//        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        x = xr * cos(th);
        y = yr * sin(th);
//        sleeper(100000);

        point(xc+x, yc+y, 50,200,200);
        point(xc-x, yc+y, 50,200,200);
        point(xc+x, yc-y, 50,200,200);
        point(xc-x, yc-y, 50,200,200);
        delay(100);

//        sleeper(100000);

//        cout << "theta = " << th << endl;

        th = th + dth;

    }

    auto end = high_resolution_clock::now();
    int executionTime = duration_cast<microseconds>(end - start).count();
//    ui->timepolar->setText(QString::number(executionTime,'f',3));
//    ui->time_circle_polar->setText(QString::number(executionTime,'f',3));
    cout << "polar drawn" << endl;
    ui->timeEllipsePolar->setText(QString::number(executionTime, 'f', 3));

}



void MainWindow::on_fillScanline_clicked()
{
    for(int i = gridsize/2; i < ui->frame->height(); i+= gridsize){

        bool isOpen = false;
        vector<int> xlist ;
        for(int j = gridsize/2; j < ui->frame->width(); j+= gridsize){
//            delay(100);
//            if(isOpen){
//                point(j,i,250,250,250);
//            }
            if(img.pixelColor(j,i).blue() > 0){
                xlist.push_back(j);
            }
        }

        // filter xlist for extreme points
        if(xlist.size() > 1){
            int prev = xlist[0];
            for(int l = 1; l < xlist.size(); l++){
                delay(100);
                if(xlist[l] - prev == 1 || xlist[l] - prev == gridsize){
                    prev = xlist[l];
                    continue;
                }else{
                    isOpen = !isOpen;

                    if(isOpen){
                        for(int z = prev+gridsize; z < xlist[l]; z+=gridsize){
                            point(z,i,250,250,250);
                        }
                    }
                }
            }
        }

        cout << endl;
    }

}


void MainWindow::on_setFillPoint_clicked()
{
    p1.setX(ui->frame->x);
    p1.setY(ui->frame->y);

    cout << p1.x() << ", " << p1.y() << endl;
}




void MainWindow::on_floodFillBtn_clicked()
{
    int xc = p1.x();
    int yc = p1.y();

//    now we need to find the lPoint and Rpoint
    int lpoint = xc;
    int rpoint = yc;

//    for lpoint
    for(int x = xc-gridsize; x >=0 ; x-=gridsize){
        if(img.pixelColor(x,yc).blue() >= 20 ){
            lpoint = x;
            break;
        }
    }

//    for rpoint
    for(int x = xc+gridsize; x < ui->frame->width() ; x+=gridsize){
        if(img.pixelColor(x,yc).blue() >= 20 ){
            rpoint = x;
            break;
        }
    }

//    for(int z = lpoint+gridsize; z < rpoint; z+=gridsize){
//        point(z,yc,250,250,250);
//    }

    cout << "lpoint : " << lpoint << " : " << img.pixelColor(lpoint, yc).red() << ", " <<  img.pixelColor(lpoint, yc).green() << ", " << img.pixelColor(lpoint, yc).blue() << endl;
    cout << "lpoint : " << rpoint << " : " << img.pixelColor(rpoint, yc).red() << ", " <<  img.pixelColor(rpoint, yc).green() << ", " << img.pixelColor(rpoint, yc).blue() << endl;

    int clp = img.pixelColor(lpoint, yc).red() + img.pixelColor(lpoint, yc).green() + img.pixelColor(lpoint, yc).blue();
    int crp = img.pixelColor(rpoint, yc).red() + img.pixelColor(rpoint, yc).green() + img.pixelColor(rpoint, yc).blue();

    cout << "flood fill start" << endl;
    flood(xc,yc,clp, crp, gridsize);
//    flood(xc-gridsize,yc-gridsize,clp, crp, -gridsize);
    cout << "flood fill end" << endl;
}

void MainWindow::flood(int x, int y, int lm, int rm, int incrementFactor){
    int color = img.pixelColor(x,y).red() + img.pixelColor(x,y).green() + img.pixelColor(x,y).blue();

//    if(incrementFactor < 0){
//        cout << "isnegative" << endl;
//    }else if(incrementFactor > 0){
//        cout << "ispositive" << endl;
//    }

    if(color == lm || color == rm){
        return;
    }

    else if(img.pixelColor(x,y).blue() == 0){
        point(x,y,250,250,250);

        delay(10);

        flood(x + incrementFactor,y, lm, rm, incrementFactor);
        flood(x - incrementFactor,y, lm, rm, incrementFactor);
        flood(x ,y + incrementFactor, lm, rm, incrementFactor);
        flood(x ,y - incrementFactor, lm, rm, incrementFactor);

    }

//    delay(50);


}

void MainWindow::on_boundaryFill_clicked()
{
    int xc = p1.x();
    int yc = p1.y();
    int lpoint = xc;
    int rpoint = yc;

//    for lpoint
    for(int x = xc-gridsize; x >=0 ; x-=gridsize){
        if(img.pixelColor(x,yc).blue() >= 20 ){
            lpoint = x;
            break;
        }
    }

//    for rpoint
    for(int x = xc+gridsize; x < ui->frame->width() ; x+=gridsize){
        if(img.pixelColor(x,yc).blue() >= 20 ){
            rpoint = x;
            break;
        }
    }

//    for(int z = lpoint+gridsize; z < rpoint; z+=gridsize){
//        point(z,yc,250,250,250);
//    }

    cout << "lpoint : " << lpoint << " : " << img.pixelColor(lpoint, yc).red() << ", " <<  img.pixelColor(lpoint, yc).green() << ", " << img.pixelColor(lpoint, yc).blue() << endl;
    cout << "lpoint : " << rpoint << " : " << img.pixelColor(rpoint, yc).red() << ", " <<  img.pixelColor(rpoint, yc).green() << ", " << img.pixelColor(rpoint, yc).blue() << endl;

    int clp = img.pixelColor(lpoint, yc).red() + img.pixelColor(lpoint, yc).green() + img.pixelColor(lpoint, yc).blue();
    int crp = img.pixelColor(rpoint, yc).red() + img.pixelColor(rpoint, yc).green() + img.pixelColor(rpoint, yc).blue();

    cout << "boundary fill start" << endl;
    boundaryFill(xc,yc,clp, crp, gridsize);
    cout << "boundary fill end" << endl;
}


void MainWindow::boundaryFill(int x, int y, int lm, int rm, int incrementFactor){
    int color = img.pixelColor(x,y).red() + img.pixelColor(x,y).green() + img.pixelColor(x,y).blue();

//    if(incrementFactor < 0){
//        cout << "isnegative" << endl;
//    }else if(incrementFactor > 0){
//        cout << "ispositive" << endl;
//    }

    if(color == lm || color == rm){
        return;
    }

    else if(img.pixelColor(x,y).blue() == 0){
        point(x,y,250,250,250);

        delay(10);

        boundaryFill(x + incrementFactor,y, lm, rm, incrementFactor);
        boundaryFill(x ,y + incrementFactor, lm, rm, incrementFactor);

        boundaryFill(x - incrementFactor,y, lm, rm, incrementFactor);
        boundaryFill(x ,y - incrementFactor, lm, rm, incrementFactor);

    }

//    delay(50);


}

void MainWindow::on_setBoundary_clicked()
{
//    for y = 0 && y = width - gridsize
    int ly = ui->frame->width() - gridsize;
    for(int x = 0; x < ui->frame->width(); x+= gridsize){
        point(x,0,255,127,80);
        point(0,x,255,127,80);
        point(ly,x,255,127,80);
        point(x,ly,255,127,80);
    }

}


void MainWindow::on_drawClippingFrame_clicked()
{
    int xw = ui->clippingFrameX->value() * gridsize;
    int yw = ui->clippingFrameY->value() * gridsize;

//    int xc = p1.x();
//    int yc = p1.y();

    int xc = 451/2;
    int yc = 451/2;

    int lxc = xc - xw;
    int rxc = xc + xw;
    int dyc = yc - yw;
    int uyc = yc + yw;

    for(int i = lxc; i <= rxc; i+=gridsize){
        point(i,dyc,255,127,80);
        point(i,uyc,255,127,80);
    }

    for(int i = dyc; i <= uyc; i+=gridsize){
        point(rxc,i,255,127,80);
        point(lxc,i,255,127,80);
    }

//    point(rxc,uyc,200,0,0);
//    point(lxc,uyc,0,200,0);
//    point(rxc,dyc,0,0,200);
//    point(lxc,dyc,200,50,200); // for debug
}


void MainWindow::on_clipScreen_clicked()
{
    int r = 255, g = 127, b = 80;
    int xw = ui->clippingFrameX->value() * gridsize;
    int yw = ui->clippingFrameY->value() * gridsize;

//    int xc = p1.x();
//    int yc = p1.y();
//    int xc = ui->frame->width() / 2;
//    int yc = ui->frame->width() / 2;
    int xc = 451/2;
    int yc = 451/2;

    int lxc = xc - xw;
    int rxc = xc + xw;
    int dyc = yc - yw;
    int uyc = yc + yw;

//    for(int i = 0; i < ui->frame->width(); i+=gridsize){
//        for (int j = 0; j < ui->frame->width(); j+=gridsize){

////            int tr = img.pixelColor(j,i).red(), tg = img.pixelColor(j,i).green(), tb = img.pixelColor(j,i).blue();
//            if ( !((j > lxc && j < rxc) && (i > dyc && i < uyc)) ){
////                point(j,i,255,69,0);
//                point(j,i,0,0,0);
//            }

//        }
//    }
//    l-x-eraser and ly eraser

    for(int i = 0; i < lxc; i+=gridsize){
        for(int j = 0; j < ui->frame->width(); j+=gridsize){
            point(i,j,0,0,0);
        }
    }

    for(int i = rxc + gridsize; i < ui->frame->width(); i+=gridsize){
        for(int j = 0; j < ui->frame->width(); j+=gridsize){
            point(i,j,0,0,0);
        }
    }

//    for x

    for(int i = 0; i < dyc; i+=gridsize){
        for(int j = 0; j < ui->frame->width(); j+=gridsize){
            point(j,i,0,0,0);
        }
    }

    for(int i = uyc + gridsize; i < ui->frame->width(); i+=gridsize){
        for(int j = 0; j < ui->frame->width(); j+=gridsize){
            point(j,i,0,0,0);
        }
    }

}


void MainWindow::on_markCentre_clicked()
{
    int width = ui->frame->width();
    int xc = width / 2;
    int yc = xc;
    point(xc,yc,255,50,50);

//    use equation
    double x = p1.x();
    double y = p1.y();

    double dox = -y - 0.1*x;
    double doy = x - 0.4*y;

    int count = 0;

    while(count < 50){
        dox = (y - 0.1*x);
        doy = (x - 0.1*y);

        double tx = x + dox;
        double ty = y + doy;

        point((int)xc,(int)yc,255,50,50);
        cout << (int)tx << " " <<  (int)ty << endl;

        x = tx;
        y = ty;
        count++;
    }

}


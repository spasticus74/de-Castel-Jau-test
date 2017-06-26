#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QList<QPoint> bez;
//    bez.append(QPoint(200, 200));
//    bez.append(QPoint(200, 100));
//    bez.append(QPoint(300, 400));
//    bez.append(QPoint(400, 400));
//    bez.append(QPoint(322384, 6378868));
//    bez.append(QPoint(322409, 6379060));
//    bez.append(QPoint(322392, 6379147));
//    bez.append(QPoint(322525, 6379127));
        bez.append(QPoint(320800, 6381533));
        bez.append(QPoint(320821, 6381758));
        bez.append(QPoint(320933, 6381485));
        bez.append(QPoint(320967, 6381442));


    for(float j=0; j <= 1; j =j + 0.1) {
        QPoint _p = deCastelJau(bez, j);
        qDebug() << _p.x() << "," << _p.y();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPoint MainWindow::deCastelJau(QList<QPoint> points, float t)
{
    if(t == 1) {
        return(points[points.size()]);
    }

    if(t == 0) {
        return(points[0]);
    }

    if(points.size() == 1) {
        return(points[0]);
    }

    QList< QPoint > calculatedPoints;
    for(int i = 1; i < points.size(); i++)
    {
        calculatedPoints.append(calculatePoints(points[i-1], points[i], t));
    }

    return(deCastelJau(calculatedPoints, t));
}

QPoint MainWindow::calculatePoints(QPoint point0, QPoint point1, float t)
{
    float pInterX = point0.x() + (point1.x() - point0.x()) * t;
    float pInterY = point0.y() + (point1.y() - point0.y()) * t;
    return( QPoint(pInterX, pInterY));
}

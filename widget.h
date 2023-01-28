#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QMessageBox>
#include <QVector>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public:
    QTimer *timer_com;
    QTimer *timer_refresh;
    QVector<double> data_x;
    QVector<double> data_y;

    double T;//采样周期,单位S
    int num;

private slots:
    void on_openSerial_btn_clicked();

    void on_plot_btn_clicked();

private:
    Ui::Widget *ui;
    QSerialPort *serial;
};

#endif // WIDGET_H

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->num = 0;
    this->T=0.01;

    //串口，timer
    serial = new QSerialPort(this); //新建一个串口对象，存储在堆区
    connect(this->serial,&QSerialPort::readyRead,this,[=]{
        double x = (num++)*T; //计算曲线横坐标值
        data_x.push_back(x);
        double y = QString(serial->readAll().data()).toDouble(); //获取曲线纵坐标值，即浓度
        data_y.push_back(y);
       if(num>=100)  //当曲线显示了100个样本后，释放之前的数据，达到动态的效果
       {
           data_x.pop_front();
           data_y.pop_front();
       }
    });

    timer_com  = new QTimer(this);  //新建一个定时器，用于刷新串口号
    connect(timer_com,&QTimer::timeout,this,[=]{  //定时刷新串口号
        ui->COM->clear();
        foreach(const QSerialPortInfo info,QSerialPortInfo::availablePorts())  //搜索可用的串口，并遍历
        {
            ui->COM->addItem(info.portName()); //将用户选择的串口号和可用串口绑定
        }
    });
    timer_com->start(4000); //刷新间隔 4000ms

    timer_refresh = new QTimer(this);   //新建一个定时器，用于浓度曲线和数据的刷新
    connect(timer_refresh,&QTimer::timeout,this,[=]{  //定时刷新数据显示
        if(num>=100)
        {
            ui->plot->xAxis->setRange(*data_x.begin(),num*T); //当曲线显示了100个样本后，重新设置横坐标，达到动态的效果
        }
        ui->plot->graph(0)->setData(data_x,data_y); //设置横坐标和纵坐标数据
        ui->plot->replot();  //曲线绘制
        ui->plainTextEdit->appendPlainText(QString("血糖浓度为：")+QString::number(*(data_y.end()),'f',3)+QString("mMol/L")); //文本框添加浓度数据
    });

    //曲线属性设置
    this->ui->plot->xAxis->setLabel("时间/s");  //设置横坐标标签
    this->ui->plot->xAxis->setRange(0,1);  //设置初始横坐标范围
    this->ui->plot->yAxis->setLabel("血糖浓度");  //设置纵坐标标签
    this->ui->plot->yAxis->setRange(0,10);  //设置初始纵坐标范围
    this->ui->plot->addGraph();  //实例化一个曲线
}

//析构函数
Widget::~Widget()
{
    delete ui;  //释放ui界面
}

//打开、关闭串口
void Widget::on_openSerial_btn_clicked()
{
    if(ui->openSerial_btn->text()=="打开串口")  //判断串口是否打开
    {
        foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
        {
            if(info.portName()==ui->COM->currentText())
            {
                //串口属性设置
                serial->setPort(info);  //绑定串口
                serial->setBaudRate(ui->BautRate->currentText().toInt()); //设置串口名
                serial->setDataBits(QSerialPort::Data8);//设置串口每次传输的数据位，一般为8位
                serial->setStopBits(QSerialPort::OneStop); //设置停止位
                serial->setParity(QSerialPort::NoParity); //无校验位

                serial->open(QIODevice::ReadWrite); //打开串口

                ui->openSerial_btn->setText("关闭串口");
                ui->openSerial_btn->setStyleSheet("background-color:red");//设置按钮背景颜色

                timer_com->stop(); //禁止串口号刷新
            }
        }
    }
    else if(ui->openSerial_btn->text()=="关闭串口"||serial->isOpen())
    {
        serial->close(); //关闭串口
        ui->openSerial_btn->setText("打开串口");
        ui->openSerial_btn->setStyleSheet("background-color:green");
        timer_com->start(2000); //开启串口号刷新
    }
    else QMessageBox::warning(this,"错误","串口关闭失败！！！");
}

void Widget::on_plot_btn_clicked()
{
    if(serial->isOpen())
    {
        timer_refresh->start(15);//15ms显示一次
    }
}

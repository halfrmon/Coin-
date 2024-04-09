#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include "mybutton.h"
#include<QDebug>
#include <QTimer>
Mainscene::Mainscene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mainscene)
{
    ui->setupUi(this);
    //配置主场景
    this->setFixedSize(320,588);
    //设置图标i
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");
    //实现退出
    connect(ui->actionquit,&QAction::triggered,[=](){this->close();});

    //开始按钮
    mybutton*startbtn = new mybutton(":/res/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.7);
    choosescene = new ChooseLevelscene;
    connect(startbtn,&QPushButton::clicked,[=](){
        startbtn->zoom1();
        startbtn->zoom2();

        //延时
        QTimer::singleShot(500,this,[=](){
            this->hide();
            //进入选择
            choosescene->show();

        });

    });
    //connect(choosescene,&ChooseLevelscene::choosesceneback,[=](){this->show();});



}

void Mainscene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
        //创建QPixmap对象
    QPixmap pix;
        //加载图片
    pix.load(":/res/PlayLevelSceneBg.png");
        //绘制背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);


        //加载标题
    pix.load(":/res/Title.png");
        //缩放图片
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

Mainscene::~Mainscene()
{
    delete ui;
}


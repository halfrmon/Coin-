#include "chooselevelscene.h"
#include<QMenuBar>
#include<QPushButton>
#include<QPainter>
#include"mybutton.h"
#include<QTimer>
#include<QDebug>
#include<QLabel>
#include"playscene.h"
ChooseLevelscene::ChooseLevelscene(QWidget *parent)
    : QMainWindow{parent}
{
    //配置
    this->setFixedSize(320,588);
    //设置图标i
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    this->setWindowTitle("翻金币");
    //实现退出

    //创建菜单栏
    QMenuBar * bar = this->menuBar();
    this->setMenuBar(bar);
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
//    QMenu * quittMenu = bar->addMenu("退出");
//    connect(quittMenu->menuAction(), &QAction::triggered, [=]() {this->close();});

    QAction *quitaction=startMenu->addAction("退出");
    connect(quitaction,&QAction::triggered,[=](){this->close();});

    mybutton *close =new  mybutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    close->setParent(this);
    close->move(this->width()-close->width(),this->height()-close->height());
    connect(close,&mybutton::clicked,[=](){qDebug()<<"dianji";});
    connect(close,&mybutton::clicked,[=](){QTimer::singleShot(200,this,[=](){
            this->hide();
            emit this->choosesceneback();
        });});
    connect(this,&ChooseLevelscene::choosesceneback,[=](){this->show();});


    //循环创建关卡图标

    for(int i=0;i<20;i++)
    {
        mybutton *menubtn = new  mybutton(":/res/LevelIcon.png");
        menubtn->setParent(this);
        menubtn->move(25+(i%4)*70,130+(i/4)*70);
        QLabel *label =new QLabel;
        label->setParent(this);
        label->setFixedSize(menubtn->width(),menubtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        label->move(25+(i%4)*70,130+(i/4)*70);
        label->setAttribute(Qt::WA_TransparentForMouseEvents,true);
        connect(menubtn,&mybutton::clicked,[=](){
            if(pscene==NULL)
            {
                this->hide();
                pscene=new playscene(i+1);
                pscene->show();
                connect(pscene,&playscene::choosesceneback,[=]()
                {
                    this->show();
                    delete pscene;
                    pscene=nullptr;
                });
            }
            //将点击退出的信号操作放在这也没问题
//            connect(pscene,&playscene::choosesceneback,[=]()
//            {
//                this->show();
//                delete pscene;
//                pscene=nullptr;
//            });




        });
    }


}


void ChooseLevelscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

         //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);



}

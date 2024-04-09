#include "coin.h"

#include<QSize>
#include<QDebug>
Coin::Coin(QString btnimg)
{
    QPixmap pix;
    bool ret = pix.load(btnimg);
    if(!ret)
    {
        qDebug()<<btnimg<<"加载图片失败";

    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);
        this->setFixedSize(QSize(pix.width(),pix.height()));
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max)
        {
            this->min = 1;
            this->isanimation=false;
            timer1->stop();
        }


    });
    connect(timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str =QString(":/res/Coin000%8.png").arg(this->max--);
        pix.load(str);
        this->setFixedSize(QSize(pix.width(),pix.height()));
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if (this->max<this->min)
        {
            this->max=8;
            this->isanimation=false;
            timer2->stop();
        }
    });
}

void Coin::changeflag()
{
    if(this->flag)
    {
        timer1->start(30);
        this->isanimation=true;
        this->flag=false;
    }
    else
    {
        timer2->start(30);
        this->isanimation=true;
        this->flag=true;
    }
}



void Coin::mousePressEvent(QMouseEvent *e)
{
    if(this->isanimation||iswin==true)
    {
        return;
    }
    else
    {
        return QPushButton::mousePressEvent(e);
    }
}

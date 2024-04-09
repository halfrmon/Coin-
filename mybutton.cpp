#include "mybutton.h"
#include<QDebug>
#include<QPropertyAnimation>
#include<QMouseEvent>
//mybutton::mybutton(QWidget *parent)
//    : QWidget{parent}
//{

//}
mybutton::mybutton(QString normalimg,QString pressimg)
{
    this->normalimgpath=normalimg;
    this->pressimgpath=pressimg;
    QPixmap pix;
    bool ret = pix.load(normalimg);
    if(!ret)
    {
        qDebug()<<"图片加载失败";
        return;
    }
    //设置图片大小
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void mybutton::zoom1()
{
    QPropertyAnimation *animation1 =new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void mybutton::zoom2()
{
    QPropertyAnimation *animation1 =new QPropertyAnimation(this,"geometry");
    animation1->setDuration(200);
    animation1->setStartValue(QRect(this->x(),this->y()+5,this->width(),this->height()));
    animation1->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    animation1->start();
}

void mybutton::mousePressEvent(QMouseEvent*e)
{
    if(pressimgpath != "")
    {
        QPixmap pix;
        bool ret = pix.load(pressimgpath);
        if(!ret)
        {
            qDebug()<<pressimgpath<<"加载图片失败";
        }
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    return QPushButton::mousePressEvent(e);
}
void mybutton::mouseReleaseEvent(QMouseEvent *e)
{
    if(normalimgpath != "") //选中路径不为空，显示选中图片
    {
        QPixmap pixmap;
        bool ret = pixmap.load(normalimgpath);
        if(!ret)
        {
            qDebug() << normalimgpath << "加载图片失败!";
        }
        this->setFixedSize( pixmap.width(), pixmap.height() );
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pixmap);
        this->setIconSize(QSize(pixmap.width(),pixmap.height()));
    }
    //交给父类执行 释放事件
    return QPushButton::mouseReleaseEvent(e);
}

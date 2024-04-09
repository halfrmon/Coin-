#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include<QPushButton>

class mybutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mybutton(QWidget *parent = nullptr);
    mybutton(QString normalimg,QString pressimg="");
    QString normalimgpath;
    QString pressimgpath;
    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);

signals:

};

#endif // MYBUTTON_H

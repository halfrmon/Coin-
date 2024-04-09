#ifndef COIN_H
#define COIN_H

#include<QTimer>
#include<QPushButton>
class Coin : public QPushButton
{
    Q_OBJECT
public:
//    explicit Coin(QWidget *parent = nullptr);
    Coin(QString btnimg);
    int posx;
    int posy;
    bool flag;
    void changeflag();
    void mousePressEvent(QMouseEvent*e);
    QTimer *timer1;
    QTimer *timer2;
    int min=1;
    int max=8;
    bool isanimation =false;
    bool iswin=false;
signals:

};

#endif // COIN_H

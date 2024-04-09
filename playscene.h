#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include"coin.h"
#include <QMainWindow>

class playscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit playscene(QWidget *parent = nullptr);
    int levalindex;
    playscene(int index);
    int gamearray[4][4];
    void paintEvent(QPaintEvent*);
    Coin *coinbtn[4][4];
    bool iswin;
signals:
    void choosesceneback();
};

#endif // PLAYSCENE_H

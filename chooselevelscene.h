#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include "playscene.h"
class ChooseLevelscene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelscene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    playscene *pscene=nullptr;
signals:
    void choosesceneback();
};

#endif // CHOOSELEVELSCENE_H

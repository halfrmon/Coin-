#ifndef MAINSCENE_H
#define MAINSCENE_H
#include"chooselevelscene.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Mainscene; }
QT_END_NAMESPACE

class Mainscene : public QMainWindow
{
    Q_OBJECT

public:
    Mainscene(QWidget *parent = nullptr);

    ~Mainscene();
    void paintEvent(QPaintEvent*);
    ChooseLevelscene *choosescene = nullptr;
private:
    Ui::Mainscene *ui;
};
#endif // MAINSCENE_H

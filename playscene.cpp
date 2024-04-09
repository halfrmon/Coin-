#include "playscene.h"
#include <QMenuBar>
#include<QPainter>
#include"mybutton.h"
#include<QTimer>
#include<QLabel>
#include"coin.h"
#include "dataconfig.h"
#include <QDebug>
#include <QPropertyAnimation>
playscene::playscene(int index)
{
    this->levalindex=index;
    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币");
    QMenuBar *bar =this->menuBar();
    this->setMenuBar(bar);
    QMenu *startmenu = bar->addMenu("开始");
    QAction*quitaction = startmenu->addAction("退出");
    connect(quitaction,&QAction::triggered,[=](){this->close();});
    mybutton *closebtn=new mybutton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    closebtn->setParent(this);
    closebtn->move(this->width()-closebtn->width(),this->height()-closebtn->height());
    connect(closebtn,&mybutton::clicked,[=](){QTimer::singleShot(500,this,[=]()
        {this->hide();emit this->choosesceneback();});});
    QLabel *label =new  QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString str = QString("Leavel:%1").arg(this->levalindex);
    label->setText(str);
    label->setGeometry(QRect(30, this->height() - 50,120, 50));

    dataConfig config;

    QLabel*winlabel = new QLabel;
    QPixmap tmppix;
    tmppix.load(":/res/LevelCompletedDialogBg.png");
    winlabel->setGeometry(0,0,tmppix.width(),tmppix.height());
    winlabel->setPixmap(tmppix);
    winlabel->setParent(this);
    winlabel->move((this->width()-tmppix.width())*0.5,-tmppix.height());


    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
            QLabel*label=new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode(1).png"));
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            gamearray[i][j]=config.mData[this->levalindex][i][j];
            QString img;
            if(gamearray[i][j]==1)
            {
                img=":/res/Coin0001.png";
            }
            else
            {
                img = ":/res/Coin0008.png";
            }
            Coin*coin=new Coin(img);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);
            coin->posx=i;
            coin->posy=j;
            coin->flag = gamearray[i][j];

            coinbtn[i][j] = coin;
            connect(coin,&Coin::clicked,[=](){
                coin->changeflag();
                this->gamearray[i][j]=this->gamearray[i][j]==0?1:0;
                QTimer::singleShot(300,this,[=](){
                    if(coin->posx+1<=3)
                    {
                        coinbtn[coin->posx+1][coin->posy]->changeflag();
                        gamearray[coin->posx+1][coin->posy]=gamearray[coin->posx+1][coin->posy]==0?1:0;

                    }
                    if(coin->posx-1>=0)
                    {
                        coinbtn[coin->posx-1][coin->posy]->changeflag();
                        gamearray[coin->posx-1][coin->posy]=gamearray[coin->posx-1][coin->posy]==0?1:0;

                    }
                    if(coin->posy+1<=3)
                    {
                        coinbtn[coin->posx][coin->posy+1]->changeflag();
                        gamearray[coin->posx][coin->posy+1]=gamearray[coin->posx][coin->posy+1]==0?1:0;

                    }
                    if(coin->posx-1>=0)
                    {
                        coinbtn[coin->posx][coin->posy-1]->changeflag();
                        gamearray[coin->posx][coin->posy-1]=gamearray[coin->posx][coin->posy-1]==0?1:0;

                    }

                });
               ;
                for(int i = 0;i<4;i++)
                {
                    for(int j =0;j<4;j++)
                    {
                       coinbtn[i][j]->iswin=true;
                       if(coinbtn[i][j]->flag==false)
                       {
                            this->iswin=false;
                            break;
                       }
                       if( this->iswin==true)
                       {
                           qDebug()<<"胜利";
                           QPropertyAnimation*animation1=new  QPropertyAnimation(winlabel,"geometry");
                           animation1->setDuration(1000);
                           animation1->setStartValue(QRect(winlabel->x(),
                                                     winlabel->y(),
                                                     winlabel->width(),
                                                     winlabel->height()));
                           animation1->setEndValue(QRect(winlabel->x(),winlabel->y()+150,winlabel->width(),winlabel->height()));
                                                   animation1->setEasingCurve(QEasingCurve::OutBounce);
                                                   animation1->start();
                       }

                    }
                }






            });


        }
     }




}


void playscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

         //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap( (this->width() - pix.width())*0.5,30,pix.width(),pix.height(),pix);


}

#include "battlepage.h"
#include "ui_battlepage.h"
#include "barrier.h"
#include "tank.h"
#include "config.h"
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QDebug>


BattlePage::BattlePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BattlePage)
{
    ui->setupUi(this);
    this->setFixedSize(620, 600);
    this->move(550, 200);
    this->setWindowTitle("坦克大战");

    bar.map1();//加载地图
    initial();//初始化

    //启动计时器
    timer = new QTimer(this);
    timer->start(50);

    connect(timer, &QTimer::timeout, this, &BattlePage::playerMove);//连接计时器的信号到槽函数

}

BattlePage::~BattlePage()
{
    delete ui;

}

void BattlePage::initial()
{
    //创建玩家
    player = new Tank(0);
    player->dir = dup;
    player->rect.setRect(11*BasicSize, 28*BasicSize, 40, 40);
    //Player的坐标
    player->x = player->rect.x();
    player->y = player->rect.y();
    //子弹位置、大小初始化
    player->bullet.rect.setRect(player->rect.x()+15, player->rect.y(), 10, 10);

    //创建敌人
    enemy1 = new Tank(1);  
    enemy2 = new Tank(1);
    enemy3 = new Tank(1);
    enemy4 = new Tank(1);
    enemy5 = new Tank(1);

    enemy1->dir = null;
    enemy2->dir = null;
    enemy3->dir = null;
    enemy4->dir = null;
    enemy5->dir = null;

    enemy1->rect.setRect(0*BasicSize, 0*BasicSize, 40, 40);
    enemy2->rect.setRect(6*BasicSize, 0*BasicSize, 40, 40);
    enemy3->rect.setRect(12*BasicSize, 0*BasicSize, 40, 40);
    enemy4->rect.setRect(18*BasicSize, 0*BasicSize, 40, 40);
    enemy5->rect.setRect(24*BasicSize, 0*BasicSize, 40, 40);

    update();
}

bool BattlePage::isCollision(Tank &tank)
{
    return true;
}

bool BattlePage::isBoom(Tank &tank)
{
    //if(tank.bullet.rect.intersects(1, 2))
}

void BattlePage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    //画背景图
    p.drawPixmap(0, 0, width(), height(), QPixmap("../Image/black.png"));

    //画子弹
    if(player->bullet.dir == dup)
        p.drawPixmap(player->bullet.rect, player->bullet.upImage);
    else if(player->bullet.dir == ddown)
        p.drawPixmap(player->bullet.rect, player->bullet.downImage);
    else if(player->bullet.dir == dleft)
        p.drawPixmap(player->bullet.rect, player->bullet.leftImage);
    else if(player->bullet.dir == dright)
        p.drawPixmap(player->bullet.rect, player->bullet.rightImage);

    //画玩家
    if(player->dir == dup)
        p.drawPixmap(player->rect, player->upImage);
    else if(player->dir == ddown)
        p.drawPixmap(player->rect, player->downImage);
    else if(player->dir == dleft)
        p.drawPixmap(player->rect, player->leftImage);
    else if(player->dir == dright)
        p.drawPixmap(player->rect, player->rightImage);


    //for test
//    qDebug()<<player->rect.x();
//    qDebug()<<player->rect.y();

    //画敌人

    p.drawPixmap(enemy1->rect, enemy1->downImage);
    p.drawPixmap(enemy2->rect, enemy2->downImage);
    p.drawPixmap(enemy3->rect, enemy3->downImage);
    p.drawPixmap(enemy4->rect, enemy4->downImage);
    p.drawPixmap(enemy5->rect, enemy5->downImage);

    for(int x=0;x<Boarder;x++){
        for(int y=0;y<Boarder;y++){
            if(bar.barrier[x][y] == 1){
                p.drawPixmap(x*20, y*20, BasicSize, BasicSize, bar.wall);
            }
            else if(bar.barrier[x][y] == 2){
                p.drawPixmap(x*20, y*20, BasicSize, BasicSize, bar.stone);
            }
            else if(bar.barrier[x][y] == 3){
                p.drawPixmap(x*20, y*20, BaseSize, BaseSize, bar.base);
            }
            else
                continue;
        }
    }
}

void BattlePage::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        emit escape();
    }
    else if(event->key() == Qt::Key_Up){
        player->isMove = true;
        player->dir = dup;
    }
    else if(event->key() == Qt::Key_Down){
        player->isMove = true;
        player->dir = ddown;
    }
    else if(event->key() == Qt::Key_Left){
        player->isMove = true;
        player->dir = dleft;
    }
    else if(event->key() == Qt::Key_Right){
        player->isMove = true;
        player->dir = dright;
    }
    else if(event->key() == Qt::Key_Space){
        player->shoot();
    }
    else{
        return;
    }
}

void BattlePage::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() != Qt::Key_Space){
        player->isMove = false;
    }
}

void BattlePage::playerMove()
{
    //子弹移动
    if(player->bullet.isMove == true){
        if(player->bullet.dir == dup){
            player->bullet.y -= player->bullet.speed;
            player->bullet.rect.moveTo(player->bullet.x, player->bullet.y);
        }
        else if(player->bullet.dir == ddown){
            player->bullet.y += player->bullet.speed;
            player->bullet.rect.moveTo(player->bullet.x, player->bullet.y);
        }
        else if(player->bullet.dir == dleft){
            player->bullet.x -= player->bullet.speed;
            player->bullet.rect.moveTo(player->bullet.x, player->bullet.y);
        }
        else if(player->bullet.dir == dright){
            player->bullet.x += player->bullet.speed;
            player->bullet.rect.moveTo(player->bullet.x, player->bullet.y);
        }
    }


    //坦克移动
    int cx = player->rect.x()/BasicSize;
    int cy = player->rect.y()/BasicSize;

    // || player->rect.y()<5 || player->rect.x()>575 || player->rect.y()>555)
    //将要出界时停止
    if(player->rect.x()<0){
        player->isMove = false;
        player->rect.moveTo(0, player->y);
        return;
    }
    else if(player->rect.x()>580){
        player->isMove = false;
        player->rect.moveTo(580, player->y);
        return;
    }
    else if(player->rect.y()<0){
        player->isMove = false;
        player->rect.moveTo(player->x, 0);
        return;
    }
    else if(player->rect.y()>560){
        player->isMove = false;
        player->rect.moveTo(player->x, 560);
        return;
    }

    if(player->dir == dup && player->isMove){
        //遇到障碍物时停止
        if(player->rect.intersects(bar.rect[cx][cy])
                || player->rect.intersects(bar.rect[cx+1][cy])
                || player->rect.intersects(bar.rect[cx+2][cy]))
        {
            qDebug()<<"collide";
            return;
        }
        //否则移动
        player->dir = dup;
        player->y -= player->speed;
        player->rect.moveTo(player->x, player->y);
    }

    else if(player->dir == ddown && player->isMove){

        //遇到障碍物时停止
        if(player->rect.intersects(bar.rect[cx][cy+2])
            || player->rect.intersects(bar.rect[cx-1][cy+2])
            || player->rect.intersects(bar.rect[cx-2][cy+2]))
        {
            qDebug()<<"collide";
            return;
        }
        //否则移动
        player->dir = ddown;
        player->y += player->speed;
        player->rect.moveTo(player->x, player->y);
    }

    else if(player->dir == dright && player->isMove){

        //遇到障碍物时停止
        if(player->rect.intersects(bar.rect[cx+2][cy])
            || player->rect.intersects(bar.rect[cx+2][cy+1])
            || player->rect.intersects(bar.rect[cx+2][cy+2]))
        {
            qDebug()<<"collide";
            return;
        }
        //否则移动
        player->dir = dright;
        player->x += player->speed;
        player->rect.moveTo(player->x, player->y);
    }

    else if(player->dir == dleft && player->isMove){

        //遇到障碍物时停止
        //qDebug()<<cx<<" "<<cy;
        //qDebug()<<player->rect;
        //qDebug()<<bar.rect[cx][cy]<<" "<<bar.rect[cx][cy+1]<<" "<<bar.rect[cx][cy+2];
        if(player->rect.intersects(bar.rect[cx][cy])
            || player->rect.intersects(bar.rect[cx][cy+1])
            || player->rect.intersects(bar.rect[cx][cy+2]))
        {
            qDebug()<<"collide";
            return;
        }
        //否则移动
        player->dir = dleft;
        player->x -= player->speed;
        player->rect.moveTo(player->x, player->y);
    }

        update();
}

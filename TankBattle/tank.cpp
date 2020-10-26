#include "tank.h"

Tank::Tank(bool t)
{
    isMove = false;
    type = t;
    dir = dup;
    speed = 4;
    bulletNum = true;
    loadImage();
}

//加载各个方向坦克图片
void Tank::loadImage()
{
    if(type == 0){
        upImage.load(":/player/res/pic/0Player/m0-1-1.gif");
        downImage.load(":/player/res/pic/0Player/m0-3-1.gif");
        leftImage.load(":/player/res/pic/0Player/m0-0-1.gif");
        rightImage.load(":/player/res/pic/0Player/m0-2-1.gif");
    }
    else{
        upImage.load(":/enemy/res/pic/gray-tank/1-2-1.gif");
        downImage.load(":/enemy/res/pic/gray-tank/1-4-1.gif");
        leftImage.load(":/enemy/res/pic/gray-tank/1-1-1.gif");
        rightImage.load(":/enemy/res/pic/gray-tank/1-3-1.gif");
    }
}

void Tank::shoot()
{
    if(bulletNum == 0)
        return;
    //初始化炮弹
    bullet.isMove = 1;
    bullet.dir = this->dir;
    bullet.rect.setRect(this->rect.x()+15, this->rect.y(), 10, 10);
    bullet.x = bullet.rect.x();
    bullet.y = bullet.rect.y();
    //炮弹数量变为0
    bulletNum = false;
}


#ifndef TANK_H
#define TANK_H

#include <QPixmap>
#include <QRect>
#include "bullet.h"
#include "config.h"

class Tank
{
public:
    Tank(bool t);

    int speed;//移动速度
    int x, y;//坦克坐标
    bool isMove;
    bool bulletNum;//子弹数量（一个坦克在战场上只能同时拥有一颗炮弹）
    bool type;//0代表玩家，1代表敌人

    Direct dir;//前进方向
    QRect rect;//用来表示坦克实体

    Bullet bullet;

    QPixmap upImage;
    QPixmap downImage;
    QPixmap leftImage;
    QPixmap rightImage;

    void loadImage();
    void shoot();
    bool isBoom();//判断炮弹是否击中目标

};

#endif // TANK_H

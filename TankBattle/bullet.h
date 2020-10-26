#ifndef BULLET_H
#define BULLET_H

#include <QRect>
#include <QPixmap>
#include "config.h"

class Bullet
{
public:
    Bullet();

    QRect rect;//炮弹实体
    Direct dir;//发射方向

    bool isMove;//判断炮弹是否发射
    int speed;//炮弹速度
    int x, y;//炮弹坐标

    //各个方向的炮弹图片
    QPixmap upImage;
    QPixmap downImage;
    QPixmap leftImage;
    QPixmap rightImage;

};

#endif // BULLET_H

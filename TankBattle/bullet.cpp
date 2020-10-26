#include "bullet.h"
#include <QPixmap>

Bullet::Bullet()
{
    speed = 7;
    isMove = false;
    dir = null;
    rect.setRect(0, 0, 10, 10);

    upImage = QPixmap(":/bullet/res/pic/bullet-1.gif");
    downImage = QPixmap(":/bullet/res/pic/bullet-3.gif");
    leftImage = QPixmap(":/bullet/res/pic/bullet-0.gif");
    rightImage = QPixmap(":/bullet/res/pic/bullet-2.gif");

}

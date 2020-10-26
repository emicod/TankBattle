#ifndef BARRIER_H
#define BARRIER_H

#include <QRect>
#include <QPixmap>

class Barrier
{
public:
    Barrier();

    QPixmap wall;
    QPixmap stone;
    QPixmap base;
    QRect rect[31][30];
    int barrier[31][30];//0代表空，1代表墙，2代表石头，3代表基地

    void map1();
};

#endif // BARRIER_H

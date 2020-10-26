#ifndef BATTLEPAGE_H
#define BATTLEPAGE_H

#include "tank.h"
#include "barrier.h"
#include "tank.h"
#include <QWidget>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QTimer>
#include <QTimerEvent>

namespace Ui {
class BattlePage;
}

class BattlePage : public QWidget
{
    Q_OBJECT

public:
    explicit BattlePage(QWidget *parent = 0);
    ~BattlePage();

    Tank *player;
    Tank *enemy1;
    Tank *enemy2;
    Tank *enemy3;
    Tank *enemy4;
    Tank *enemy5;
    Barrier bar;
    QTimer *timer;

    void initial();
    bool isCollision(Tank &tank);//判断是否发生碰撞
    bool isBoom(Tank &tank);//判断炮弹是否击中目标


    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    //void timerEvent(QTimerEvent *event) override;

public slots:
    void playerMove();

private:
    Ui::BattlePage *ui;

signals:
    void escape();
};

#endif // BATTLEPAGE_H

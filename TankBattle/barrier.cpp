#include "barrier.h"

Barrier::Barrier()
{
    for(int i=0;i<31;i++){
        for(int j=0;j<30;j++){
            barrier[i][j] = 0;
        }
    }

    //wall.
    wall.load(":/building/res/pic/wall.gif");
    stone.load(":/building/res/pic/stone.gif");
    base.load(":/building/res/pic/camp0.gif");
}

//绘制地图
void Barrier::map1()
{
    //基地
    barrier[14][27] = 3;
    rect[14][27].setRect(14*20, 27*20, 20, 20);
    //围墙
    barrier[13][26] = 1;
    barrier[13][27] = 1;
    barrier[13][28] = 1;
    barrier[13][29] = 1;
    barrier[14][26] = 1;
    barrier[15][26] = 1;
    barrier[16][26] = 1;
    barrier[17][26] = 1;
    barrier[17][27] = 1;
    barrier[17][28] = 1;
    barrier[17][29] = 1;

    rect[13][26].setRect(13*20, 26*20, 20, 20);
    rect[13][27].setRect(13*20, 27*20, 20, 20);
    rect[13][28].setRect(13*20, 28*20, 20, 20);
    rect[13][29].setRect(13*20, 29*20, 20, 20);
    rect[14][26].setRect(14*20, 26*20, 20, 20);
    rect[15][26].setRect(15*20, 26*20, 20, 20);
    rect[16][26].setRect(16*20, 26*20, 20, 20);
    rect[17][26].setRect(17*20, 26*20, 20, 20);
    rect[17][27].setRect(17*20, 27*20, 20, 20);
    rect[17][28].setRect(17*20, 28*20, 20, 20);
    rect[17][29].setRect(17*20, 29*20, 20, 20);



    //地形
    for(int i=2;i<30;i+=5)
        for(int j=2;j<=10;j++){
            barrier[i][j] = 1;
            barrier[i+1][j] = 1;
            rect[i][j].setRect(i*20, j*20, 20, 20);
            rect[i+1][j].setRect((i+1)*20, j*20, 20, 20);
        }
    for(int i=2;i<30;i+=5)
        for(int j=17;j<=24;j++){
            barrier[i][j] = 1;
            barrier[i+1][j] = 1;
            rect[i][j].setRect(i*20, j*20, 20, 20);
            rect[i+1][j].setRect((i+1)*20, j*20, 20, 20);
        }
    //for(int a=0;a<)
    for(int i=4;i<=6;i++){
        barrier[i][20] = 1;
        barrier[i][21] = 1;
        rect[i][20].setRect(i*20, 20*20, 20, 20);
        rect[i][21].setRect(i*20, 21*20, 20, 20);
    }
    for(int i=24;i<=27;i++){
        barrier[i][20] = 1;
        barrier[i][21] = 1;
        rect[i][20].setRect(i*20, 20*20, 20, 20);
        rect[i][21].setRect(i*20, 21*20, 20, 20);
    }
    for(int i=14;i<=16;i++){
        barrier[i][6] = 2;
        barrier[i][7] = 2;
        rect[i][6].setRect(i*20, 6*20, 20, 20);
        rect[i][7].setRect(i*20, 7*20, 20, 20);
    }
    for(int i=14;i<=16;i++){
        barrier[i][6] = 2;
        barrier[i][7] = 2;
        barrier[i][20] = 2;
        barrier[i][21] = 2;
        rect[i][6].setRect(i*20, 6*20, 20, 20);
        rect[i][7].setRect(i*20, 7*20, 20, 20);
        rect[i][20].setRect(i*20, 20*20, 20, 20);
        rect[i][21].setRect(i*20, 21*20, 20, 20);
    }
    for(int i=4;i<=11;i++){
        barrier[i][13] = 1;
        //barrier[i][14] = 1;
        rect[i][13].setRect(i*20, 13*20, 20, 20);
        //rect[i][14].setRect(i*20, 14*20, 20, 20);
    }
    for(int i=19;i<=26;i++){
        barrier[i][13] = 1;
       // barrier[i][14] = 1;
        rect[i][13].setRect(i*20, 13*20, 20, 20);
       // rect[i][14].setRect(i*20, 14*20, 20, 20);
    }

}


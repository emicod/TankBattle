#include "mainpage.h"
#include "ui_mainpage.h"
#include <QPainter>
#include <QPixmap>

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->move(300, 100);
    this->setWindowTitle("坦克大战");
    ui->buttonStart->setFont(QFont("微软雅黑", 20, 700));
    ui->buttonStart->setStyleSheet("color:red");
    ui->buttonExit->setFont(QFont("微软雅黑", 20, 700));
    ui->buttonExit->setStyleSheet("color:red");
    ui->buttonStart->setFlat(true);
    ui->buttonExit->setFlat(true);

    connect(ui->buttonStart, &QPushButton::clicked, this, &MainPage::slot);
    connect(ui->buttonExit, &QPushButton::clicked, this, &MainPage::close);
    connect(&battlePage, &BattlePage::escape, this, &MainPage::slot2);

}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("../Image/mainpage.png"));
}

void MainPage::keyPressEvent(QKeyEvent *event)
{
    //按E进入游戏
    if(event->key() == Qt::Key_E || event->key() == Qt::Key_Enter){
        this->close();
        battlePage.show();
    }
    //esc退出游戏
    else if(event->key() == Qt::Key_Escape)
        this->close();
    else
        return;
}

void MainPage::slot()
{
    this->close();
    battlePage.show();
}

void MainPage::slot2()
{
    this->show();
    battlePage.close();
}

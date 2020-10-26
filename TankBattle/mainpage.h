#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "battlepage.h"
#include <QMainWindow>
#include <QPaintEvent>
#include <QKeyEvent>

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    BattlePage battlePage;

private slots:
    void slot();
    void slot2();

private:
    Ui::MainPage *ui;
};

#endif // MAINPAGE_H

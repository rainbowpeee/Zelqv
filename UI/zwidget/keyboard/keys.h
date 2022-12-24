#ifndef KEYS_H
#define KEYS_H

#include <QWidget>
#include <QToolButton>
#include <QKeyEvent>
#include <QPropertyAnimation>
#include <QApplication>
#include <QPainter>
#include <QDebug>

class Keys : public QToolButton
{
    Q_OBJECT
public:
    explicit Keys(QWidget *parent = nullptr);


    void isClicked();

    /**
     * @brief popUp popIn   弹出/探入
     * @param x             x方向移动距离
     * @param y             y方向移动距离
     * @param msecs         动画间隔
     */
    void popUp(int x = 0, int y = 2, int msecs = 200);
    void popIn(int x = 0, int y = 2, int msecs = 200);

protected:
//   virtual void paintEvent(QPaintEvent *event) override;
signals:
    void capsLk();
    void enter();
};

#endif // KEYS_H

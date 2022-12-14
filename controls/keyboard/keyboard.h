#ifndef KEYBOARD
#define KEYBOARD

#include <QWidget>
#include <QPainter>
#include "keys.h"
#include <QPainterPath> //板端不加这个头文件会报错
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Keyboard; }
QT_END_NAMESPACE

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

    /**
     * @brief init  初始化
     */
    void init();


    /**
     * @brief converUpLow   大小写字母转换
     */
    void converUpLow();

    /**
     * @brief popUp popIn   弹出/探入
     * @param x             x方向移动距离
     * @param y             y方向移动距离
     * @param msecs         动画间隔
     */
    void popUp(int x = 0, int y = 400, int msecs = 200);
    void popIn(int x = 0, int y = 400, int msecs = 200);

    bool state();
    bool popUpState();
    bool popInState();

signals:
    void enterSig();    //回车键信号

    void popUpSig();    //开始弹出信号
    void popInSig();    //开始弹入信号

protected:
    virtual void paintEvent(QPaintEvent *event) override;

    virtual void timerEvent(QTimerEvent *event) override;

private:
    Ui::Keyboard *ui;

    bool m_state = false;       //是否隐藏状态
    bool m_popUpState = false;  //弹出中的状态
    bool m_popInState = false;  //弹入中的状态

    QTimer *m_popUptimer = nullptr; //弹出计时器
    int m_uptimerID = -1;
    QTimer *m_popIntimer = nullptr; //弹入计时器
    int m_intimerID = -1;

    bool m_letterState = false; //小写

};
#endif // KEYBOARD

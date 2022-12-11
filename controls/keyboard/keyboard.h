#ifndef KEYBOARD
#define KEYBOARD

#include <QWidget>
#include <QPainter>
#include <QGridLayout>
#include "keys.h"
#include <QPainterPath> //板端不加这个头文件会报错

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

signals:
    void enterSig();    //回车键信号

protected:
    virtual void paintEvent(QPaintEvent *event) override;


private:
    Ui::Keyboard *ui;

    bool m_state = false; //隐藏
    bool m_letterState = false; //小写

    QGridLayout *gridLayout = nullptr;


//    char letter[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

//    int m_parentWidth;
//    int m_parentHeight;

};
#endif // KEYBOARD

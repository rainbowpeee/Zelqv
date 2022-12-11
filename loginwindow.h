#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>
#include "controls/keyboard/keyboard.h"
#include <QValidator>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

    bool m_state = false;

protected:
    /**
     * @brief timerEvent    定时器事件，循环检测用户名和密码是否正确
     * @param event
     */
    virtual void timerEvent(QTimerEvent *event) override;

    /**
     * @brief eventFilter   事件过滤器，用于键盘的弹入与弹回
     * @param watched
     * @param event
     * @return
     */
    virtual bool eventFilter(QObject *watched, QEvent *event) override;

private:
    void init();

private:
    Ui::LoginWindow *ui;

    int m_timerID = -1;

    Keyboard *m_keyboard;

};

#endif // LOGINWINDOW_H

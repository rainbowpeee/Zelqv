#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDebug>

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
    void timerEvent(QTimerEvent *event);


private:
    Ui::LoginWindow *ui;

    int m_timerID = -1;

};

#endif // LOGINWINDOW_H

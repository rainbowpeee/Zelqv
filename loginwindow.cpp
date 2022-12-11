#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    m_timerID = startTimer(100);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_timerID && ui->lineEdit_2->text()== "123456")
    {
        qDebug()<<"Correct";
        m_state = true;
        killTimer(m_timerID);
    }
}

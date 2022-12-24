#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    init();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == m_pWTimerID && m_parentWidget != nullptr)
    {
        qDebug()<<m_parentWidget->width()<<m_parentWidget->height();
        this->setGeometry(0, 0, m_parentWidget->width(), m_parentWidget->height());
    }

    if(event->timerId() == m_leTimerID && ui->passwordLineEdit->text()== "123456")
    {
        qDebug()<<"Correct";
        m_state = true;
        killTimer(m_leTimerID);
    }
}

bool LoginWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == this && event->type() == QEvent::MouseButtonPress)
    {
        this->setFocus();
        if(m_keyboard->state())
        {
            m_keyboard->popIn(0, this->height()/3);
        }
    }
    else if(watched == ui->userNameLineEdit && event->type() == QEvent::MouseButtonPress)
    {
        ui->userNameLineEdit->setFocus();
        if(!m_keyboard->state())
        {
            m_keyboard->popUp(0, this->height()/3);
        }
    }
    else if (watched == ui->passwordLineEdit && event->type() == QEvent::MouseButtonPress)
    {
        ui->passwordLineEdit->setFocus();
        if(!m_keyboard->state())    //隐藏->弹出
        {
            m_keyboard->popUp(0, this->height()/3);
        }
    }

    return QWidget::eventFilter(watched, event);
}

void LoginWindow::init()
{
    m_parentWidget = new QWidget;
    m_parentWidget = parentWidget();

    this->installEventFilter(this);

    QRegExp regx("[a-zA-Z0-9]+$");

    QValidator *validator0 = new QRegExpValidator(regx, ui->userNameLineEdit);
    ui->userNameLineEdit->setValidator(validator0);
    ui->userNameLineEdit->setMaxLength(15);
    ui->userNameLineEdit->installEventFilter(this);

    QValidator *validator1 = new QRegExpValidator(regx, ui->passwordLineEdit);
    ui->passwordLineEdit->setValidator(validator1);
    ui->passwordLineEdit->setMaxLength(15);
    ui->passwordLineEdit->installEventFilter(this);

    m_keyboard = new Keyboard(this);

    m_pWTimerID = startTimer(20);
    m_leTimerID = startTimer(100);
}

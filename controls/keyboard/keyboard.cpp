#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    init();

    connect(m_popUptimer, &QTimer::timeout, [=]()
    {
        m_popUptimer->stop();
        m_popUpState = false;   //弹出完成
    });
    connect(m_popIntimer, &QTimer::timeout, [=]()
    {
        m_popIntimer->stop();
        m_popInState = false;   //弹入完成
    });
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::init()
{
    setMinimumSize(QSize(430,130));

    QWidget *parentW = parentWidget();
    if(parentW)
    {
        int parentWidth = parentW->width();
        int parentHeight = parentW->height();

        int positionX = 0;
        int positionY = parentHeight;

        setGeometry(positionX, positionY, parentWidth, parentHeight/3);
    }

    connect(ui->toolButton_Enter, &Keys::enter, this, [=](){emit enterSig();});
    connect(ui->toolButton_CapsLk, &Keys::capsLk, this, &Keyboard::converUpLow);

    m_popUptimer = new QTimer(this);
    m_popIntimer = new QTimer(this);

    setWindowFlags(Qt::FramelessWindowHint);
}

void Keyboard::converUpLow()
{
    if(!m_letterState)
    {
        ui->toolButton_a->setText("A");
        ui->toolButton_b->setText("B");
        ui->toolButton_c->setText("C");
        ui->toolButton_d->setText("D");
        ui->toolButton_e->setText("E");
        ui->toolButton_f->setText("F");
        ui->toolButton_g->setText("G");
        ui->toolButton_h->setText("H");
        ui->toolButton_i->setText("I");
        ui->toolButton_j->setText("J");
        ui->toolButton_k->setText("K");
        ui->toolButton_l->setText("L");
        ui->toolButton_m->setText("M");
        ui->toolButton_n->setText("N");
        ui->toolButton_o->setText("O");
        ui->toolButton_p->setText("P");
        ui->toolButton_q->setText("Q");
        ui->toolButton_r->setText("R");
        ui->toolButton_s->setText("S");
        ui->toolButton_t->setText("T");
        ui->toolButton_u->setText("U");
        ui->toolButton_v->setText("V");
        ui->toolButton_w->setText("W");
        ui->toolButton_x->setText("X");
        ui->toolButton_y->setText("Y");
        ui->toolButton_z->setText("Z");
        m_letterState = !m_letterState;
    }
    else
    {
        ui->toolButton_a->setText("a");
        ui->toolButton_b->setText("b");
        ui->toolButton_c->setText("c");
        ui->toolButton_d->setText("d");
        ui->toolButton_e->setText("e");
        ui->toolButton_f->setText("f");
        ui->toolButton_g->setText("g");
        ui->toolButton_h->setText("h");
        ui->toolButton_i->setText("i");
        ui->toolButton_j->setText("j");
        ui->toolButton_k->setText("k");
        ui->toolButton_l->setText("l");
        ui->toolButton_m->setText("m");
        ui->toolButton_n->setText("n");
        ui->toolButton_o->setText("o");
        ui->toolButton_p->setText("p");
        ui->toolButton_q->setText("q");
        ui->toolButton_r->setText("r");
        ui->toolButton_s->setText("s");
        ui->toolButton_t->setText("t");
        ui->toolButton_u->setText("u");
        ui->toolButton_v->setText("v");
        ui->toolButton_w->setText("w");
        ui->toolButton_x->setText("x");
        ui->toolButton_y->setText("y");
        ui->toolButton_z->setText("z");
        m_letterState = !m_letterState;
    }
}

void Keyboard::popUp(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x()+x, this->y()-y, this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutQuint);
    animation->start();
    m_popUpState = true;        //弹出中
    m_popUptimer->start(msecs); //弹出中计时
    emit popUpSig();
    m_state = !m_state;
}

void Keyboard::popIn(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x()+x, this->y()+y, this->width(), this->height()));
    animation->setEasingCurve(QEasingCurve::OutQuint);
    animation->start();
    m_popInState = true;        //弹入中
    m_popIntimer->start(msecs); //弹入中计时
    emit popInSig();
    m_state = !m_state;
}

bool Keyboard::state()
{
    return m_state;
}

bool Keyboard::popUpState()
{
    return m_popUpState;
}

bool Keyboard::popInState()
{
    return m_popInState;
}

void Keyboard::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  //抗锯齿
    painter.setBrush(Qt::black);                   //设置画刷

    /*绘制背景*/
    QPainterPath path;
    path.addRoundedRect(QRectF(0, 0, width(), height()) , 5, 5);
    painter.drawPath(path.simplified());
}



#include "keys.h"

Keys::Keys(QWidget *parent) : QToolButton(parent)
{
    connect(this, &QToolButton::clicked, this, &Keys::isClicked);
}

void Keys::isClicked()
{
    if(this->text() == "<-")
    {
        popUp();
        popIn();
        //定义一个事件，Key_Backspace撤消按钮
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress, Qt::Key_Backspace, Qt::NoModifier, this->text());
        //通过postEvent将事件key发送出去给QApplication::focusWidget()，
        //在当前窗口界面中有焦点的控件
        QApplication::postEvent(QApplication::focusWidget(), key);
    }
    else if(this->text() == "Enter")
    {
        emit enter();
        popUp();
        popIn();
        qDebug()<<"Enter";
    }
    else if(this->text() == "")
    {
        popUp();
        popIn();
        qDebug()<<"Space";
    }
    else if(this->text() == "^")
    {
        emit capsLk();
        popUp();
        popIn();
        qDebug()<<"CapsLk";
    }
    else if (this->text() == "En/Ch")
    {
        popUp();
        popIn();
        qDebug()<<"En/Ch";
    }
    else
    {
        popUp();
        popIn();
        QKeyEvent* key = new QKeyEvent(QEvent::KeyPress,'z', Qt::NoModifier, this->text());
        //通过postEvent将事件key的文本内容发送出去，QApplication::focusWidget()当前窗口中，有光标的
        //控件上
        QApplication::postEvent(QApplication::focusWidget(), key);
    }
}

void Keys::popUp(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");  //创建动画对象;
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x()+x, this->y()+y, this->width(), this->height()));  //设置结束起始位置
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void Keys::popIn(int x, int y, int msecs)
{
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");  //创建动画对象;
    animation->setDuration(msecs);
    animation->setStartValue(QRect(this->x()+x, this->y()+y, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));  //设置结束起始位置
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

//void Keys::paintEvent(QPaintEvent *event)
//{
//    Q_UNUSED(event);
//    QPainter painter;
//    QPixmap pix(this->width(), this->height());

//    painter.begin(&pix);
//    painter.setRenderHint(QPainter::Antialiasing);  //抗锯齿
//    painter.setBrush(QColor(51,51,51));
//    /*绘制背景*/
////    QPainterPath path;  //一个用来画线的类
////    path.addRoundedRect(QRectF(0, 0, width(), height()) , 5, 5);   //QRectF是一个可以接受float型的类似QRect的类
////    painter.drawPath(path.simplified());    //画path设置的线
//    painter.end();

//    painter.begin(this);
//    painter.drawPixmap(0,0,pix);
//}



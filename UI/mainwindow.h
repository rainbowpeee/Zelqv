#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "UI/subpage/subpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUI();


private:
    Ui::MainWindow *ui;

    LoginWindow *m_lgW;
    AdminWindow *m_adW;

};
#endif // MAINWINDOW_H

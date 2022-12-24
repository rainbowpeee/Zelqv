#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <QGridLayout>
#include <QTableView>
#include <QPushButton>
#include <QStandardItemModel>
#include <QHeaderView>

#include <stdio.h>
#include <string>
#include <QtCore>
#include <QSettings>

class AdminWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AdminWindow(QWidget *parent = nullptr);

signals:

protected:
    void initUI();

private:
    bool initProfile();

    void loadUserData();

    void addUserData();

protected:
    QPushButton *m_addBtn = nullptr;
    QTableView *m_tableView = nullptr;
    QStandardItemModel *m_tableModel = nullptr;

private:
    QSettings *m_userProfile = nullptr;
    QString m_filePath = QCoreApplication::applicationDirPath()+"/config/userprofile.ini";

    int m_userCount;
};

#endif // ADMINWINDOW_H

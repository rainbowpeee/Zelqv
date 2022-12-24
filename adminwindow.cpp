#include "adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) : QWidget(parent)
{
    m_addBtn = new QPushButton(this);
    m_tableView = new QTableView(this);
    m_tableModel = new QStandardItemModel(m_tableView);

    initProfile();
    loadUserData();
    initUI();
}

void AdminWindow::initUI()
{
    QFont font;
    font.setFamily(QString::fromUtf8("Century Gothic"));
    font.setPointSize(13);

    m_addBtn->setText("Add");
    m_addBtn->setFont(font);
    connect(m_addBtn, &QPushButton::clicked, this, &AdminWindow::addUserData);

    m_tableModel->setColumnCount(3);
    m_tableModel->setRowCount(m_userCount);
    m_tableModel->setHeaderData(0, Qt::Horizontal, QString("ID"));
    m_tableModel->setHeaderData(1, Qt::Horizontal, QString("Name"));
    m_tableModel->setHeaderData(2, Qt::Horizontal, QString("Password"));

    m_tableView->verticalHeader()->hide();
    m_tableView->horizontalHeader()->setFont(font);
    m_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_tableView->setModel(m_tableModel);

    QGridLayout *gridLayout;
    gridLayout = new QGridLayout(this);
    gridLayout->addWidget(m_tableView, 0, 0, 1, 3);
    gridLayout->addWidget(m_addBtn, 1, 1, 1, 1);
}

bool AdminWindow::initProfile()
{
    const char *filePath = new char;
    filePath = m_filePath.toLatin1().data();
    if(!fopen(filePath, "r"))
    {
        qDebug()<<"Can not find the profile, creating profile...";
    }

    m_userProfile = new QSettings(m_filePath, QSettings::IniFormat);
    m_userCount = m_userProfile->childGroups().size();
    return true;
}

void AdminWindow::loadUserData()
{
    m_tableModel->clear();
    m_tableModel->setRowCount(0);
}

void AdminWindow::addUserData()
{
    m_tableModel->setRowCount(m_tableModel->rowCount()+1);
    m_tableModel->setData(m_tableModel->index(m_tableModel->rowCount(),1), "IDaa");
//    m_userProfile->setValue();
}

FORMS += \
    $$PWD/mainwindow.ui \
    $$PWD/subpage/loginwindow.ui

HEADERS += \
    $$PWD/mainwindow.h \
    $$PWD/subpage/adminwindow.h \
    $$PWD/subpage/loginwindow.h \
    $$PWD/subpage/subpage.h

SOURCES += \
    $$PWD/mainwindow.cpp \
    $$PWD/subpage/adminwindow.cpp \
    $$PWD/subpage/loginwindow.cpp


####################### 控件库 #######################
include($$PWD/zwidget/zwidget.pri)



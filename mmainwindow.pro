QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    difficultty.cpp \
    gamescence.cpp \
    gamescence2.cpp \
    main.cpp \
    mainwindow.cpp \
    mypushbutton1.cpp

HEADERS += \
    difficultty.h \
    gamescence.h \
    gamescence2.h \
    mainwindow.h \
    mypushbutton1.h

FORMS += \
    difficultty.ui \
    gamescence.ui \
    gamescence2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc15/lib/ -lopencv_world3410
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc15/lib/ -lopencv_world3410d
else:unix: LIBS += -L$$PWD/../../opencv/build/x64/vc15/lib/ -lopencv_world3410

INCLUDEPATH += $$PWD/../../opencv/build/include
DEPENDPATH += $$PWD/../../opencv/build/include

DISTFILES += \
    ../../opencv/build/x64/vc15/bin/opencv_world3410.dll \
    ../../opencv/build/x64/vc15/bin/opencv_world3410d.dll

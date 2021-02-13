QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authenticate.cpp \
    dbfirestore.cpp \
    main.cpp \
    wfind.cpp \
    wform.cpp \
    wlogin.cpp

HEADERS += \
    authenticate.h \
    dbfirestore.h \
    wfind.h \
    wform.h \
    wlogin.h

FORMS += \
    wfind.ui \
    wform.ui \
    wlogin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Firebase SDK path
FIREBASE_SDK = ../../../Desktop/firebase_cpp_sdk

#include path
INCLUDEPATH += $${FIREBASE_SDK}/include/

LIBS += -F$${FIREBASE_SDK}/frameworks/darwin/x86_64 \
        -framework firebase_auth                    \
        -framework firebase                         \
        -framework firebase_firestore               \
        -framework CoreFoundation                   \
        -framework Security                         \
        -framework Foundation                       \
        -framework GSS                              \
        -framework Kerberos                         \
        -framework SystemConfiguration              \
        -L$${FIREBASE_SDK}/libs/darwin/x86_64

QT       += core gui \
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 \
          release

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    hub.cpp \
    mod_window.cpp \
    crypto_window.cpp \
    level_window.cpp

HEADERS += \
    hub.h \
    mod_window.h \
    crypto_window.h \
    level_window.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \

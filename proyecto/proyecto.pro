QT       += core gui charts

# Directorios de encabezados (include)
INCLUDEPATH += C:/symengine-install/include

# Directorios de bibliotecas (lib)
LIBS += -LC:/symengine-install/lib -lsymengine

# Si SymEngine depende de GMP, incluye también estas líneas:
INCLUDEPATH += C:/gmp/include
LIBS += -LC:/gmp/lib -lgmp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    inputwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    polinomio.cpp

HEADERS += \
    inputwindow.h \
    mainwindow.h \
    polinomio.h

FORMS += \
    inputwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

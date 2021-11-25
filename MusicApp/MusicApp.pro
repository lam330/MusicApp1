QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        audiofile.cpp \
        cppsignalsender.cpp \
        folderlistmodel.cpp \
        main.cpp

RESOURCES += qml.qrc \
    Images.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    audiofile.h \
    cppsignalsender.h \
    folderlistmodel.h

DISTFILES += \
    images/Classic.jpeg \
    images/pexels-barthy-bonhomme-185030.jpg \
    images/pexels-breakingpic-3104.jpg \
    images/pexels-foteros-352505.jpg \
    images/pexels-freestocksorg-14548.jpg \
    images/pexels-jessica-lynn-lewis-1010519.jpg \
    images/pexels-kaboompics-com-6320.jpg \
    images/pexels-pixabay-159376.jpg \
    images/pexels-pixabay-248510.jpg \
    images/pexels-snapwire-6966.jpg \
    images/pexels-stephen-niemeier-63703.jpg

DEFINES += QT_CREATOR_DRPC_LIBRARY

TEMPLATE = lib
CONFIG += plugin C++17
QT += core

TARGET = qtcreator_drpc

QMAKE_CXXFLAGS += /std:c++17

SOURCES += \
    "source/qtcreator_drpc_plugin.cpp"

HEADERS += \
    "source/qtcreator_drpc_plugin.hpp"

# Discord RPC Dependency --------------------------------
INCLUDEPATH += "$$PWD/dependencies/discord-rpc/include/"
DEPENDPATH  += "$$PWD/dependencies/discord-rpc/include/"
LIBS        += -L$$PWD/dependencies/discord-rpc/lib -ldiscord-rpc -ladvapi32

# Qt Plugin Configuration ------------------------------
IDE_SOURCE_TREE = C:/Qt/qt-creator-5.0.3/    # Should point to the Qt Creator repository source code.
IDE_BUILD_TREE  = C:/Qt/Tools/QtCreator/     # Should point to a Qt Creator build containing the required libraries.

QTC_PLUGIN_NAME = QtCreatorDRPC

QTC_PLUGIN_DEPENDS += \
    coreplugin \
    projectexplorer

include($$IDE_SOURCE_TREE/src/qtcreatorplugin.pri)

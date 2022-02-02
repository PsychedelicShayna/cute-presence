#ifndef QTCREATOR_DRPC_PLUGIN_HPP
#define QTCREATOR_DRPC_PLUGIN_HPP

// #if defined(QT_CREATOR_DRPC_LIBRARY)
// #define QT_CREATOR_DRPC_SHARED_EXPORT Q_DECL_EXPORT
// #else
// #define QT_CREATOR_DRPC_SHARED_EXPORT Q_DECL_IMPORT
// #endif

#include <extensionsystem/iplugin.h>

#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <QtWidgets/QAction>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMessageBox>

#include <coreplugin/editormanager/editormanager.h>
#include <coreplugin/editormanager/ieditor.h>

#include <coreplugin/coreconstants.h>

#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>

#include <projectexplorer/projecttree.h>
#include <projectexplorer/project.h>

#include <functional>
#include <iostream>
#include <string>

#include <discord_rpc.h>

namespace QtCreatorDRPC {

constexpr const char* GLOBAL_APPLICATION_ID          { "937400240473006092"         };
constexpr const char* GLOBAL_DRPC_MENU_ID            { "QtCreatorDRPC.Menu"         };
constexpr const char* GLOBAL_DRPC_START_ACTION_ID    { "QtCreatorDRPC.ActionStart" };
constexpr const char* GLOBAL_DRPC_STOP_ACTION_ID     { "QtCreatorDRPC.ActionStop"  };

class QDiscordRichPresence {
public:
    QString State;
    QString Details;
    quint64 StartTimestamp;
    quint64 EndTimestamp;
    QString LargeImageKey;
    QString LargeImageText;
    QString SmallImageKey;
    QString SmallImageText;
    QString PartyId;
    qint32  PartySize;
    qint32  PartyMax;
    QString MatchSecret;
    QString SpectateSecret;
    QString JoinSecret;
    int8_t  Instance;

    void UpdateRichPresence() const;
    QDiscordRichPresence();
};

class Q_DECL_EXPORT QtCreatorDRPCPlugin : public ExtensionSystem::IPlugin {
Q_OBJECT
Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "QtCreatorDRPC.json")

protected:
    struct RichPresenceFileDescriptor {
        QString ImageKey;       // The key of the art asset stored in the rich presence developer portal used for this file.
        QString Description;    // Description of the file type, e.g. C++ Source File, Python Script, QMake Project File, etc...
        QString WorkingVerb;    // Verb used when referring to this file, e.g. editing, designing, configuring.
    };

    // Maps the mime types of files as QStrings, to their respective RichPresenceFileDescriptor.
    static const QMap<QString, RichPresenceFileDescriptor> mimeTypeToRpcFileDescriptorMap;

    class MimeOverrider {
    public:
        static QMap<QString, QList<QPair<QList<QString>, QString>>> MimeOverrideMap;
        static QString OverrideMimeIfApplicable(const QString& mime, const Utils::FilePath& file_path);
    };

    std::time_t drpcInitializedTimestamp;
    void initializeDiscordRichPresence(const char* application_id);

    std::time_t timeSpentOnCurrentEditor;

    QTimer* drpcSyncTimer;

    QList<QMetaObject::Connection> syncSignalConnections;

protected slots:
    void setDrpcNotEditingState();
    void syncDrpcToCurrentEditorState();

    void connectSyncSignals();
    void disconnectSyncSignals();

    void initializeControlMenu();

public:
    virtual bool initialize(const QStringList& arguments, QString* error_string) override;
    virtual void extensionsInitialized() override;
    virtual ShutdownFlag aboutToShutdown() override;

    QtCreatorDRPCPlugin();
    virtual ~QtCreatorDRPCPlugin() override;
};

};

#endif // QTCREATOR_DRPC_PLUGIN_HPP

#ifndef CARPLAYLINKPROXY_H
#define CARPLAYLINKPROXY_H

#include <QtCore/QObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QtDBus/QtDBus>

class LocalDbusServerCarplayInterface: public QDBusAbstractInterface
{
    Q_OBJECT
public:
    static inline const char *staticInterfaceName()
    { return "Local.DbusServer.Carplay"; }

public:
    LocalDbusServerCarplayInterface(const QString &service, const QString &path, const QDBusConnection &connection, QObject *parent = 0);

    ~LocalDbusServerCarplayInterface();

public Q_SLOTS: // METHODS
    inline QDBusPendingReply<> requestLinkStatus(int type, int status)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(type) << qVariantFromValue(status);
        return asyncCallWithArgumentList(QLatin1String("requestLinkStatus"), argumentList);
    }

    inline QDBusPendingReply<> requestTouchStatus(int deviceType, int touchType, const QString &touchPointXml)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(deviceType) << qVariantFromValue(touchType) << qVariantFromValue(touchPointXml);
        return asyncCallWithArgumentList(QLatin1String("requestTouchStatus"), argumentList);
    }

    inline QDBusPendingReply<> requestKeyValue(int type)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(type);
        return asyncCallWithArgumentList(QLatin1String("requestKeyValue"), argumentList);
    }

    inline QDBusPendingReply<> requestWheelStatus(const int deviceType, const int select_pressed, const int wheelStep)
    {
        QList<QVariant> argumentList;
        argumentList << qVariantFromValue(deviceType) << qVariantFromValue(select_pressed) << qVariantFromValue(wheelStep);
        return asyncCallWithArgumentList(QLatin1String("requestWheelStatus"), argumentList);
    }

Q_SIGNALS: // SIGNALS
    void onLinkStatusChange(int type, int status);
    void onTouchStatusChange(int type, int x_src, int y_src, int x_dst, int y_dst);
};

namespace Local {
  namespace DbusServer {
    typedef ::LocalDbusServerCarplayInterface Carplay;
  }
}
#endif

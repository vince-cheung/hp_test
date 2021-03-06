#ifndef USBDISKWIDGET_H
#define USBDISKWIDGET_H

#include "BusinessLogic/Widget.h"
#include "BusinessLogic/Multimedia.h"
#include <QWidget>
#include <QScopedPointer>

class USBDiskWidgetPrivate;
class USBDiskWidget
        : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(USBDiskWidget)
public:
    explicit USBDiskWidget(QWidget *parent = NULL);
    ~USBDiskWidget();
protected:
    void resizeEvent(QResizeEvent* event);
protected slots:
    void onWidgetTypeChange(const Widget::Type destinationType, const Widget::Type requestType, const QString &status);
    void onDeviceWatcherStatus(const int type, const int status);
    void onMusicPlayerFileNames(const int type, const QString &xml);
    void onMusicPlayerID3TagChange(const int type,
                                   const int index,
                                   const QString &fileName,
                                   const QString& title,
                                   const QString& artist,
                                   const QString& album,
                                   const int endTime);
    void onImagePlayerFileNames(const int type, const QString &xml);
    void onImagePlayerChange(const int type, const QString &filePath, const int index, const int percent, const int rotate);
    void onVideoPlayerFileNames(const int type, const QString& xml);
    void onVideoPlayerInformation(const int type, const int index, const QString &fileName, const int endTime);
private slots:
    void onTimeout();
private:
    friend class USBDiskWidgetPrivate;
    QScopedPointer<USBDiskWidgetPrivate> m_Private;
};

#endif // USBDISKWIDGET_H

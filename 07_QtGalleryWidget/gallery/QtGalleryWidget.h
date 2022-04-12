#ifndef QTGALLERYWIDGET_H
#define QTGALLERYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QDebug>
#include <QScrollArea>
#include <QPropertyAnimation>
#include <QScrollBar>
#include "QtGalleryPhotoWidget.h"

class QtGalleryWidget : public QScrollArea
{
    Q_OBJECT
public:
    QtGalleryWidget(QWidget *parent = nullptr);

    void loadData(QList<QtGalleryPhotoData> list);
    void resizeGallery(QPoint emit_pos = QPoint(0, 0));
    void startAnimation();

protected:
    void resizeEvent(QResizeEvent *event) override;

signals:
    void signalPictureClicked(QtGalleryPhotoWidget* bean);

public slots:

public:
    static int item_spacing_h;
    static int item_spacing_v;

private:
    QList<QtGalleryPhotoWidget*> widgets;
    QWidget* center_widget;
};

#endif // QTGALLERYWIDGET_H

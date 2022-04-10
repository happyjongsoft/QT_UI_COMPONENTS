#ifndef QTSCROLLLABEL_H
#define QTSCROLLLABEL_H

#include <QLabel>
#include <QBasicTimer>
#include <QTimerEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>

class QtScrollLabel : public QLabel
{
    Q_OBJECT
public:
    enum ScrollDirection{
        RightToLeft=1,
        LeftToRight=2
    };
public:
    explicit QtScrollLabel(QWidget *parent = nullptr);

    QtScrollLabel::ScrollDirection getDirection() const;
    void setDirection(QtScrollLabel::ScrollDirection direction);

    int getInterval() const;
    void setInterval(int interval);

protected:
    void timerEvent(QTimerEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QBasicTimer scrollTimer;
    int interval=20;

    int offset=0;
    int textWidth=0;
    int labelWidth=0;

    ScrollDirection direction=RightToLeft;
};

#endif // SCROLLLABEL_H

#include "QtScrollLabel.h"

QtScrollLabel::QtScrollLabel(QWidget *parent)
    : QLabel(parent)
{
    scrollTimer.start(interval,this);
}

QtScrollLabel::ScrollDirection QtScrollLabel::getDirection() const
{
    return direction;
}

void QtScrollLabel::setDirection(QtScrollLabel::ScrollDirection direction)
{
    if(this->direction!=direction){
        this->direction=direction;
        offset=0;
    }
}

int QtScrollLabel::getInterval() const
{
    return interval;
}

void QtScrollLabel::setInterval(int interval)
{
    if(this->interval!=interval){
        this->interval=interval;
        scrollTimer.start(interval,this);
    }
}

void QtScrollLabel::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==scrollTimer.timerId()){
        event->accept();
        ++offset;
        if(offset>textWidth+labelWidth){
            offset=0;
        }
        update();
    }else{
        QLabel::timerEvent(event);
    }
}

void QtScrollLabel::paintEvent(QPaintEvent *event)
{
    event->accept();

    QPainter painter(this);
    const int text_width = painter.fontMetrics().width(text());
    const int text_height = painter.fontMetrics().height();
    const int text_y = (height()+text_height) / 2-painter.fontMetrics().descent();
    if (textWidth != text_width && text_width > 0) {
        textWidth = text_width;
        offset = 0;
    }else {
        if(direction==RightToLeft){
            painter.drawText(labelWidth - offset, text_y, text());
        }else{
            painter.drawText(offset - textWidth, text_y, text());
        }
    }
}

void QtScrollLabel::resizeEvent(QResizeEvent *event)
{
    const int old_width = event->oldSize().width();
    const int new_width = event->size().width();
    if (new_width > 10) {
        labelWidth = new_width;
        if (new_width < old_width) {
            offset = 0;
        }
    }
    QLabel::resizeEvent(event);
}

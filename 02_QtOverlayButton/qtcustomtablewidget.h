#ifndef QTCUSTOMTABLEWIDGET_H
#define QTCUSTOMTABLEWIDGET_H

#include <QObject>
#include <QTableWidget>
#include <QPushButton>

class QtCustomTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    QtCustomTableWidget(QWidget* parent = nullptr);


    void resizeEvent(QResizeEvent *event);

public slots:
    void onClickedDetails();

signals:
    void clickedDetails();

private:
    QPushButton*    m_btnDetails;
};

#endif // QTCUSTOMTABLEWIDGET_H

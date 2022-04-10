#include "qtcustomtablewidget.h"

QtCustomTableWidget::QtCustomTableWidget(QWidget* parent)
{
    m_btnDetails = new QPushButton(this);
    m_btnDetails->setText("Settings");

    connect(m_btnDetails, &QPushButton::released, this, &QtCustomTableWidget::onClickedDetails);
}

void QtCustomTableWidget::resizeEvent(QResizeEvent *event)
{
    m_btnDetails->setGeometry(width() - 110, 10, 100, 30);
}

void QtCustomTableWidget::onClickedDetails()
{
    emit clickedDetails();
}

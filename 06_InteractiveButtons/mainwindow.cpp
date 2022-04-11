#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QScreen* desktop = QApplication::screenAt(QCursor::pos());
    QRect rect = desktop->availableGeometry();
    move(rect.left()+(rect.width() - width())/2, (rect.height() - height())/2);

    setMouseTracking(true);

    QVBoxLayout *vlayout = new QVBoxLayout;
    QWidget *widget = new QWidget();
    widget->setLayout(vlayout);
    setCentralWidget(widget);

    QWidget *hWidget = new QWidget();
    QHBoxLayout *hlayout = new QHBoxLayout;
    hWidget->setLayout(hlayout);
    vlayout->addWidget(hWidget);

    AppendButton* append_btn = new AppendButton(this);
    append_btn->setMinimumSize(32, 32);
    append_btn->setMaximumSize(32, 32);
    hlayout->addWidget(append_btn);

    InfoButton* info_btn = new InfoButton(this);
    info_btn->setMinimumSize(32, 32);
    info_btn->setMaximumSize(32, 32);
    hlayout->addWidget(info_btn);

    WinMenuButton* menu_btn = new WinMenuButton(this);
    menu_btn->setMinimumSize(32, 32);
    menu_btn->setMaximumSize(32, 32);
    hlayout->addWidget(menu_btn);

    WinMinButton *min_btn = new WinMinButton(this);
    min_btn->setMinimumSize(32, 32);
    min_btn->setMaximumSize(32, 32);
    hlayout->addWidget(min_btn);

    WinMaxButton *max_btn = new WinMaxButton(this);
    max_btn->setMinimumSize(32, 32);
    max_btn->setMaximumSize(32, 32);
    hlayout->addWidget(max_btn);

    WinRestoreButton* res_btn = new WinRestoreButton(this);
    res_btn->setMinimumSize(32, 32);
    res_btn->setMaximumSize(32, 32);
    hlayout->addWidget(res_btn);

    WinCloseButton* close_btn = new WinCloseButton(this);
    close_btn->setMinimumSize(32, 32);
    close_btn->setMaximumSize(32, 32);
    close_btn->setBgColor(Qt::black, Qt::red);
    hlayout->addWidget(close_btn);

    InteractiveButtonBase* btn = new InteractiveButtonBase("WELCOME");
    btn->setMinimumSize(100, 32);
    btn->setMaximumSize(100, 32);
    btn->setBgColor(QColor(255, 0, 0));
    btn->setRadius(5);
    vlayout->addWidget(btn);

    InteractiveButtonBase* btn0 = new InteractiveButtonBase(this);
    btn0->setMinimumSize(100, 32);
    btn0->setMaximumSize(100, 32);
    btn0->setIcon(QIcon(":/icons/point_menu"));
    vlayout->addWidget(btn0);

    InteractiveButtonBase* text_btn = new InteractiveButtonBase("WELCOME", this);
    text_btn->setMinimumSize(100, 32);
    text_btn->setMaximumSize(100, 32);
    text_btn->setHoverAniDuration(5000);
    vlayout->addWidget(text_btn);

    ThreeDimenButton* tdb = new ThreeDimenButton(this);
    tdb->setMinimumSize(100, 32);
    tdb->setMaximumSize(100, 32);
    tdb->setBgColor(Qt::gray);
    tdb->setStyleSheet("qproperty-text: WELCOME; color: red;");
    connect(tdb, &ThreeDimenButton::clicked, [=]{ qDebug() << "3D按钮clicked"; });
    connect(tdb, &ThreeDimenButton::signalMouseEnter, [=]{ qDebug() << "mouseEnter"; });
    connect(tdb, &ThreeDimenButton::signalMouseLeave, [=]{ qDebug() << "mouseLeave"; });
    connect(tdb, &ThreeDimenButton::signalMouseEnterLater, [=]{ qDebug() << "mouseEnterLater"; });
    connect(tdb, &ThreeDimenButton::signalMouseLeaveLater, [=]{ qDebug() << "mouseLeaveLater"; });
    connect(tdb, &ThreeDimenButton::signalMousePress, [=](QMouseEvent*){ qDebug() << "mousePress"; });
    connect(tdb, &ThreeDimenButton::signalMouseRelease, [=](QMouseEvent*){ qDebug() << "mouseRelease"; });
    connect(tdb, &ThreeDimenButton::signalMousePressLater, [=](QMouseEvent*){ qDebug() << "mousePressLater"; });
    connect(tdb, &ThreeDimenButton::signalMouseReleaseLater, [=](QMouseEvent*){ qDebug() << "mouseReleaseLater"; });
    vlayout->addWidget(tdb);

    WaterZoomButton* zoom_btn1 = new WaterZoomButton("WELCOME", this);
    zoom_btn1->setMinimumSize(100, 32);
    zoom_btn1->setMaximumSize(100, 32);
    zoom_btn1->setBgColor(QColor(240,128,128));
    zoom_btn1->setBgColor(Qt::transparent, QColor(0x88, 0x88, 0x88, 0x64));
    zoom_btn1->setRadius(10, 5);
    zoom_btn1->setChokingProp(0.18);
    vlayout->addWidget(zoom_btn1);

    InteractiveButtonBase* icon_text_btn = new InteractiveButtonBase(QIcon(":/icons/point_menu"), "WELCOME", this);
    icon_text_btn->setMinimumSize(100, 32);
    icon_text_btn->setMaximumSize(100, 32);
    vlayout->addWidget(icon_text_btn);

    InteractiveButtonBase* float_btn = new WaterFloatButton("WELCOME", this);
    float_btn->setMinimumSize(100, 32);
    float_btn->setMaximumSize(100, 32);
    float_btn->setBgColor(QColor(102,51,204,192), QColor(102,51,204,255));
    float_btn->setIconColor(QColor(102,51,204,192));
    float_btn->setStyleSheet("qproperty-text: WELCOME; qproperty-water_animation: true; ");
    vlayout->addWidget(float_btn);

    InteractiveButtonBase* par_btn = new InteractiveButtonBase("WELCOME", this);
    par_btn->setMinimumSize(100, 32);
    par_btn->setMaximumSize(100, 32);
    par_btn->setParentEnabled(true);
    par_btn->setForeEnabled(false);
    par_btn->setStyleSheet("qproperty-text: WELCOME; color: red; qproperty-press_color: green;");
    vlayout->addWidget(par_btn);

    PointMenuButton* pm_btn = new PointMenuButton(this);
    pm_btn->setMinimumSize(100, 32);
    pm_btn->setMaximumSize(100, 32);
    pm_btn->setStyleSheet("qproperty-background_color: red; qproperty-radius: 20; qproperty-border_color: green; qproperty-border_width:3;"
                          "qproperty-icon_color: blue; ");
    vlayout->addWidget(pm_btn);
}

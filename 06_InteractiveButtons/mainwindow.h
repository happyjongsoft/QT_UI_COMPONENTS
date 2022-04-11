#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QDesktopWidget>
#include <QScreen>
#include <QHBoxLayout>
#include <QSpacerItem>

#include "interactivebuttonbase.h"
#include "winminbutton.h"
#include "winmaxbutton.h"
#include "winrestorebutton.h"
#include "winclosebutton.h"
#include "winmenubutton.h"
#include "watercirclebutton.h"
#include "waterfloatbutton.h"
#include "pointmenubutton.h"
#include "threedimenbutton.h"
#include "waterzoombutton.h"
#include "appendbutton.h"
#include "infobutton.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
};

#endif // MAINWINDOW_H

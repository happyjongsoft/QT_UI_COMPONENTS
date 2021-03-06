#ifndef FACILEMENU_H
#define FACILEMENU_H

#include <QObject>
#include <QDialog>
#include <functional>
#include <QRegularExpression>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QScreen>
#include <QGraphicsDropShadowEffect>
#include <QMenu>
#include <QAction>
#include "facilemenuitem.h"

#define DEFAULT_MENU_BLUR_ALPHA 33

typedef std::function<void(int index, bool state)> const FuncCheckType;

class FacileMenu : public QWidget
{
    Q_OBJECT
public:
    FacileMenu(QWidget *parent = nullptr);
    ~FacileMenu() override;

    FacileMenuItem* addAction(QIcon icon, QString text, FuncType clicked = nullptr);
    FacileMenuItem* addAction(QIcon icon, FuncType clicked = nullptr);
    FacileMenuItem* addAction(QString text, FuncType clicked = nullptr);
    FacileMenuItem* addAction(QAction* action, bool deleteWithMenu = false);
    FacileMenuItem* addAction(QIcon icon, QString text, void (*func)());
    template <class T>
    FacileMenuItem* addAction(QIcon icon, QString text, T *obj, void (T::*func)());
    FacileMenu* addNumberedActions(QString pattern, int numberStart, int numberEnd, FuncItemType config = nullptr, FuncIntType clicked = nullptr);
    FacileMenu* addNumberedActions(QString pattern, int numberStart, int numberEnd, FuncItemIntType config, FuncIntType clicked = nullptr);
    FacileMenu* addActions(QList<QAction*> actions);

    FacileMenu* addRow(FuncType addActions = []{});
    FacileMenu* beginRow();
    FacileMenu* endRow();
    QVBoxLayout* createNextColumn();
    QBoxLayout* currentLayout() const;

    FacileMenu* addMenu(QIcon icon, QString text, FuncType clicked = nullptr);
    FacileMenu* addMenu(QString text, FuncType clicked = nullptr);
    FacileMenu* addMenu(QMenu* menu);
    FacileMenuItem* parentAction();
    FacileMenuItem* lastAction();
    FacileMenuItem* currentAction();

    FacileMenu* addLayout(QLayout *layout, int stretch = 0);
    FacileMenu* addLayoutItem(QLayoutItem *item);
    FacileMenu* addSpacerItem(QSpacerItem *spacerItem);
    FacileMenu* addSpacing(int size);
    FacileMenu* addStretch(int stretch = 0);
    FacileMenu* addStrut(int size);
    FacileMenu* addWidget(QWidget *widget, int stretch = 0, Qt::Alignment alignment = Qt::Alignment());
    FacileMenu* setSpacing(int spacing);
    FacileMenu* setStretchFactor(QWidget *widget, int stretch);
    FacileMenu* setStretchFactor(QLayout *layout, int stretch);

    FacileMenuItem* addSeparator();
    FacileMenu* split();
    FacileMenuItem* lastAddedItem();

    int indexOf(FacileMenuItem* item);
    FacileMenuItem* at(int index);

    void exec(QPoint pos = QPoint(-1, -1));
    void exec(QRect expt, bool vertical = false, QPoint pos = QPoint(-1, -1));
    void execute();
    void toHide(int focusIndex = -1);
    FacileMenu* finished(FuncType func);

    FacileMenu* addOptions(QList<QString>texts, QList<bool>states, FuncIntType clicked);
    FacileMenu* addOptions(QList<QString>texts, int select, FuncIntType clicked);
    FacileMenu* singleCheck(FacileMenuItem* item);
    FacileMenu* uncheckAll(FacileMenuItem* except = nullptr, int begin = -1, int end = -1);
    QList<FacileMenuItem*> checkedItems();
    QList<int> checkedIndexes();
    QStringList checkedItemTexts();
    QList<QVariant> checkedItemDatas();
    FacileMenu* setSingleCheck(FuncCheckType clicked = nullptr);
    FacileMenu* setMultiCheck(FuncCheckType clicked = nullptr);

    FacileMenu* setTipArea(int x = 48);
    FacileMenu* setTipArea(QString longestTip);
    FacileMenu* setSplitInRow(bool split = true);

signals:
    void signalActionTriggered(FacileMenuItem* action);
    void signalHidden(); // ?????????????????????

private slots:
    void itemMouseEntered(FacileMenuItem* item);

protected:
    FacileMenu(bool sub, QWidget* parent = nullptr);
    FacileMenuItem* createMenuItem(QIcon icon, QString text);
    Qt::Key getShortcutByText(QString text) const;
    void setActionButton(InteractiveButtonBase* btn, bool isChip = false);
    void showSubMenu(FacileMenuItem* item);
    bool isCursorInArea(QPoint pos, FacileMenu* child = nullptr);
    void setKeyBoardUsed(bool use = true);
    bool isSubMenu() const;
    FacileMenuItem* addVSeparator();
    void startAnimationOnShowed();
    void startAnimationOnHidden(int focusIndex);

    void hideEvent(QHideEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void paintEvent(QPaintEvent *event) override;

public:
    static void setColors(QColor normal, QColor hover, QColor press, QColor text);
    static QColor normal_bg; // ???????????????????????????????????????????????????
    static QColor hover_bg;  // ????????????
    static QColor press_bg;  // ????????????
    static QColor text_fg;   // ??????/??????????????????
    bool hidden_by_another = false; // ?????????????????????????????????????????????????????????????????????????????????
    static int blur_bg_alpha; // ????????????????????????0?????????1~100??????????????????

private:
    QList<FacileMenuItem*> items;
    QList<FacileMenuItem*> v_separators, h_separators;
    QList<QWidget*> other_widgets; // ???????????????widget
    QHBoxLayout* main_hlayout;
    QVBoxLayout* main_vlayout;
    QList<QHBoxLayout*> row_hlayouts;
    QList<QAction*> import_actions;
    QPixmap bg_pixmap;

    FacileMenu* current_sub_menu = nullptr; // ?????????????????????????????????????????????
    FacileMenu* parent_menu = nullptr; // ??????????????????
    FacileMenuItem* last_added_item = nullptr; // ???????????????item
    FuncType* finished_func = nullptr;

    int addin_tip_area = 0; // ???????????????????????????????????????
    bool adding_horizone = false; // ??????????????????????????????
    bool align_mid_if_alone = false; // ?????????????????????????????????icon???text
    bool _showing_animation = false;
    int current_index = -1; // ????????????
    bool using_keyboard = false; // ????????????????????????????????????
    bool split_in_row = false; // ????????????????????????????????????
    QRect window_rect;
    int window_height = 0; // ??????????????????????????????????????????
};

#endif // FACILEMENU_H

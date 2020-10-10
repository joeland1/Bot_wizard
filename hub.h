#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QToolBar>
#include <QCheckBox>

#include "mod_window.h"
#include "crypto_window.h"
#include "level_window.h"

class Hub : public QMainWindow {

  Q_OBJECT

  public:
    Hub(QWidget *parent = nullptr);

  private slots:
    void enable_widget(int state, QAction *desire);

  private:
    QStackedWidget *stackedWidget;
    QToolBar *toolbar;

    QWidget *token_widget;
    QWidget *home_widget;
    Mod_window *mod_widget;
    Crypto_window *crypto_widget;
    Level_window *level_widget;
};

#include <QMenuBar>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QWidget>
#include <QStackedWidget>
#include <QToolBar>
#include <QLineEdit>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

#include "hub.h"

Hub::Hub(QWidget *parent): QMainWindow(parent)
{
  home_widget = new QWidget;
  mod_widget = new Mod_window;
  crypto_widget = new Crypto_window;
  level_widget = new Level_window;

  token_widget = new QWidget;
  QLineEdit *token = new QLineEdit("");
  token->setEchoMode(QLineEdit::Password);
  QVBoxLayout *token_tab_layout = new QVBoxLayout;
  token_tab_layout -> addWidget(token);
  token_widget -> setLayout(token_tab_layout);

  stackedWidget = new QStackedWidget(this);
    stackedWidget->addWidget(home_widget);
    stackedWidget->addWidget(mod_widget);
    stackedWidget->addWidget(crypto_widget);
    stackedWidget->addWidget(level_widget);
    stackedWidget->addWidget(token_widget);

  QAction *reset = new QAction("&Reset", this);
  QAction *export_ = new QAction("&Save", this);
    connect(export_, &QAction::triggered, this, &Hub::create_file);
    export_->setShortcut(tr("CTRL+S"));
  QAction *quit = new QAction("&Quit", this);
    connect(quit, &QAction::triggered, qApp, QApplication::quit);
    quit->setShortcut(tr("CTRL+Q"));

  //QMenu file;
  QMenu *file = menuBar()->addMenu("&File");
    file->addAction(reset);
    file->addAction(export_);
    file->addSeparator();
    file->addAction(quit);

   toolbar = addToolBar("main toolbar");
    addToolBar(Qt::LeftToolBarArea, toolbar);

  QAction *tool_bar_home = new QAction("&Home");
    toolbar->addAction(tool_bar_home);
    connect(tool_bar_home, &QAction::triggered, this,[this]{stackedWidget->setCurrentWidget(home_widget);});

  QAction *tool_bar_token = new QAction("&Token");
    toolbar->addAction(tool_bar_token);
    connect(tool_bar_token, &QAction::triggered, this,[this]{stackedWidget->setCurrentWidget(token_widget);});

  QVBoxLayout *vLayout = new QVBoxLayout;

  QAction *tool_bar_mod = new QAction("&Mod Tools");
    toolbar->addAction(tool_bar_mod);
    tool_bar_mod->setVisible(false);
    connect(tool_bar_mod, &QAction::triggered, this,[this]{stackedWidget->setCurrentWidget(mod_widget);});
  QCheckBox *check_mod = new QCheckBox("Mod Tools");
    vLayout->addWidget(check_mod);
    connect(check_mod, &QCheckBox::stateChanged, this, [=](int state){
      enable_widget(state, tool_bar_mod);
    });

  QAction *tool_bar_leveling = new QAction("&Leveling");
    toolbar->addAction(tool_bar_leveling);
    tool_bar_leveling->setVisible(false);
    connect(tool_bar_leveling, &QAction::triggered, this,[this]{stackedWidget->setCurrentWidget(level_widget);});
  QCheckBox *check_leveling = new QCheckBox("Leveling");
    vLayout->addWidget(check_leveling);
    connect(check_leveling, &QCheckBox::stateChanged, this, [=](int state){
      enable_widget(state, tool_bar_leveling);
    });

  QAction *tool_bar_crypto = new QAction("&Crypto");
    tool_bar_crypto->setVisible(false);
    toolbar->addAction(tool_bar_crypto);
    connect(tool_bar_crypto, &QAction::triggered, this,[this]{stackedWidget->setCurrentWidget(crypto_widget);});
  QCheckBox *check_crypto = new QCheckBox("Crypto");
    vLayout->addWidget(check_crypto);
    connect(check_crypto, &QCheckBox::stateChanged, this, [=](int state){
      enable_widget(state, tool_bar_crypto);
    });

  home_widget->setLayout(vLayout);

  this->setCentralWidget(stackedWidget);
}

void Hub::enable_widget(int factor, QAction* desire)
{
  if(factor == 0)
    desire->setVisible(false);
  else if (factor == 2)
    desire->setVisible(true);
}

void Hub::create_file()
{
  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
  db.setDatabaseName("lauch.db");

  if (!db.open())
  {
    QMessageBox::warning(this,
     tr("Cannot open database"),
     tr("Did not write data."),
     QMessageBox::Close);
  }

  Hub::get_token();
  //setWindowTitle(edit->text());
}

void Hub::get_token()
{
  QSqlQuery query;

  query.exec("CREATE TABLE DISCORD_TOKEN("  \
      "token           TEXT    NOT NULL);");
  query.exec("select count(token) from DISCORD_TOKEN;");

  query.next();
  if(query.value(0).toInt()>=1)
  {
    setWindowTitle(query.value(0).toString());
    query.exec("delete from DISCORD_TOKEN");
  }

  QLineEdit *edit = token_widget->findChild<QLineEdit *>();
  query.prepare("insert into DISCORD_TOKEN values (?)");
  query.addBindValue(QString(edit->text()));
  query.exec();
}

void Hub::get_mod_rules()
{

}

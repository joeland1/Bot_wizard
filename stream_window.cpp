#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>

#include "stream_window.h"

Stream_window::Stream_window(QWidget *parent):QWidget(parent)
{
  QVBoxLayout *main_layout = new QVBoxLayout;

  QFormLayout *login_credentials = new QFormLayout;
  QLineEdit *email = new QLineEdit("");
  QLineEdit *password = new QLineEdit("");
  login_credentials->addRow(tr("&Email:"), email);
  login_credentials->addRow(tr("&Password:"), password);

  main_layout->addLayout(login_credentials);
  main_layout->addStretch();
  main_layout->addWidget(new QCheckBox("Search Local"));
  main_layout->addStretch();
  main_layout->addWidget(new QCheckBox("Search Youtube"));


  setLayout(main_layout);
}

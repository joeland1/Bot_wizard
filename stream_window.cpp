#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QCheckBox>
#include <QPushButton>

#include "stream_window.h"

Stream_window::Stream_window(QWidget *parent):QWidget(parent)
{
  QVBoxLayout *main_layout = new QVBoxLayout;

  QFormLayout *login_credentials = new QFormLayout;
  QLineEdit *email = new QLineEdit("");
    email->setObjectName("account email");
  QLineEdit *password = new QLineEdit("");
    password->setObjectName("account password");
  login_credentials->addRow(tr("&Email:"), email);
  login_credentials->addRow(tr("&Password:"), password);

  main_layout->addLayout(login_credentials);
  main_layout->addStretch();

  QCheckBox *enable_stream_local = new QCheckBox("Enable Local");
  main_layout->addWidget(enable_stream_local);

  main_layout->addStretch();
  main_layout->addWidget(new QCheckBox("Enable Youtube"));

  main_layout->addStretch();
  main_layout->addWidget(new QCheckBox("Allow All"));

  setLayout(main_layout);
}

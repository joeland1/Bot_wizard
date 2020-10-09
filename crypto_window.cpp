#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include "crypto_window.h"

Crypto_window::Crypto_window(QWidget *parent):QWidget(parent)
{
  QGridLayout *layout = new QGridLayout;
  QLabel *rpc_text = new QLabel("RPC User");
  QLineEdit *rpc_user_fill = new QLineEdit("");
  layout->addWidget(rpc_text,0,0,1,1);
  layout->addWidget(rpc_user_fill,0,1,1,1);

  this->setLayout(layout);
}

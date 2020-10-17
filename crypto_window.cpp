#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QIntValidator>
#include "crypto_window.h"

Crypto_window::Crypto_window(QWidget *parent):QWidget(parent)
{
  QGridLayout *main_layout = new QGridLayout;
  QGridLayout *rpc_block = new QGridLayout;
  QGridLayout *features = new QGridLayout;

  main_layout->addLayout(rpc_block,0,0);
  main_layout->addLayout(features,1,0);

  QLabel *rpc_text = new QLabel("RPC User");
  QLineEdit *rpc_user_fill = new QLineEdit("");
  rpc_block->addWidget(rpc_text,0,0,1,1);
  rpc_block->addWidget(rpc_user_fill,0,1,1,1);

  QLabel *rpc_port = new QLabel("RPC Password");
  QLineEdit *rpc_port_fill = new QLineEdit("");
  rpc_block->addWidget(rpc_port,1,0,1,1);
  rpc_block->addWidget(rpc_port_fill,1,1,1,1);

  QLabel *rpc_pw = new QLabel("RPC Port");
  QLineEdit *rpc_pw_fill = new QLineEdit("");
  rpc_pw_fill->setValidator( new QIntValidator(0, 99999, this));
  rpc_block->addWidget(rpc_pw,2,0,1,1);
  rpc_block->addWidget(rpc_pw_fill,2,1,1,1);

  QLabel *faucet = new QLabel("test");
  features->addWidget(faucet);

  this->setLayout(main_layout);
}

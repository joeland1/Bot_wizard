#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>

#include "mod_window.h"

Mod_window::Mod_window(QWidget *parent):QWidget(parent)
{
  QGridLayout *layout = new QGridLayout;
  QVBoxLayout *vertical = new QVBoxLayout;

  QCheckBox *member_control = new QCheckBox("Member Control");
    vertical->addWidget(member_control);
    connect(member_control, &QCheckBox::stateChanged, this, [=](int state){
      enable_member_control(state);
    });

  layout -> addLayout(vertical, 0,0);
  this->setLayout(layout);
}

void Mod_window::enable_member_control(int state)
{
  if(state == 0)
  {
    //disable the buttons
  }
  if(state == 2)
  {
    //enable the buttons
  }
}

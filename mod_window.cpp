#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QSpacerItem>
#include <QFormLayout>

#include "mod_window.h"

Mod_window::Mod_window(QWidget *parent):QWidget(parent)
{
  QVBoxLayout *layout = new QVBoxLayout;
  member_control_layout = new QGridLayout;

  QCheckBox *member_control = new QCheckBox("Member Control");
    member_control_layout->addWidget(member_control,0,0);
    connect(member_control, &QCheckBox::stateChanged, this, [=](int state){
      enable_member_control(state);
    });

  layout->addLayout(member_control_layout);
  this->setLayout(layout);
}

void Mod_window::enable_member_control(int state)
{
  if(state == 0)
  {
    //disabler
  }
  if(state == 2)
  {
    QCheckBox* button1 = new QCheckBox("button1");
    QCheckBox* button2 = new QCheckBox("button2");

    QFormLayout *layout_test = new QFormLayout;

    //QSpacerItem *space = new QSpacerItem(40,20, QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout_test->addRow(new QLabel("      "), button1);
    layout_test->addRow(new QLabel("      "), button2);

    layout_test->addItem(new QSpacerItem(0,300, QSizePolicy::Expanding, QSizePolicy::Expanding));


    member_control_layout->addLayout(layout_test,1,0);
  }
}

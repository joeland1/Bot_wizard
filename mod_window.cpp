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
  QVBoxLayout *overall_layout = new QVBoxLayout;
  member_control_layout = new QGridLayout;

  QCheckBox *member_control = new QCheckBox("Member Control");
    member_control->setObjectName("title box");
    member_control_layout->addWidget(member_control,0,0);
    connect(member_control, &QCheckBox::stateChanged, this, [=](int state){
      enable_member_control(state);
    });

  overall_layout->addLayout(member_control_layout);
  this->setLayout(overall_layout);
}

void Mod_window::enable_member_control(int state)
{
  if(state == 0)
  {
    QFormLayout* member_control_dec = member_control_layout->findChild<QFormLayout*>("member control submenu");
    while(member_control_dec->count()>0)
      delete member_control_dec->itemAt(0)->widget();
    delete member_control_dec;
  }
  if(state == 2)
  {
    QCheckBox* button1 = new QCheckBox("Can Ban");
      button1->setObjectName("can_ban");
    QCheckBox* button2 = new QCheckBox("Can Ban");
      button2->setObjectName("can_unban");
    QCheckBox* button3 = new QCheckBox("Can Kick");
      button3->setObjectName("can_kick");

    QFormLayout *layout_test = new QFormLayout;
      layout_test->setObjectName("member control submenu");

    //QSpacerItem *space = new QSpacerItem(40,20, QSizePolicy::Expanding, QSizePolicy::Fixed);

    layout_test->addRow(new QLabel("      "), button1);
    layout_test->addRow(new QLabel("      "), button2);
    layout_test->addRow(new QLabel("      "), button3);

    member_control_layout->addLayout(layout_test,1,0);
  }
}

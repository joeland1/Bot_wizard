#include <QWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QIntValidator>
#include <QPushButton>
#include "level_window.h"

Level_window::Level_window(QWidget *parent):QWidget(parent)
{
  QVBoxLayout *main_layout = new QVBoxLayout;
  rank_name_and_level = new QGridLayout;
    rank_name_and_level->setObjectName("rank box");

  main_layout->addLayout(rank_name_and_level);

  QLabel *title = new QLabel("Ranks");
  QPushButton *add_role = new QPushButton("Clicking this button will add a row");
  connect(add_role, &QPushButton::pressed, this, &Level_window::create_level_grouping);
  this->create_level_grouping();
  this->create_level_grouping();
  this->create_level_grouping();

  rank_name_and_level->addWidget(title,0,0,1,1);
  rank_name_and_level->addWidget(add_role,0,1,1,1);

  this->setLayout(main_layout);
}

void Level_window::create_level_grouping()
{
  QLineEdit *level = new QLineEdit("level #", this);
  level->setValidator( new QIntValidator(0, 99999, this));

  QLineEdit *name = new QLineEdit("name", this);
  QPushButton *remove = new QPushButton("Clicking this button will remove this row", this);

  connect(remove, &QPushButton::clicked, this, [=]{
    delete level;
    delete name;
    delete remove;
  });
  int row = rank_name_and_level->rowCount();

  rank_name_and_level->addWidget(level,row,0,1,1);
  rank_name_and_level->addWidget(name,row,1,1,1);
  rank_name_and_level->addWidget(remove,row,2,1,1);

}

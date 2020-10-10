#include <QWidget>
#include <QGridLayout>

class Level_window : public QWidget {

  Q_OBJECT

  public:
    Level_window(QWidget *parent = nullptr);
  private slots:
    void create_level_grouping();
  private:
    QGridLayout *rank_name_and_level;
};

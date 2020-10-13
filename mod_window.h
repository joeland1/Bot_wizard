#include <QWidget>
#include <QGridLayout>

class Mod_window : public QWidget {

  Q_OBJECT

  public:
    Mod_window(QWidget *parent = nullptr);
  private slots:
    void enable_member_control(int state);
  private:
    QGridLayout *member_control_layout;

};

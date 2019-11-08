#ifndef NEW_WINDOW_H
#define NEW_WINDOW_H

#include <QDialog>

namespace Ui {
class New_window;
}

class New_window : public QDialog
{
    Q_OBJECT

public:
    explicit New_window(QWidget *parent = nullptr);
    ~New_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::New_window *ui;
};

#endif // NEW_WINDOW_H

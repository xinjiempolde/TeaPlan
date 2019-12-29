#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>

namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    ~SearchWindow();

private:
    Ui::SearchWindow *ui;
};

#endif // SEARCHWINDOW_H

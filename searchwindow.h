#ifndef SEARCHWINDOW_H
#define SEARCHWINDOW_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class SearchWindow;
}

class SearchWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SearchWindow(QWidget *parent = nullptr);
    ~SearchWindow();
    void ReadFileData();

private slots:
    void on_all_button_clicked();

    void on_name_button_clicked();

    void on_term_button_clicked();

private:
    Ui::SearchWindow *ui;
    QVector<VNode> Sort;
};

#endif // SEARCHWINDOW_H

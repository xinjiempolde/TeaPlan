#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QVector>
#include "algraph.h"
namespace Ui {
class UpDate;
}

class UpDateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UpDateWindow(QWidget *parent = nullptr);
    ~UpDateWindow();
    void ReadFileData();
    void SaveFileData();

private slots:
    void on_submit_button_clicked();

private:
    Ui::UpDate *ui;
    QVector<VNode> Sort;
};

#endif // UPDATE_H

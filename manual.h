#ifndef MANUAL_H
#define MANUAL_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class Manual;
}

class Manual : public QWidget
{
    Q_OBJECT

public:
    explicit Manual(QWidget *parent = nullptr);
    ~Manual();

private slots:
    void on_record_button_clicked();

    void on_submit_button_clicked();

private:
    Ui::Manual *ui;
    ALGraph G;
};

#endif // MANUAL_H

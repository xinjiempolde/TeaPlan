/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 刘亚炯

Date: 2019-12-20

Description: 手动输入数据的窗口

**************************************************************************/
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
    ~Manual() override;
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_record_button_clicked();

    void on_submit_button_clicked();

private:
    Ui::Manual *ui;
    ALGraph G;
};

#endif // MANUAL_H

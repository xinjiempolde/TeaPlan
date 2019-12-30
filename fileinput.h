/**************************************************************************

Copyright: Xinji Zhou & Yajiong Liu & Songlin Wang All Rights Reserved

Author: 王崧霖

Date: 2019-12-20

Description: 从文件中输入数据的窗口

**************************************************************************/
#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class FileInput;
}

class FileInput : public QWidget
{
    Q_OBJECT

public:
    explicit FileInput(QWidget *parent = nullptr);
    ~FileInput();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FileInput *ui;
    ALGraph G;
};

#endif // FILEINPUT_H

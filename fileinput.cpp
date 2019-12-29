#include "fileinput.h"
#include "ui_fileinput.h"

#include <QFileDialog>

FileInput::FileInput(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileInput)
{
    ui->setupUi(this);
}

FileInput::~FileInput()
{
    delete ui;
}

void FileInput::on_pushButton_clicked()
{
    QString strSrcName = QFileDialog::getOpenFileName(
                this,
                tr("打开配置文件"),
                tr("."),
                tr("Text files(*.txt);;All files(*)")
                );
}

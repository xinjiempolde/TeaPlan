#include "update.h"
#include "ui_update.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

UpDateWindow::UpDateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UpDate)
{
    ui->setupUi(this);
}

UpDateWindow::~UpDateWindow()
{
    delete ui;
}

void UpDateWindow::ReadFileData()
{
    Sort.clear();
    QFile file("CouseData.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "警告", "打开文件失败！");
        return;
    }
    QTextStream s(&file);
    VNode node;
    while (!s.atEnd())
    {
        s >> node.data.term;
        s >> node.data.Num;
        s >> node.data.Name;
        s >> node.data.Point;
        s >> node.data.Weeks;
        Sort.push_back(node);
    }
    file.close();
}

void UpDateWindow::SaveFileData()
{
    QFile file("CouseData.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream s(&file);
    for (int m = 0; m < Sort.size(); m++)
    {
        s << Sort[m].data.term << "\t";
        s << Sort[m].data.Num << "\t";
        s << Sort[m].data.Name << "\t";
        s << Sort[m].data.Point << "\t";
        s << Sort[m].data.Weeks << "\n";
    }
    file.close();
}

void UpDateWindow::on_submit_button_clicked()
{
    QString pre = ui->pre_edit->text();
    QString after = ui->after_edit->text();
    if (pre.trimmed() == "" || after.trimmed() == "")
    {
        QMessageBox::warning(this, "警告", "内容不能为空！");
        return;
    }
    ReadFileData();
    bool isFound = false;
    for (int i = 0; i < Sort.size(); i++)
    {
        if (Sort[i].data.Name == pre)
        {
            Sort[i].data.Name = after;
            isFound = true;
            QMessageBox::information(this, "提示", "成功更新课程名称！");
            break;
        }
    }
    if (!isFound)
    {
        QMessageBox::warning(this, "警告", "没有找到该课程!");
    }
    SaveFileData();

}

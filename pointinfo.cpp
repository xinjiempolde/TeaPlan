#include "pointinfo.h"
#include "ui_pointinfo.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>

PointInfo::PointInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointInfo)
{
    ui->setupUi(this);
    ReadFileData();
    SetInfo();
}

PointInfo::~PointInfo()
{
    delete ui;
}

void PointInfo::ReadFileData()
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

void PointInfo::SetInfo()
{
    int terms = 0;

    /* 获取学期数目 */
    for (int i = 0; i <Sort.size(); i++)
    {
        if (Sort[i].data.term > terms)
        {
            terms = Sort[i].data.term;
        }
    }

    QString content = "";
    for (int i = 1; i <= terms; i++)
    {
        int sum_course = 0;
        float sum_point = 0;
        for (int j = 0; j < Sort.size(); j++)
        {
            if (Sort[j].data.term == i)
            {
                sum_course++;
                sum_point += Sort[j].data.Point;
            }
        }
        QString item = QString("第%1学期共需学习%2门课程，修得%3学分!\n\n").arg(i).arg(sum_course).arg(static_cast<int>(sum_point));
        content += item;
    }
    ui->info->setFontPointSize(14);
    ui->info->setText(content);

}

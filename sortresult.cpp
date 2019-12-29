#include "sortresult.h"
#include "ui_sortresult.h"

#include <QFile>
#include <QTreeWidget>
#include <QTextStream>
SortResult::SortResult(int TermNum, const QVector<VNode> &Sort, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SortResult),
    termNum(TermNum),
    Sort(Sort)
{
    ui->setupUi(this);
    ShowData();
    SaveData();
}

SortResult::~SortResult()
{
    delete ui;
}

void SortResult::ShowData()
{
    QTreeWidget *treeWidget = new QTreeWidget(this);//创建
    treeWidget->setColumnCount(5);  //设置列

    /* 设置标题 */
    QStringList titles;
    titles.append("第几学期");
    titles.append("课程编号");
    titles.append("课程名称");
    titles.append("学分");
    titles.append("应上周数");
    treeWidget->setHeaderLabels(titles);


    treeWidget->setGeometry(0,0,this->width(),this->height());  //设置大小

    /* 绑定数据 */
    QList<QTreeWidgetItem *> items;
    QStringList s;
    for (int m = 0; m < Sort.size(); m++)
    {
        s.clear();
        s.append(QString::number(Sort[m].data.term));
        s.append(Sort[m].data.Num);
        s.append(Sort[m].data.Name);
        s.append(QString("%1").arg(static_cast<double>(Sort[m].data.Point)));
        s.append(QString::number(Sort[m].data.Weeks));
        QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget,s);
        items.append(item);
    }
    //添加顶层节点
    treeWidget->insertTopLevelItems(0,items);
    //节点始终保持展开
    treeWidget->setItemsExpandable(false);
    treeWidget->expandAll();
}

void SortResult::SaveData()
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

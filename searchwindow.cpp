#include "searchwindow.h"
#include "ui_searchwindow.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include "algraph.h"
#include "sortresult.h"
SearchWindow::SearchWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchWindow)
{
    ui->setupUi(this);
    QRegExpValidator *point = new QRegExpValidator(QRegExp("\\d+"));
    ui->term_edit->setValidator(point);
}

SearchWindow::~SearchWindow()
{
    delete ui;
}

void SearchWindow::ReadFileData()
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
        if (node.data.term == 0)
        {
            break;
        }
        s >> node.data.Num;
        s >> node.data.Name;
        s >> node.data.Point;
        s >> node.data.Weeks;
        Sort.push_back(node);
    }
    file.close();
}

void SearchWindow::on_all_button_clicked()
{
    ReadFileData();
    SortResult* window = new SortResult(Sort, nullptr);
    window->show();
}

void SearchWindow::on_name_button_clicked()
{
    ReadFileData();
    QString name = ui->name_edit->text();
    if (name == "")
    {
        QMessageBox::warning(this, "警告", "输入内容不能为空！");
        return;
    }
    QVector<VNode>::iterator it = Sort.begin();
    QVector<VNode> vecName;
    while (it != Sort.end())
    {
        /* 模糊查找 */
        if (it->data.Name.indexOf(name) != -1)
        {
            vecName.push_back(*it);
        }
        it++;
    }
    SortResult* window = new SortResult(vecName, nullptr);
    window->show();
}

void SearchWindow::on_term_button_clicked()
{
    ReadFileData();
    int term = ui->term_edit->text().toInt();
    if (term == 0)
    {
        QMessageBox::warning(this, "警告", "输入内容不能为空！");
        return;
    }
    QVector<VNode>::iterator it = Sort.begin();
    QVector<VNode> vecTerm;
    while (it != Sort.end())
    {
        if (term == it->data.term)
        {
            vecTerm.push_back(*it);
        }
        it++;
    }
    SortResult* window = new SortResult(vecTerm, nullptr);
    window->show();
}

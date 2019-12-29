#include "fileinput.h"
#include "ui_fileinput.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "graphwindow.h"
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
    QFile file(strSrcName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "警告", "文件打开失败！");
        return;
    }
    QTextStream s(&file);
    while (!s.atEnd())
    {
        int i = G.vexnum;
        s >> G.AdjList[i].data.Num;
        if (G.AdjList[i].data.Num == "")
        {
            break;
        }
        s >> G.AdjList[i].data.Name;
        s >> G.AdjList[i].data.Point;
        s >> G.AdjList[i].data.Weeks;
        G.AdjList[i].data.marks = 0;
        G.AdjList[i].data.term = 0;
        G.AdjList[i].data.Outdegree = 0;
        G.AdjList[i].data.Indegree = 0;
        G.vexnum++;
    }
    GraphWindow* window = new GraphWindow(this, &G);
    window->show();
}

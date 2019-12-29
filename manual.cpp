#include "manual.h"
#include "ui_manual.h"
#include "graphwindow.h"
Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
}

Manual::~Manual()
{
    delete ui;
}

void Manual::on_record_button_clicked()
{
    // 获得用户输入
    QString id = ui->id_edit->text();
    QString name = ui->name_edit->text();
    float point = ui->point_edit->text().toFloat();
    int week = ui->week_edit->text().toInt();

    // 将用户输入保存到图结构中
    int i = G.vexnum;
    G.AdjList[i].data.Num = id;
    G.AdjList[i].data.Name = name;
    G.AdjList[i].data.Point = point;
    G.AdjList[i].data.Weeks = week;
    G.AdjList[i].data.marks = 0;
    G.AdjList[i].data.term = 0;
    G.AdjList[i].data.Outdegree = 0;
    G.AdjList[i].data.Indegree = 0;
    G.vexnum++;
}

void Manual::on_submit_button_clicked()
{
    GraphWindow* window = new GraphWindow(this, &G);
    window->show();
}

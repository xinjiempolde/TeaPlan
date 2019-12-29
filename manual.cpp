#include "manual.h"
#include "ui_manual.h"
#include "graphwindow.h"

#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QKeyEvent>
Manual::Manual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Manual)
{
    ui->setupUi(this);
    setFocusPolicy(Qt::StrongFocus);
    QRegExpValidator *id = new QRegExpValidator(QRegExp("[A-Za-z0-9]+"),this);
    ui->id_edit->setValidator(id);
    QRegExpValidator *point = new QRegExpValidator(QRegExp("\\d+"));
    ui->week_edit->setValidator(point);
    QRegExp regExp("\\d+(.\\d+)?$");
    QRegExpValidator *pattern= new QRegExpValidator(regExp, this);
    ui->point_edit->setValidator(pattern);
}

Manual::~Manual()
{
    delete ui;
}

void Manual::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up)
    {
        QPixmap pixmap(":/cartoon.png");
        ui->img->setPixmap(pixmap);
        ui->img->setScaledContents(true);
        ui->img->show();
    }
    else
    {
        ui->img->hide();
    }
}

void Manual::on_record_button_clicked()
{
    // 获得用户输入
    QString id = ui->id_edit->text();
    QString name = ui->name_edit->text();
    float point = ui->point_edit->text().toFloat();
    int week = ui->week_edit->text().toInt();
    if (id == "" || name == "" || ui->point_edit->text().isEmpty() || week == 0)
    {
        QMessageBox::warning(this, "警告", "输入内容不能为空");
        return;
    }
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

    /* 显示提示信息 */
    ui->msg_lable->setText(QString("到目前为止，您一共输入了%1组数据").arg(G.vexnum));

    /* 清空已经输入的数据 */
    ui->id_edit->clear();
    ui->name_edit->clear();
    ui->point_edit->clear();
    ui->week_edit->clear();
}

void Manual::on_submit_button_clicked()
{
    /* 一个数据也没有输入 */
    if (G.vexnum == 0)
    {
        QMessageBox::warning(this, "警告", "您未输入任何数据！");
        return;
    }
    GraphWindow* window = new GraphWindow(this, &G);
    window->show();
}

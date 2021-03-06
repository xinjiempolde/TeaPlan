#include "graphwindow.h"
#include "ui_graphwindow.h"
#include "sortresult.h"
#include <cacuutils.h>
#include <math.h>
#include <QMouseEvent>
#include <QPainter>
#include <QtDebug>
#include <QMessageBox>
#include <QQueue>
#include <QIntValidator>
#include <QTime>
GraphWindow::GraphWindow(QWidget *parent, ALGraph* G) :
    QMainWindow(parent),
    ui(new Ui::GraphWindow),
    G(G),
    count(0),
    n(G->vexnum),
    PointSize(20)
{
    ui->setupUi(this);
    ui->centralwidget->setMouseTracking(true);
    setMouseTracking(true);
    setWindowTitle("选择先导关系");
    ui->textBrowser->setVisible(false);

    /* 限制输入内容 */
    QRegExpValidator *point = new QRegExpValidator(QRegExp("\\d+(.\\d+)?$"));
    ui->point_edit->setValidator(point);
    QRegExpValidator *term = new QRegExpValidator(QRegExp("\\d+"));
    ui->term_edit->setValidator(term);

    /* 初始化值 */
    last_click = 0;
    for (int i = 0; i < n; i++)
    {
        PressMap[i] = false;
        OverMap[i] = false;
        CheckMap[i] = false;
        for (int j = 0; j < n; j++)
        {
            HasArc[i].push_back(false);
        }
    }
    ColorList = {Qt::blue, Qt::yellow, Qt::green, Qt::red, Qt::black, Qt::cyan, Qt::magenta};

    GetBtnsPos(n);
    PaintLable();
}

GraphWindow::~GraphWindow()
{
    delete ui;
}

void GraphWindow::mousePressEvent(QMouseEvent *event)
{
    bool isInPoint = false; // 用户单击位置是否在点内标志
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (list_button[i].contains(event->pos()))
        {
            PressMap[i] = true;
            isInPoint = true;
            pos = i;
            break;
        }
    }
    /* 用户点击位置不在点内则不应该执行后面的语句 */
    if (!isInPoint)
    {
        return;
    }
    count += 1;

    /* 代表用户点击了起始端 */
    if (count == 1)
    {
        last_click = pos;
        /* 转到圆的中心 */
        line.begin = QPoint(static_cast<int>(list_button[pos].x()) + 10, static_cast<int>(list_button[pos].y()) + 10);
    }

    /* 代表用户点击了终止端 */
    if (count == 2)
    {
        line.end = QPoint(static_cast<int>(list_button[pos].x()) + 10, static_cast<int>(list_button[pos].y()) + 10);
        /* 上次点击和这次点击不是一个点 */
        if (pos != last_click)
        {
            CheckMap[pos] = true;
            CheckMap[last_click] = true;
            if (HasArc[last_click][pos] || HasArc[pos][last_click])
            {
                QMessageBox::warning(this, "警告", "该两节点间已经存在弧！");
            }
            else
            {
                list_line.push_back(line);
                HasArc[last_click][pos] = true;
                ui->textBrowser->setVisible(true);
                QString content = ui->textBrowser->toPlainText();
                content += QString("%1").arg(G->AdjList[last_click].data.Name) + " -> " +QString("%1").arg(G->AdjList[pos].data.Name) + "\n";
                ui->textBrowser->setText(content);
                ArcNode* s = new ArcNode;
                s->adjvex = pos;
                s->nextarc = G->AdjList[last_click].firstarc;
                G->AdjList[last_click].firstarc = s;
                G->AdjList[last_click].data.Outdegree++;
                G->AdjList[pos].data.Indegree++;
                G->AdjList[pos].data.preCourse.push_back(G->AdjList[last_click].data.Name);
            }
        }
        /* 是同一位置则取消按下效果 */
        else
        {
            /* 没有被选中的点才取消选中状态 */
            if (!CheckMap[pos])
            {
                PressMap[pos] = false;
            }
        }
        count = 0;
        repaint();
    }
}

void GraphWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint pos = event->pos();
    line.end = pos;
    for (int i = 0; i < n; i++)
    {
        if (list_button[i].contains(event->pos()))
        {
            OverMap[i] = true;
        }
        else
        {
            OverMap[i] = false;
        }
    }
    repaint();  // 需要实时更新鼠标移到点上的效果
}

void GraphWindow::GetBtnsPos(int n, const coor &center, int stripe, coor pointsize)
{
    list_button.clear();
    CacuUtils utils;
    double angle = 360 / n;
    coor point = {center.x + stripe, center.y};
    while (n--)
    {
        list_button.push_back(QRect(static_cast<int>(point.x), static_cast<int>(point.y), static_cast<int>(pointsize.x), static_cast<int>(pointsize.y)));
        point = utils.CacuCordinate(center, point, angle);
    }
}

void GraphWindow::PaintLable()
{
    int level = list_button.size() / 2;
    for (int i = 0; i < list_button.size(); i++)
    {
        QLabel* label = new QLabel(this);
        if (i <= level)
        {
            label->setGeometry(static_cast<int>(list_button[i].x()) - 20,static_cast<int>(list_button[i].y()) + 20, 60,30);
        }
        else
        {
            label->setGeometry(static_cast<int>(list_button[i].x() - 20),static_cast<int>(list_button[i].y()) - 25, 60,30);
        }
        label->setText(G->AdjList[i].data.Name);
        label->show();
    }
}

Qt::GlobalColor GraphWindow::GetRandomColor()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int pos = qrand() % 5;
    return ColorList[pos];
}

void GraphWindow::paintEvent(QPaintEvent *)
{
    /* 绘制需要的点 */
    for (int i = 0; i < n; i++)
    {
        QPainter point_painter(this);
        point_painter.setPen(QPen(Qt::blue, 2));
        if (OverMap[i])
        {
            point_painter.setBrush(Qt::red);
        }
        if (PressMap[i])
        {
            point_painter.setBrush(Qt::black);
        }
        point_painter.drawEllipse(list_button[i]);
    }
    /* 绘制用户自己画的连线 */
    QPainter painter(this);
    int i;
    for (i = 0; i <list_line.size(); i++)
    {
        painter.setPen(QPen(ColorList[i % ColorList.size()], 4));
        painter.drawLine(list_line[i].begin, list_line[i].end);
    }

    /* 只有点击了某一个点后才能实时绘制线条 */
    painter.setPen(QPen(ColorList[i % ColorList.size()],4));//设置画笔形式
    if (count == 1)
    {
        painter.drawLine(line.begin, line.end);
    }
}

void GraphWindow::on_course_button_clicked()
{
    int MaxWeeks = ui->term_edit->text().toInt();
    float MaxPoints = ui->point_edit->text().toFloat();
    int TermNum = 1;    // 学期数量
    float t = MaxPoints;
    int s = MaxWeeks;
    QQueue<VNode*> q;
    QVector<VNode> Sort;    // 已经排好的课程
    int ZeroIndegreeNum = 0;    // 入度为零的顶点数量
    int m = 0, n = 0;
    /* 存在未被访问的顶点 */
    while (G->Traverse())
    {
        ZeroIndegreeNum = 0;

        /* 入度为零的点入队列且未还被访问的节点入队列 */
        /* 这些课程可以同时上 */
        for (int i = 0; i < G->vexnum; i++)
        {
            if (G->AdjList[i].data.Indegree == 0 && G->AdjList[i].data.marks != 1)
            {
                q.push_back(&G->AdjList[i]);
                ZeroIndegreeNum++;
                m++;    // m同一批先导课的数目
                G->AdjList[i].data.marks = 1;
            }
        }

        if (ZeroIndegreeNum == 0)
        {
            QMessageBox::warning(this, "警告", "存在环！");
            this->close();
            return;

        }
        while (!q.isEmpty())
        {
            VNode* v = q.dequeue();
            ArcNode* p = v->firstarc;
            n++;

            /* 将与该节点关联的顶点入度减一 */
            while (p)
            {
                G->AdjList[p->adjvex].data.Indegree--;
                p = p->nextarc;
            }

            if (v->data.Point <= t && v->data.Weeks <= s)
            {
                v->data.term = TermNum;
                Sort.push_back(*v);
            }
            else
            {
                TermNum++;
                /* 注意，这里只能更新t,s的更新是不确定的,因为有可能同时进行的先导课还没上完 */
                /* 所以即使是下一个学期了，也必须把没上完的先导课上完 */
                t = MaxPoints;
                s = MaxWeeks;
                v->data.term = TermNum;
                Sort.push_back(*v);
            }

            /* 同一批次的先导课结束了，该排后面的课程了 */
            /* 验证的是是否同一学期含有不是同一批先导课的课程 */
            if (n == m)
            {
                QVector<VNode>::iterator it = Sort.begin();
                while (it != Sort.end())
                {
                    // 去查找是否有先导课存在
                    // 含义就是要去排后导课程结果发现先导课程在同一学期
                    if (it->data.term == TermNum)
                    {
                        /* 最长先导课上完才能上后面的课 */
                        if (s >= (MaxWeeks - it->data.Weeks))
                        {
                            s = MaxWeeks - it->data.Weeks;
                        }
                    }
                    it++;
                }
                t -= v->data.Point;
            }

            /* 仍然在排本批次的先导课 */
            else
            {
                // 只要同一批课程没拍完，所剩周数都不用减
                t -= v->data.Point;
            }
        }

    }
    // 测试使用，舍不得删
    /*
    for (int j = 1; j <= TermNum; j++)
    {
        qDebug() << "第" << j << "学期";
        for (int m = 0; m < Sort.size(); m++)
        {
            if (Sort[m].data.term == j)
                qDebug() << Sort[m].data.Num <<  Sort[m].data.Name << Sort[m].data.Point << Sort[m].data.Weeks << Sort[m].data.term << endl;
        }
    }
    */
    this->close();
    SortResult* sortwindow = new SortResult(Sort, nullptr, true);
    sortwindow->show();
}

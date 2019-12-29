#ifndef GRAPHWINDOW_H
#define GRAPHWINDOW_H

#include "cacuutils.h"
#include "algraph.h"
#include <QMainWindow>
#include <QMap>
#include <QVector>
typedef struct {
    QPoint begin;
    QPoint end;
}line_point;
namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = nullptr, ALGraph* G = nullptr);
    ~GraphWindow();
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void GetBtnsPos(int n, const coor &center = {350, 350}, int stripe = 200, coor pointsize = {20, 20});

private:
    Ui::GraphWindow *ui;
    QVector<line_point> list_line;
    QVector<line_point>::iterator it;
    QVector<QRectF> list_button;
    QVector<QRectF>::iterator button_it;
    QMap<int, bool> PressMap;
    QMap<int, bool> OverMap;
    QMap<int, bool> CheckMap; // 保存哪些节点被点击
    QMap<int, QVector<bool>> HasArc; // 保存哪些节点间有弧
    ALGraph* G;
    line_point line;
    int last_click; // 上次点击了那个点
    int count;
    const int n;
    const int PointSize;

protected:
    void paintEvent(QPaintEvent* event);
private slots:
    void on_course_button_clicked();
};

#endif // GRAPHWINDOW_H

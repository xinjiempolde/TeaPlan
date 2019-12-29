#ifndef POINTINFO_H
#define POINTINFO_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class PointInfo;
}

class PointInfo : public QWidget
{
    Q_OBJECT

public:
    explicit PointInfo(QWidget *parent = nullptr);
    ~PointInfo();
    void ReadFileData();
    void SetInfo();

private:
    Ui::PointInfo *ui;
    QVector<VNode> Sort;
};

#endif // POINTINFO_H

#ifndef SORTRESULT_H
#define SORTRESULT_H

#include <QWidget>
#include "algraph.h"
namespace Ui {
class SortResult;
}

class SortResult : public QWidget
{
    Q_OBJECT

public:
    explicit SortResult(int TermNum, const QVector<VNode> &Sort, QWidget *parent = nullptr);
    ~SortResult();
    void ShowData();
    void SaveData();

private:
    Ui::SortResult *ui;
    int termNum;
    const QVector<VNode> &Sort;
};

#endif // SORTRESULT_H

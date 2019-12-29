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
    explicit SortResult(const QVector<VNode> &Sort, QWidget *parent = nullptr, bool flag = false);
    ~SortResult();
    void ShowData();
    void SaveData();

private:
    Ui::SortResult *ui;
    int termNum;
    const QVector<VNode> &Sort;
    bool isSaveFile;    // 是否需要保存到文件中
};

#endif // SORTRESULT_H

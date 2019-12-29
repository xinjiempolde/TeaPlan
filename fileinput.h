#ifndef FILEINPUT_H
#define FILEINPUT_H

#include <QWidget>

namespace Ui {
class FileInput;
}

class FileInput : public QWidget
{
    Q_OBJECT

public:
    explicit FileInput(QWidget *parent = nullptr);
    ~FileInput();

private slots:
    void on_pushButton_clicked();

private:
    Ui::FileInput *ui;
};

#endif // FILEINPUT_H

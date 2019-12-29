#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manual.h"
#include "fileinput.h"
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitTabWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitTabWidget()
{
    m_tabwidget = new QTabWidget(this);
    m_tabwidget->resize(800, 600);

    // 第一个窗口，人工输入窗口
    Manual* manual = new Manual(m_tabwidget);
    m_tabwidget->addTab(manual, "手动输入");

    // 第二个窗口，文件输入窗口
    FileInput* fileinput = new FileInput(m_tabwidget);
    m_tabwidget->addTab(fileinput, "文件输入");

    // 第三个窗口，更新课程表

    // 第四个窗口，统计信息
}

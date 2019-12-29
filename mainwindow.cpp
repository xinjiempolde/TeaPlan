#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manual.h"
#include "fileinput.h"
#include "searchwindow.h"
#include "update.h"
#include "pointinfo.h"
#include <QFileDialog>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("课程管理系统");
    setWindowIcon(QIcon(":/windowico.ico"));
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

    // 第三个窗口，查询课程表
    SearchWindow* searchwindow = new SearchWindow(m_tabwidget);
    m_tabwidget->addTab(searchwindow, "查询课表");

    // 第四个窗口，更新课程表
    UpDateWindow* updatewindow = new UpDateWindow(m_tabwidget);
    m_tabwidget->addTab(updatewindow, "更新课表");

    // 第五个窗口，显示要修学分
    PointInfo* pointinfo = new PointInfo(m_tabwidget);
    m_tabwidget->addTab(pointinfo, "统计信息");
}

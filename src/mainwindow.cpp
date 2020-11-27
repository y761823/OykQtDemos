#include "mainwindow.h"

#include <QListWidget>
#include <QTabWidget>

#include "OCheckListWidget/ochecklistwidgetexample.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTabWidget* tabWidget = new QTabWidget;
    setCentralWidget(tabWidget);

    tabWidget->addTab(new OCheckListWidgetExample(this), "OCheckedListWidget");
}

MainWindow::~MainWindow()
{
}


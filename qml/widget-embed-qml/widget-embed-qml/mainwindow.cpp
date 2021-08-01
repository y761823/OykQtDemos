#include "mainwindow.h"

#include <QHBoxLayout>
#include <QQuickWidget>
#include <QQmlContext>

ControllerConnection::ControllerConnection(QObject *parent):
    QObject(parent) {}

void ControllerConnection::callSlot(const QString &value)
{
    qDebug() << __FUNCTION__ << value;
}

ViewerConnection::ViewerConnection(QObject *parent):
    QObject(parent) {}

int ViewerConnection::getValue() {
    return value;
}

void ViewerConnection::onAdd(int count)
{
    emit valueChanged(value += count);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto central = new QWidget(this);
    setCentralWidget(central);

    // controllerWidget
    auto controllerWidget = new QQuickWidget(this);
    auto controllerConnection = new ControllerConnection(this);
    controllerWidget->rootContext()->setContextProperty("controllerConnection", controllerConnection);
    controllerWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    controllerWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    controllerWidget->setAttribute(Qt::WA_TranslucentBackground);
    controllerWidget->setClearColor(Qt::transparent);
    controllerWidget->setSource(QUrl("qrc:/qml/controller.qml"));

    // viewerWidget
    auto viewerWidget = new QQuickWidget(this);
    auto viewerConnection = new ViewerConnection(this);
    connect(controllerConnection, &ControllerConnection::add,
            viewerConnection, &ViewerConnection::onAdd);
    viewerWidget->rootContext()->setContextProperty("viewerConnection", viewerConnection);
    viewerWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    viewerWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    viewerWidget->setAttribute(Qt::WA_TranslucentBackground);
    viewerWidget->setClearColor(Qt::transparent);
    viewerWidget->setSource(QUrl("qrc:/qml/view.qml"));

    auto layout = new QHBoxLayout(central);
    layout->addWidget(controllerWidget);
    layout->addWidget(viewerWidget);

    setMinimumSize(800, 400);
}

MainWindow::~MainWindow()
{
}

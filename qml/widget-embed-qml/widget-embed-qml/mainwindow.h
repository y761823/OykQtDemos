#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ControllerConnection : public QObject
{
    Q_OBJECT

public:
    ControllerConnection(QObject *parent = nullptr);

public slots:
    void callSlot(const QString &value);

signals:
    void add(int count);
};

class ViewerConnection : public QObject
{
    Q_OBJECT

public:
    ViewerConnection(QObject *parent = nullptr);

    Q_INVOKABLE int getValue();

public slots:
    void onAdd(int count);

signals:
    void valueChanged(int count);

private:
    int value = 0;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};

#endif // MAINWINDOW_H

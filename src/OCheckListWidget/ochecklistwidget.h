#ifndef OCHECKLISTWIDGET_H
#define OCHECKLISTWIDGET_H

#include <QListWidget>

class OCheckListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OCheckListWidget(QWidget *parent = nullptr);

    void addItem(const QString &text, const QVariant &value, Qt::CheckState state = Qt::Unchecked);

    QList<QVariant> checkedValues();

protected:
    void onSelectAllBtnClicked();
    void onUnselectAllBtnClicked();
    void onInverseAllBtnClicked();

private:
    QListWidget* listWidget;
};

#endif // OCHECKLISTWIDGET_H

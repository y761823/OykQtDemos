#include "ochecklistwidgetexample.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

#include "ochecklistwidget.h"

OCheckListWidgetExample::OCheckListWidgetExample(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* btn = new QPushButton(tr("Show All Selections"), this);

    auto listWidget = new OCheckListWidget(this);
    listWidget->addItem("text1", "value1");
    listWidget->addItem("text2", "value2");
    listWidget->addItem("text3", "value3", Qt::Checked);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(listWidget);
    layout->addWidget(btn);

    connect(btn, &QPushButton::clicked, this, [=]() {
        QStringList values;
        for (auto value : listWidget->checkedValues()) {
            values << value.toString();
        }
        QMessageBox::information(this, tr("All Selections"), values.join(","));
    });
}

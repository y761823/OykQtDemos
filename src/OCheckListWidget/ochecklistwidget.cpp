#include "ochecklistwidget.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

OCheckListWidget::OCheckListWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* selectAllBtn = new QPushButton(tr("Select All"), this);
    QPushButton* unselectAllBtn = new QPushButton(tr("Unselect All"), this);
    QPushButton* inverseAllBtn = new QPushButton(tr("Inverse All"), this);

    QHBoxLayout* btnLayout = new QHBoxLayout;
    btnLayout->addWidget(selectAllBtn);
    btnLayout->addWidget(unselectAllBtn);
    btnLayout->addWidget(inverseAllBtn);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(listWidget = new QListWidget);
    mainLayout->addLayout(btnLayout);

    connect(selectAllBtn, &QPushButton::clicked, this, &OCheckListWidget::onSelectAllBtnClicked);
    connect(unselectAllBtn, &QPushButton::clicked, this, &OCheckListWidget::onUnselectAllBtnClicked);
    connect(inverseAllBtn, &QPushButton::clicked, this, &OCheckListWidget::onInverseAllBtnClicked);
}

void OCheckListWidget::addItem(const QString &text, const QVariant &value, Qt::CheckState state)
{
    auto item = new QListWidgetItem(text, listWidget);
    item->setData(Qt::UserRole, value);
    item->setCheckState(state);
}

QList<QVariant> OCheckListWidget::checkedValues()
{
    QList<QVariant> result;
    for (int i = 0; i < listWidget->count(); ++i) {
        auto item = listWidget->item(i);
        if (item->checkState() == Qt::Checked) {
            result << item->data(Qt::UserRole);
        }
    }
    return result;
}

void OCheckListWidget::onSelectAllBtnClicked()
{
    for (int i = 0; i < listWidget->count(); ++i) {
        listWidget->item(i)->setCheckState(Qt::Checked);
    }
}

void OCheckListWidget::onUnselectAllBtnClicked()
{
    for (int i = 0; i < listWidget->count(); ++i) {
        listWidget->item(i)->setCheckState(Qt::Unchecked);
    }
}

void OCheckListWidget::onInverseAllBtnClicked()
{
    for (int i = 0; i < listWidget->count(); ++i) {
        auto item = listWidget->item(i);
        item->setCheckState(item->checkState() == Qt::Unchecked ? Qt::Checked : Qt::Unchecked);
    }
}

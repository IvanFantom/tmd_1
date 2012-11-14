/********************************************************************************
** Form generated from reading UI file 'pointadddialog.ui'
**
** Created: Mon Nov 12 22:57:18 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTADDDIALOG_H
#define UI_POINTADDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PointAddDialog
{
public:
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QSpinBox *classSpinBox;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PointAddDialog)
    {
        if (PointAddDialog->objectName().isEmpty())
            PointAddDialog->setObjectName(QString::fromUtf8("PointAddDialog"));
        PointAddDialog->resize(229, 161);
        verticalLayout = new QVBoxLayout(PointAddDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        comboBox = new QComboBox(PointAddDialog);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        verticalLayout->addWidget(comboBox);

        classSpinBox = new QSpinBox(PointAddDialog);
        classSpinBox->setObjectName(QString::fromUtf8("classSpinBox"));

        verticalLayout->addWidget(classSpinBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(PointAddDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(PointAddDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PointAddDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PointAddDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PointAddDialog);
    } // setupUi

    void retranslateUi(QDialog *PointAddDialog)
    {
        PointAddDialog->setWindowTitle(QApplication::translate("PointAddDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("PointAddDialog", "Undefined class point", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PointAddDialog", "Defined class point", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class PointAddDialog: public Ui_PointAddDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTADDDIALOG_H

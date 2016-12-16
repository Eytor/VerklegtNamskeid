/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Edit
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *edit_scientist_name;
    QLabel *edit_scientist_name_error;
    QLineEdit *scientist_edit_name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *edit_scientist_gender;
    QLabel *edit_scientist_gender_error;
    QLineEdit *scientist_edit_gender;
    QHBoxLayout *horizontalLayout_4;
    QLabel *edit_scientist_yob;
    QLabel *edit_scientist_yob_error;
    QLineEdit *scientist_edit_yob;
    QHBoxLayout *horizontalLayout_5;
    QLabel *edit_scientist_yod;
    QLabel *edit_scientist_yod_error;
    QLineEdit *scientist_edit_yod;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Edit)
    {
        if (Edit->objectName().isEmpty())
            Edit->setObjectName(QStringLiteral("Edit"));
        Edit->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(Edit);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        edit_scientist_name = new QLabel(Edit);
        edit_scientist_name->setObjectName(QStringLiteral("edit_scientist_name"));

        horizontalLayout_2->addWidget(edit_scientist_name);

        edit_scientist_name_error = new QLabel(Edit);
        edit_scientist_name_error->setObjectName(QStringLiteral("edit_scientist_name_error"));

        horizontalLayout_2->addWidget(edit_scientist_name_error);


        verticalLayout->addLayout(horizontalLayout_2);

        scientist_edit_name = new QLineEdit(Edit);
        scientist_edit_name->setObjectName(QStringLiteral("scientist_edit_name"));

        verticalLayout->addWidget(scientist_edit_name);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        edit_scientist_gender = new QLabel(Edit);
        edit_scientist_gender->setObjectName(QStringLiteral("edit_scientist_gender"));

        horizontalLayout_3->addWidget(edit_scientist_gender);

        edit_scientist_gender_error = new QLabel(Edit);
        edit_scientist_gender_error->setObjectName(QStringLiteral("edit_scientist_gender_error"));

        horizontalLayout_3->addWidget(edit_scientist_gender_error);


        verticalLayout->addLayout(horizontalLayout_3);

        scientist_edit_gender = new QLineEdit(Edit);
        scientist_edit_gender->setObjectName(QStringLiteral("scientist_edit_gender"));

        verticalLayout->addWidget(scientist_edit_gender);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        edit_scientist_yob = new QLabel(Edit);
        edit_scientist_yob->setObjectName(QStringLiteral("edit_scientist_yob"));

        horizontalLayout_4->addWidget(edit_scientist_yob);

        edit_scientist_yob_error = new QLabel(Edit);
        edit_scientist_yob_error->setObjectName(QStringLiteral("edit_scientist_yob_error"));

        horizontalLayout_4->addWidget(edit_scientist_yob_error);


        verticalLayout->addLayout(horizontalLayout_4);

        scientist_edit_yob = new QLineEdit(Edit);
        scientist_edit_yob->setObjectName(QStringLiteral("scientist_edit_yob"));

        verticalLayout->addWidget(scientist_edit_yob);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        edit_scientist_yod = new QLabel(Edit);
        edit_scientist_yod->setObjectName(QStringLiteral("edit_scientist_yod"));

        horizontalLayout_5->addWidget(edit_scientist_yod);

        edit_scientist_yod_error = new QLabel(Edit);
        edit_scientist_yod_error->setObjectName(QStringLiteral("edit_scientist_yod_error"));

        horizontalLayout_5->addWidget(edit_scientist_yod_error);


        verticalLayout->addLayout(horizontalLayout_5);

        scientist_edit_yod = new QLineEdit(Edit);
        scientist_edit_yod->setObjectName(QStringLiteral("scientist_edit_yod"));

        verticalLayout->addWidget(scientist_edit_yod);


        verticalLayout_2->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(Edit);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(Edit);
        QObject::connect(buttonBox, SIGNAL(accepted()), Edit, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Edit, SLOT(reject()));

        QMetaObject::connectSlotsByName(Edit);
    } // setupUi

    void retranslateUi(QDialog *Edit)
    {
        Edit->setWindowTitle(QApplication::translate("Edit", "Dialog", 0));
        edit_scientist_name->setText(QApplication::translate("Edit", "Name:", 0));
        edit_scientist_name_error->setText(QString());
        scientist_edit_name->setText(QString());
        scientist_edit_name->setPlaceholderText(QApplication::translate("Edit", "Name..", 0));
        edit_scientist_gender->setText(QApplication::translate("Edit", "Gender:", 0));
        edit_scientist_gender_error->setText(QString());
        scientist_edit_gender->setText(QString());
        scientist_edit_gender->setPlaceholderText(QApplication::translate("Edit", "Gender..", 0));
        edit_scientist_yob->setText(QApplication::translate("Edit", "Year of birth:", 0));
        edit_scientist_yob_error->setText(QString());
        scientist_edit_yob->setText(QString());
        scientist_edit_yob->setPlaceholderText(QApplication::translate("Edit", "Year of birth..", 0));
        edit_scientist_yod->setText(QApplication::translate("Edit", "Year of Death:", 0));
        edit_scientist_yod_error->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Edit: public Ui_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H

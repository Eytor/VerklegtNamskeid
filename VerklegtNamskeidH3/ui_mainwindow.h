/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabs;
    QWidget *Scientists;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *scientist_search;
    QHBoxLayout *horizontalLayout_10;
    QComboBox *scientist_order_by_column;
    QComboBox *scientist_order_by_asc_desc;
    QTableWidget *scientist_table;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *scientist_delete;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *scientist_edit_button;
    QLabel *add_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scientist_name;
    QLabel *scientist_name_error;
    QLineEdit *scientist_name_input;
    QHBoxLayout *horizontalLayout_3;
    QLabel *scientist_gender;
    QLabel *scientist_gender_error;
    QLineEdit *scientist_gender_input;
    QHBoxLayout *horizontalLayout_4;
    QLabel *scientist_yob;
    QLabel *scientist_yob_error;
    QLineEdit *scientist_yob_input;
    QHBoxLayout *horizontalLayout_5;
    QLabel *scientist_yod;
    QLabel *scientist_yod_error;
    QLineEdit *scientist_yod_input;
    QPushButton *scientist_button;
    QWidget *Computers;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *computer_search;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *computer_order_by_column;
    QComboBox *computer_order_by_asc_desc;
    QTableWidget *computer_table;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *computer_delete;
    QSpacerItem *horizontalSpacer;
    QPushButton *computer_edit_button;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *computer_name_label;
    QLabel *computer_name_error;
    QLineEdit *computer_name_input;
    QHBoxLayout *horizontalLayout_6;
    QLabel *computer_type_label;
    QLabel *computer_type_error;
    QLineEdit *computer_type_input;
    QHBoxLayout *horizontalLayout_7;
    QLabel *computer_built_label;
    QLabel *computer_built_error;
    QComboBox *computer_built_input;
    QHBoxLayout *horizontalLayout_8;
    QLabel *computer_year_lable;
    QLabel *computer_year_error;
    QLineEdit *computer_year_input;
    QPushButton *computer_button;
    QWidget *linking_tab;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *scientist_link_table;
    QLabel *label_4;
    QTableWidget *computer_link_table;
    QPushButton *link_delete_button;
    QLabel *Link_success_fail_label;
    QLabel *label_2;
    QComboBox *scientist_dropdown;
    QLabel *label_3;
    QComboBox *computer_dropdown;
    QPushButton *link_button;
    QWidget *recycle_tab;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *trash_placeholder;
    QWidget *scientist_trash_tab;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *scientist_trash_table;
    QGridLayout *gridLayout_2;
    QPushButton *scientist_recover_button;
    QPushButton *scientist_empty_button;
    QWidget *computer_trash_tab;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *computer_trash_table;
    QGridLayout *gridLayout_3;
    QPushButton *computer_recover_button;
    QPushButton *computer_empty_button;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCalendarWidget *calendarWidget;
    QMenuBar *menuBar;
    QMenu *menuUltra_scientist_and_computer_database;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1112, 742);
        QPalette palette;
        QBrush brush(QColor(53, 53, 53, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QLatin1String("QMainWindow{\n"
"background-color:rgb(53, 53, 53);\n"
"}\n"
"\n"
"QTableWidget::item{\n"
"background-color:grey;\n"
"padding:0;\n"
"}\n"
"\n"
"QTableWidget::item:hover{\n"
"background-color:rgb(85, 85, 255);\n"
"border-color:#008CBA;\n"
"}\n"
"QTableWidget::item:selected{\n"
"background-color:rgb(75, 75, 75);\n"
"color:#008CBB\n"
"}\n"
"\n"
"QComboBox{\n"
"color:#fff;\n"
"}\n"
"QComboBox:scientist_order_by_column{\n"
"color:#fff;\n"
"}\n"
"\n"
"QLabel{\n"
"color:#fff;\n"
"}\n"
"\n"
"QWidget{\n"
"background-color:rgb(53, 53, 53);\n"
"}\n"
"\n"
"\n"
"QTableView{\n"
"background-color:rgb(53, 53, 53);\n"
"border: 1px solid gray;\n"
"color:#fff;\n"
"}\n"
"\n"
"QGroupBox{\n"
"background-color:rgb(53, 53, 53);\n"
"border-style:groove;\n"
"border-color:rgb(75, 75, 75);\n"
"padding:10px;\n"
"font: 10pt \"MS Shell Dlg 2\";\n"
"color:#008CBA;\n"
"}\n"
"\n"
"QMenuBar{\n"
"background-color:rgb(53, 53, 53);\n"
"padding:5px;\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"QMenu{\n"
"background-color:rgb(53, 53, 53);\n"
"color:#"
                        "008CBA;\n"
"padding:0;\n"
"}\n"
"QMenu::item:selected{\n"
"background-color:rgb(75, 75, 75);\n"
"color:#008CBA;\n"
"}\n"
"\n"
"QMenuBar::item{\n"
"background-color:rgb(53, 53, 53);\n"
"color:#008CBA;\n"
"padding:5px;\n"
"font: 12pt \"MS Shell Dlg 2\";\n"
"}\n"
"\n"
"QLineEdit{\n"
"background-color:gray;\n"
"border: 1px solid rgb(30, 30, 30);\n"
"}\n"
"QLineEdit:hover{\n"
"background-color:rgb(75, 75, 75);\n"
"border: 1px solid #008CBA ;\n"
"}\n"
"\n"
"QPushButton{\n"
"  font-size: 12px;\n"
"  padding: 6px;\n"
"  color: #fff;\n"
"  background-color: rgb(90,90,90);\n"
"  border:1px solid rgb(30,30,30);\n"
"  border-radius: 6px;\n"
"}\n"
"QPushButton:hover{\n"
"background-color:#008CBA;\n"
"}\n"
"QPushButton:!enabled{\n"
"border:  1px solid grey;\n"
"color:grey;\n"
"background-color:rgb(65, 65, 65)\n"
"}\n"
"\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setTabShape(QTabWidget::Rounded);
        Scientists = new QWidget();
        Scientists->setObjectName(QStringLiteral("Scientists"));
        verticalLayout_2 = new QVBoxLayout(Scientists);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scientist_search = new QLineEdit(Scientists);
        scientist_search->setObjectName(QStringLiteral("scientist_search"));
        scientist_search->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(scientist_search);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        scientist_order_by_column = new QComboBox(Scientists);
        scientist_order_by_column->setObjectName(QStringLiteral("scientist_order_by_column"));

        horizontalLayout_10->addWidget(scientist_order_by_column);

        scientist_order_by_asc_desc = new QComboBox(Scientists);
        scientist_order_by_asc_desc->setObjectName(QStringLiteral("scientist_order_by_asc_desc"));

        horizontalLayout_10->addWidget(scientist_order_by_asc_desc);


        verticalLayout_2->addLayout(horizontalLayout_10);

        scientist_table = new QTableWidget(Scientists);
        if (scientist_table->columnCount() < 4)
            scientist_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        scientist_table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        scientist_table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        scientist_table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        scientist_table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        scientist_table->setObjectName(QStringLiteral("scientist_table"));
        scientist_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scientist_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        scientist_table->setSortingEnabled(false);
        scientist_table->horizontalHeader()->setCascadingSectionResizes(true);
        scientist_table->horizontalHeader()->setDefaultSectionSize(235);
        scientist_table->horizontalHeader()->setMinimumSectionSize(100);
        scientist_table->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        scientist_table->horizontalHeader()->setStretchLastSection(true);
        scientist_table->verticalHeader()->setVisible(false);

        verticalLayout_2->addWidget(scientist_table);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        scientist_delete = new QPushButton(Scientists);
        scientist_delete->setObjectName(QStringLiteral("scientist_delete"));
        scientist_delete->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scientist_delete->sizePolicy().hasHeightForWidth());
        scientist_delete->setSizePolicy(sizePolicy);
        scientist_delete->setMinimumSize(QSize(300, 0));
        scientist_delete->setMaximumSize(QSize(160000, 160000));
        scientist_delete->setToolTipDuration(-1);
        scientist_delete->setLayoutDirection(Qt::LeftToRight);
        scientist_delete->setAutoFillBackground(false);

        horizontalLayout_12->addWidget(scientist_delete);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        scientist_edit_button = new QPushButton(Scientists);
        scientist_edit_button->setObjectName(QStringLiteral("scientist_edit_button"));
        scientist_edit_button->setEnabled(false);
        sizePolicy.setHeightForWidth(scientist_edit_button->sizePolicy().hasHeightForWidth());
        scientist_edit_button->setSizePolicy(sizePolicy);
        scientist_edit_button->setMinimumSize(QSize(300, 0));
        scientist_edit_button->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_12->addWidget(scientist_edit_button);


        verticalLayout_2->addLayout(horizontalLayout_12);

        add_label = new QLabel(Scientists);
        add_label->setObjectName(QStringLiteral("add_label"));
        add_label->setLayoutDirection(Qt::LeftToRight);
        add_label->setFrameShape(QFrame::NoFrame);

        verticalLayout_2->addWidget(add_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        scientist_name = new QLabel(Scientists);
        scientist_name->setObjectName(QStringLiteral("scientist_name"));

        horizontalLayout_2->addWidget(scientist_name);

        scientist_name_error = new QLabel(Scientists);
        scientist_name_error->setObjectName(QStringLiteral("scientist_name_error"));

        horizontalLayout_2->addWidget(scientist_name_error);


        verticalLayout_2->addLayout(horizontalLayout_2);

        scientist_name_input = new QLineEdit(Scientists);
        scientist_name_input->setObjectName(QStringLiteral("scientist_name_input"));

        verticalLayout_2->addWidget(scientist_name_input);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        scientist_gender = new QLabel(Scientists);
        scientist_gender->setObjectName(QStringLiteral("scientist_gender"));

        horizontalLayout_3->addWidget(scientist_gender);

        scientist_gender_error = new QLabel(Scientists);
        scientist_gender_error->setObjectName(QStringLiteral("scientist_gender_error"));

        horizontalLayout_3->addWidget(scientist_gender_error);


        verticalLayout_2->addLayout(horizontalLayout_3);

        scientist_gender_input = new QLineEdit(Scientists);
        scientist_gender_input->setObjectName(QStringLiteral("scientist_gender_input"));

        verticalLayout_2->addWidget(scientist_gender_input);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        scientist_yob = new QLabel(Scientists);
        scientist_yob->setObjectName(QStringLiteral("scientist_yob"));

        horizontalLayout_4->addWidget(scientist_yob);

        scientist_yob_error = new QLabel(Scientists);
        scientist_yob_error->setObjectName(QStringLiteral("scientist_yob_error"));

        horizontalLayout_4->addWidget(scientist_yob_error);


        verticalLayout_2->addLayout(horizontalLayout_4);

        scientist_yob_input = new QLineEdit(Scientists);
        scientist_yob_input->setObjectName(QStringLiteral("scientist_yob_input"));

        verticalLayout_2->addWidget(scientist_yob_input);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        scientist_yod = new QLabel(Scientists);
        scientist_yod->setObjectName(QStringLiteral("scientist_yod"));

        horizontalLayout_5->addWidget(scientist_yod);

        scientist_yod_error = new QLabel(Scientists);
        scientist_yod_error->setObjectName(QStringLiteral("scientist_yod_error"));

        horizontalLayout_5->addWidget(scientist_yod_error);


        verticalLayout_2->addLayout(horizontalLayout_5);

        scientist_yod_input = new QLineEdit(Scientists);
        scientist_yod_input->setObjectName(QStringLiteral("scientist_yod_input"));

        verticalLayout_2->addWidget(scientist_yod_input);

        scientist_button = new QPushButton(Scientists);
        scientist_button->setObjectName(QStringLiteral("scientist_button"));

        verticalLayout_2->addWidget(scientist_button);

        tabs->addTab(Scientists, QString());
        Computers = new QWidget();
        Computers->setObjectName(QStringLiteral("Computers"));
        verticalLayout_3 = new QVBoxLayout(Computers);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        computer_search = new QLineEdit(Computers);
        computer_search->setObjectName(QStringLiteral("computer_search"));
        computer_search->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_3->addWidget(computer_search);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        computer_order_by_column = new QComboBox(Computers);
        computer_order_by_column->setObjectName(QStringLiteral("computer_order_by_column"));

        horizontalLayout_13->addWidget(computer_order_by_column);

        computer_order_by_asc_desc = new QComboBox(Computers);
        computer_order_by_asc_desc->setObjectName(QStringLiteral("computer_order_by_asc_desc"));

        horizontalLayout_13->addWidget(computer_order_by_asc_desc);


        verticalLayout_3->addLayout(horizontalLayout_13);

        computer_table = new QTableWidget(Computers);
        if (computer_table->columnCount() < 4)
            computer_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        computer_table->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        computer_table->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        computer_table->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        computer_table->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        computer_table->setObjectName(QStringLiteral("computer_table"));
        computer_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        computer_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        computer_table->setSortingEnabled(true);
        computer_table->horizontalHeader()->setDefaultSectionSize(265);
        computer_table->horizontalHeader()->setStretchLastSection(true);
        computer_table->verticalHeader()->setVisible(false);

        verticalLayout_3->addWidget(computer_table);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        computer_delete = new QPushButton(Computers);
        computer_delete->setObjectName(QStringLiteral("computer_delete"));
        computer_delete->setEnabled(false);
        computer_delete->setMinimumSize(QSize(300, 0));

        horizontalLayout_11->addWidget(computer_delete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer);

        computer_edit_button = new QPushButton(Computers);
        computer_edit_button->setObjectName(QStringLiteral("computer_edit_button"));
        computer_edit_button->setEnabled(false);
        computer_edit_button->setMinimumSize(QSize(300, 0));

        horizontalLayout_11->addWidget(computer_edit_button);


        verticalLayout_3->addLayout(horizontalLayout_11);

        label = new QLabel(Computers);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        computer_name_label = new QLabel(Computers);
        computer_name_label->setObjectName(QStringLiteral("computer_name_label"));

        horizontalLayout->addWidget(computer_name_label);

        computer_name_error = new QLabel(Computers);
        computer_name_error->setObjectName(QStringLiteral("computer_name_error"));

        horizontalLayout->addWidget(computer_name_error);


        verticalLayout_3->addLayout(horizontalLayout);

        computer_name_input = new QLineEdit(Computers);
        computer_name_input->setObjectName(QStringLiteral("computer_name_input"));

        verticalLayout_3->addWidget(computer_name_input);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        computer_type_label = new QLabel(Computers);
        computer_type_label->setObjectName(QStringLiteral("computer_type_label"));

        horizontalLayout_6->addWidget(computer_type_label);

        computer_type_error = new QLabel(Computers);
        computer_type_error->setObjectName(QStringLiteral("computer_type_error"));

        horizontalLayout_6->addWidget(computer_type_error);


        verticalLayout_3->addLayout(horizontalLayout_6);

        computer_type_input = new QLineEdit(Computers);
        computer_type_input->setObjectName(QStringLiteral("computer_type_input"));

        verticalLayout_3->addWidget(computer_type_input);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        computer_built_label = new QLabel(Computers);
        computer_built_label->setObjectName(QStringLiteral("computer_built_label"));

        horizontalLayout_7->addWidget(computer_built_label);

        computer_built_error = new QLabel(Computers);
        computer_built_error->setObjectName(QStringLiteral("computer_built_error"));

        horizontalLayout_7->addWidget(computer_built_error);


        verticalLayout_3->addLayout(horizontalLayout_7);

        computer_built_input = new QComboBox(Computers);
        computer_built_input->setObjectName(QStringLiteral("computer_built_input"));

        verticalLayout_3->addWidget(computer_built_input);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        computer_year_lable = new QLabel(Computers);
        computer_year_lable->setObjectName(QStringLiteral("computer_year_lable"));

        horizontalLayout_8->addWidget(computer_year_lable);

        computer_year_error = new QLabel(Computers);
        computer_year_error->setObjectName(QStringLiteral("computer_year_error"));

        horizontalLayout_8->addWidget(computer_year_error);


        verticalLayout_3->addLayout(horizontalLayout_8);

        computer_year_input = new QLineEdit(Computers);
        computer_year_input->setObjectName(QStringLiteral("computer_year_input"));

        verticalLayout_3->addWidget(computer_year_input);

        computer_button = new QPushButton(Computers);
        computer_button->setObjectName(QStringLiteral("computer_button"));

        verticalLayout_3->addWidget(computer_button);

        tabs->addTab(Computers, QString());
        linking_tab = new QWidget();
        linking_tab->setObjectName(QStringLiteral("linking_tab"));
        verticalLayout_12 = new QVBoxLayout(linking_tab);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));

        horizontalLayout_9->addLayout(verticalLayout_11);

        scientist_link_table = new QTableWidget(linking_tab);
        if (scientist_link_table->columnCount() < 1)
            scientist_link_table->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        scientist_link_table->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        scientist_link_table->setObjectName(QStringLiteral("scientist_link_table"));
        scientist_link_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scientist_link_table->horizontalHeader()->setStretchLastSection(true);
        scientist_link_table->verticalHeader()->setVisible(false);

        horizontalLayout_9->addWidget(scientist_link_table);

        label_4 = new QLabel(linking_tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_9->addWidget(label_4);

        computer_link_table = new QTableWidget(linking_tab);
        if (computer_link_table->columnCount() < 1)
            computer_link_table->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        computer_link_table->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        computer_link_table->setObjectName(QStringLiteral("computer_link_table"));
        computer_link_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        computer_link_table->setRowCount(0);
        computer_link_table->horizontalHeader()->setStretchLastSection(true);
        computer_link_table->verticalHeader()->setVisible(false);

        horizontalLayout_9->addWidget(computer_link_table);


        verticalLayout_12->addLayout(horizontalLayout_9);

        link_delete_button = new QPushButton(linking_tab);
        link_delete_button->setObjectName(QStringLiteral("link_delete_button"));
        link_delete_button->setEnabled(false);

        verticalLayout_12->addWidget(link_delete_button);

        Link_success_fail_label = new QLabel(linking_tab);
        Link_success_fail_label->setObjectName(QStringLiteral("Link_success_fail_label"));
        Link_success_fail_label->setMinimumSize(QSize(0, 0));
        Link_success_fail_label->setFrameShape(QFrame::StyledPanel);
        Link_success_fail_label->setAlignment(Qt::AlignCenter);
        Link_success_fail_label->setTextInteractionFlags(Qt::NoTextInteraction);

        verticalLayout_12->addWidget(Link_success_fail_label);

        label_2 = new QLabel(linking_tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_12->addWidget(label_2);

        scientist_dropdown = new QComboBox(linking_tab);
        scientist_dropdown->setObjectName(QStringLiteral("scientist_dropdown"));

        verticalLayout_12->addWidget(scientist_dropdown);

        label_3 = new QLabel(linking_tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_12->addWidget(label_3);

        computer_dropdown = new QComboBox(linking_tab);
        computer_dropdown->setObjectName(QStringLiteral("computer_dropdown"));

        verticalLayout_12->addWidget(computer_dropdown);

        link_button = new QPushButton(linking_tab);
        link_button->setObjectName(QStringLiteral("link_button"));
        link_button->setEnabled(false);

        verticalLayout_12->addWidget(link_button);

        tabs->addTab(linking_tab, QString());
        recycle_tab = new QWidget();
        recycle_tab->setObjectName(QStringLiteral("recycle_tab"));
        verticalLayout_7 = new QVBoxLayout(recycle_tab);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        trash_placeholder = new QTabWidget(recycle_tab);
        trash_placeholder->setObjectName(QStringLiteral("trash_placeholder"));
        scientist_trash_tab = new QWidget();
        scientist_trash_tab->setObjectName(QStringLiteral("scientist_trash_tab"));
        verticalLayout_5 = new QVBoxLayout(scientist_trash_tab);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        scientist_trash_table = new QTableWidget(scientist_trash_tab);
        if (scientist_trash_table->columnCount() < 4)
            scientist_trash_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        scientist_trash_table->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        scientist_trash_table->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        scientist_trash_table->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        scientist_trash_table->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        scientist_trash_table->setObjectName(QStringLiteral("scientist_trash_table"));
        scientist_trash_table->setFrameShape(QFrame::WinPanel);
        scientist_trash_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        scientist_trash_table->setSelectionBehavior(QAbstractItemView::SelectRows);
        scientist_trash_table->horizontalHeader()->setDefaultSectionSize(255);
        scientist_trash_table->horizontalHeader()->setStretchLastSection(true);
        scientist_trash_table->verticalHeader()->setVisible(false);

        verticalLayout_5->addWidget(scientist_trash_table);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scientist_recover_button = new QPushButton(scientist_trash_tab);
        scientist_recover_button->setObjectName(QStringLiteral("scientist_recover_button"));
        scientist_recover_button->setEnabled(false);

        gridLayout_2->addWidget(scientist_recover_button, 0, 0, 1, 1);

        scientist_empty_button = new QPushButton(scientist_trash_tab);
        scientist_empty_button->setObjectName(QStringLiteral("scientist_empty_button"));

        gridLayout_2->addWidget(scientist_empty_button, 1, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        trash_placeholder->addTab(scientist_trash_tab, QString());
        computer_trash_tab = new QWidget();
        computer_trash_tab->setObjectName(QStringLiteral("computer_trash_tab"));
        verticalLayout_6 = new QVBoxLayout(computer_trash_tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        computer_trash_table = new QTableWidget(computer_trash_tab);
        if (computer_trash_table->columnCount() < 4)
            computer_trash_table->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        computer_trash_table->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        computer_trash_table->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        computer_trash_table->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        computer_trash_table->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        computer_trash_table->setObjectName(QStringLiteral("computer_trash_table"));
        computer_trash_table->setFrameShape(QFrame::WinPanel);
        computer_trash_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
        computer_trash_table->setAlternatingRowColors(true);
        computer_trash_table->setSelectionBehavior(QAbstractItemView::SelectItems);
        computer_trash_table->horizontalHeader()->setDefaultSectionSize(255);
        computer_trash_table->horizontalHeader()->setStretchLastSection(true);
        computer_trash_table->verticalHeader()->setVisible(false);

        verticalLayout_6->addWidget(computer_trash_table);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        computer_recover_button = new QPushButton(computer_trash_tab);
        computer_recover_button->setObjectName(QStringLiteral("computer_recover_button"));
        computer_recover_button->setEnabled(false);

        gridLayout_3->addWidget(computer_recover_button, 0, 0, 1, 1);

        computer_empty_button = new QPushButton(computer_trash_tab);
        computer_empty_button->setObjectName(QStringLiteral("computer_empty_button"));

        gridLayout_3->addWidget(computer_empty_button, 1, 0, 1, 1);


        verticalLayout_6->addLayout(gridLayout_3);

        trash_placeholder->addTab(computer_trash_tab, QString());

        verticalLayout_7->addWidget(trash_placeholder);

        tabs->addTab(recycle_tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_8 = new QVBoxLayout(tab_2);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        calendarWidget = new QCalendarWidget(groupBox);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));

        verticalLayout->addWidget(calendarWidget);


        verticalLayout_8->addWidget(groupBox);

        tabs->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabs);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1112, 39));
        menuUltra_scientist_and_computer_database = new QMenu(menuBar);
        menuUltra_scientist_and_computer_database->setObjectName(QStringLiteral("menuUltra_scientist_and_computer_database"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuUltra_scientist_and_computer_database->menuAction());

        retranslateUi(MainWindow);

        tabs->setCurrentIndex(1);
        trash_placeholder->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        scientist_search->setText(QString());
        scientist_search->setPlaceholderText(QApplication::translate("MainWindow", "Search..", 0));
        QTableWidgetItem *___qtablewidgetitem = scientist_table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Full name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = scientist_table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem2 = scientist_table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Year of Birth", 0));
        QTableWidgetItem *___qtablewidgetitem3 = scientist_table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Year of Death", 0));
#ifndef QT_NO_TOOLTIP
        scientist_delete->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        scientist_delete->setText(QApplication::translate("MainWindow", "Delete scientist", 0));
        scientist_edit_button->setText(QApplication::translate("MainWindow", "Edit", 0));
        add_label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:x-large; font-weight:600; color:#ffffff;\">Add scientist to list</span></p></body></html>", 0));
        scientist_name->setText(QApplication::translate("MainWindow", "Name:", 0));
        scientist_name_error->setText(QString());
        scientist_name_input->setText(QString());
        scientist_name_input->setPlaceholderText(QApplication::translate("MainWindow", "Name..", 0));
        scientist_gender->setText(QApplication::translate("MainWindow", "Gender:", 0));
        scientist_gender_error->setText(QString());
        scientist_gender_input->setText(QString());
        scientist_gender_input->setPlaceholderText(QApplication::translate("MainWindow", "Gender..", 0));
        scientist_yob->setText(QApplication::translate("MainWindow", "Year of birth:", 0));
        scientist_yob_error->setText(QString());
        scientist_yob_input->setText(QString());
        scientist_yob_input->setPlaceholderText(QApplication::translate("MainWindow", "Year of birth..", 0));
        scientist_yod->setText(QApplication::translate("MainWindow", "Year of Death:", 0));
        scientist_yod_error->setText(QString());
        scientist_yod_input->setText(QString());
        scientist_yod_input->setPlaceholderText(QApplication::translate("MainWindow", "Year of death (leave empty if still alive)..", 0));
        scientist_button->setText(QApplication::translate("MainWindow", "Add", 0));
        tabs->setTabText(tabs->indexOf(Scientists), QApplication::translate("MainWindow", "Scientists", 0));
        computer_search->setText(QString());
        computer_search->setPlaceholderText(QApplication::translate("MainWindow", "Search..", 0));
        QTableWidgetItem *___qtablewidgetitem4 = computer_table->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem5 = computer_table->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem6 = computer_table->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Built", 0));
        QTableWidgetItem *___qtablewidgetitem7 = computer_table->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Year", 0));
        computer_delete->setText(QApplication::translate("MainWindow", "Delete Computer", 0));
        computer_edit_button->setText(QApplication::translate("MainWindow", "Edit", 0));
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:x-large; font-weight:600;\">Add computer to list</span></p></body></html>", 0));
        computer_name_label->setText(QApplication::translate("MainWindow", "Name:", 0));
        computer_name_error->setText(QString());
        computer_name_input->setPlaceholderText(QApplication::translate("MainWindow", "Name..", 0));
        computer_type_label->setText(QApplication::translate("MainWindow", "Type:", 0));
        computer_type_error->setText(QString());
        computer_type_input->setPlaceholderText(QApplication::translate("MainWindow", "Type..", 0));
        computer_built_label->setText(QApplication::translate("MainWindow", "Built:", 0));
        computer_built_error->setText(QString());
        computer_year_lable->setText(QApplication::translate("MainWindow", "Year:", 0));
        computer_year_error->setText(QString());
        computer_year_input->setText(QString());
        computer_year_input->setPlaceholderText(QApplication::translate("MainWindow", "Year..", 0));
        computer_button->setText(QApplication::translate("MainWindow", "Add", 0));
        tabs->setTabText(tabs->indexOf(Computers), QApplication::translate("MainWindow", "Computers", 0));
        QTableWidgetItem *___qtablewidgetitem8 = scientist_link_table->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Full Name", 0));
        label_4->setText(QApplication::translate("MainWindow", "Is linked to", 0));
        QTableWidgetItem *___qtablewidgetitem9 = computer_link_table->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Computer Name", 0));
        link_delete_button->setText(QApplication::translate("MainWindow", "Delete Link", 0));
        Link_success_fail_label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Select Scientist to link to:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Select Computer to link to:", 0));
        link_button->setText(QApplication::translate("MainWindow", "Link", 0));
        tabs->setTabText(tabs->indexOf(linking_tab), QApplication::translate("MainWindow", "Linking", 0));
        QTableWidgetItem *___qtablewidgetitem10 = scientist_trash_table->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Full name", 0));
        QTableWidgetItem *___qtablewidgetitem11 = scientist_trash_table->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Gender", 0));
        QTableWidgetItem *___qtablewidgetitem12 = scientist_trash_table->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Year of birth", 0));
        QTableWidgetItem *___qtablewidgetitem13 = scientist_trash_table->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Year of death", 0));
        scientist_recover_button->setText(QApplication::translate("MainWindow", "Recover selected from bin", 0));
        scientist_empty_button->setText(QApplication::translate("MainWindow", "Empty recycle bin", 0));
        trash_placeholder->setTabText(trash_placeholder->indexOf(scientist_trash_tab), QApplication::translate("MainWindow", "Scientists", 0));
        QTableWidgetItem *___qtablewidgetitem14 = computer_trash_table->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Name", 0));
        QTableWidgetItem *___qtablewidgetitem15 = computer_trash_table->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem16 = computer_trash_table->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Built", 0));
        QTableWidgetItem *___qtablewidgetitem17 = computer_trash_table->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Year", 0));
        computer_recover_button->setText(QApplication::translate("MainWindow", "Recover selected from bin", 0));
        computer_empty_button->setText(QApplication::translate("MainWindow", "Empty recycle bin", 0));
        trash_placeholder->setTabText(trash_placeholder->indexOf(computer_trash_tab), QApplication::translate("MainWindow", "Computers", 0));
        tabs->setTabText(tabs->indexOf(recycle_tab), QApplication::translate("MainWindow", "Recycle Bin", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Calendar", 0));
        tabs->setTabText(tabs->indexOf(tab_2), QApplication::translate("MainWindow", "Calendar", 0));
        menuUltra_scientist_and_computer_database->setTitle(QApplication::translate("MainWindow", "Ultra scientist and computer database", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
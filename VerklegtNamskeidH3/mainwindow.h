#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "domainservice.h"
#include <QMainWindow>
#include <QDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Function that displays all scientists to table
    void displayAllScientists();
    // function that orders the scientist vector in a specific order chosen by user
    void scientistsOrder();
    // function that orders the computer vector in a specific order chosen by user
    void computersOrder();
    // Function that displays all computers to table
    void displayAllComputers();
    // Function that displays all deleted computers to table
    void displayComputerTrash();
    // Function that displays all deleted scientists to table
    void displayScientistTrash();
    // Function that displays all scientists that have links to a specific table
    void displayLinksScientists();
private slots:
    // Function starts searching scientists as soon as user starts writing
    void on_scientist_search_textChanged(const QString &arg1);
    // Add to Scientist Table button, when it's clicked it adds scientist to table and database
    void on_scientist_button_clicked();
    //Sends a scientist to the recycle bin
    void on_scientist_delete_clicked();
    //Clears everything
    void disableAndClearErrthing();


    void on_scientist_table_clicked();

    void on_computer_search_textChanged(const QString &arg1);

    void on_computer_button_clicked();

    void on_computer_table_clicked();

    void on_computer_delete_clicked();

    void on_computer_trash_table_clicked();

    void on_scientist_trash_table_clicked();

    void on_computer_recover_button_clicked();

    void on_scientist_recover_button_clicked();

    void on_computer_empty_button_clicked();

    void on_scientist_empty_button_clicked();

    void on_tabs_tabBarClicked(int index);

    void on_link_button_clicked();

    void on_scientist_link_table_clicked();

    void on_scientist_edit_button_clicked();

    void on_computer_link_table_clicked();

    void on_link_delete_button_clicked();


    void on_scientist_order_by_column_currentIndexChanged();

    void on_scientist_order_by_asc_desc_currentIndexChanged();

    void on_computer_order_by_column_currentIndexChanged();

    void on_computer_order_by_asc_desc_currentIndexChanged();

    void on_computer_edit_button_clicked();

    void on_computer_button_edit_clicked();

    void on_scientist_button_edit_clicked();

private:
    Ui::MainWindow *ui;
    DomainService _service;

    vector<TolPers> _tempInput;
    vector<TolPers> _currentScientistDisplay;
    vector<TolPers> _currentScientistTrashDisplay;

    vector<TolComp> _currentComputerDisplay;
    vector<TolComp> _currentComputerTrashDisplay;
    vector<TolComp> _tempCompInput;

    vector<TolPersLink> _linkPersDisplay;
    vector<TolCompLink> _linkCompDisplay;
    int _currentEditID;
};

#endif // MAINWINDOW_H

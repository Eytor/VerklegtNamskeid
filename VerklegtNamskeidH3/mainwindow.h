#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "domainservice.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayAllScientists();
    void displayAllComputers();
    void printPerson(int list, int i);
private slots:
    void on_scientist_search_textChanged(const QString &arg1);

    void on_scientist_button_clicked();

    void on_scientist_delete_clicked();


    void on_scientist_table_clicked();

    void on_computer_search_textChanged(const QString &arg1);

    void on_computer_button_clicked();

private:
    Ui::MainWindow *ui;
    DomainService _service;

    vector<TolPers> _tempInput;
    vector<TolPers> _currentScientistDisplay;

    vector<TolComp> _currentComputerDisplay;
    vector<TolComp> _tempCompInput;
};

#endif // MAINWINDOW_H

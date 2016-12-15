#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _service.retriveList();
    displayAllScientists();
    displayAllComputers();
    displayComputerTrash();
    displayScientistTrash();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    ui->scientist_table->clearContents();
    _currentScientistDisplay = _service.getList(1);
    ui->scientist_table->setRowCount(_currentScientistDisplay.size());

    for(unsigned int i = 0; i < _currentScientistDisplay.size(); i++)
    {
        QString fullName =  QString::fromStdString(_currentScientistDisplay[i].fullName);
        QString gender =  QString::fromStdString(_currentScientistDisplay[i].gender);
        QString YoB =  QString::number(_currentScientistDisplay[i].yearOfBirth);
        QString YoD =  QString::number(_currentScientistDisplay[i].yearOfDeath);

        ui->scientist_table->setItem(i, 0, new QTableWidgetItem(fullName));
        ui->scientist_table->setItem(i, 1, new QTableWidgetItem(gender));
        ui->scientist_table->setItem(i, 2, new QTableWidgetItem(YoB));

        if(YoD != "0")
        {
            ui->scientist_table->setItem(i, 3, new QTableWidgetItem(YoD));
        }
    }
}

void MainWindow::displayAllComputers()
{
    ui->computer_table->clearContents();
    _currentComputerDisplay = _service.getCompList(1);
    ui->computer_table->setRowCount(_currentComputerDisplay.size());

    for(unsigned int i = 0; i < _currentComputerDisplay.size(); i++)
    {
        QString name =  QString::fromStdString(_currentComputerDisplay[i].name);
        QString type =  QString::fromStdString(_currentComputerDisplay[i].type);
        QString built =  QString::number(_currentComputerDisplay[i].built);
        QString year =  QString::number(_currentComputerDisplay[i].year);

        ui->computer_table->setItem(i, 0, new QTableWidgetItem(name));
        ui->computer_table->setItem(i, 1, new QTableWidgetItem(type));
        ui->computer_table->setItem(i, 2, new QTableWidgetItem(built));

        if(built != "0")
        {
            ui->computer_table->setItem(i, 3, new QTableWidgetItem(year));
        }
    }
}

void MainWindow::displayComputerTrash()
{
    ui->computer_trash_table->clearContents();
    _currentComputerTrashDisplay = _service.getCompList(2);
    ui->computer_trash_table->setRowCount(_currentComputerTrashDisplay.size());

    for(unsigned int i = 0; i < _currentComputerTrashDisplay.size(); i++)
    {
        QString name =  QString::fromStdString(_currentComputerTrashDisplay[i].name);
        QString type =  QString::fromStdString(_currentComputerTrashDisplay[i].type);
        QString built =  QString::number(_currentComputerTrashDisplay[i].built);
        QString year =  QString::number(_currentComputerTrashDisplay[i].year);

        ui->computer_trash_table->setItem(i, 0, new QTableWidgetItem(name));
        ui->computer_trash_table->setItem(i, 1, new QTableWidgetItem(type));
        ui->computer_trash_table->setItem(i, 2, new QTableWidgetItem(built));

        if(built != "0")
        {
            ui->computer_trash_table->setItem(i, 3, new QTableWidgetItem(year));
        }
    }
}

void MainWindow::displayScientistTrash()
{
    ui->scientist_trash_table->clearContents();
    _currentScientistTrashDisplay = _service.getList(2);
    ui->scientist_trash_table->setRowCount(_currentScientistTrashDisplay.size());

    for(unsigned int i = 0; i < _currentScientistTrashDisplay.size(); i++)
    {
        QString fullName =  QString::fromStdString(_currentScientistTrashDisplay[i].fullName);
        QString gender =  QString::fromStdString(_currentScientistTrashDisplay[i].gender);
        QString YoB =  QString::number(_currentScientistTrashDisplay[i].yearOfBirth);
        QString YoD =  QString::number(_currentScientistTrashDisplay[i].yearOfDeath);

        ui->scientist_trash_table->setItem(i, 0, new QTableWidgetItem(fullName));
        ui->scientist_trash_table->setItem(i, 1, new QTableWidgetItem(gender));
        ui->scientist_trash_table->setItem(i, 2, new QTableWidgetItem(YoB));

        if(YoD != "0")
        {
            ui->scientist_trash_table->setItem(1, 3, new QTableWidgetItem(YoD));
        }
    }
}

void MainWindow::on_scientist_search_textChanged(const QString &arg1)
{
    ui->scientist_table->clearContents();
    _tempInput.clear();
    string keyword = arg1.toStdString();
    _service.searchScientists(_tempInput, keyword);
    _currentScientistDisplay = _tempInput;
    ui->scientist_table->setRowCount(_currentScientistDisplay.size());
    for(unsigned int i = 0; i < _currentScientistDisplay.size(); i++)
    {
        QString fullName =  QString::fromStdString(_tempInput[i].fullName);
        QString gender =  QString::fromStdString(_tempInput[i].gender);
        QString YoB =  QString::number(_tempInput[i].yearOfBirth);
        QString YoD =  QString::number(_tempInput[i].yearOfDeath);

        ui->scientist_table->setItem(i, 0, new QTableWidgetItem(fullName));
        ui->scientist_table->setItem(i, 1, new QTableWidgetItem(gender));
        ui->scientist_table->setItem(i, 2, new QTableWidgetItem(YoB));

        if(YoD != "0")
        {
            ui->scientist_table->setItem(i, 3, new QTableWidgetItem(YoD));
        }

    }
    _tempInput.clear();
}

void MainWindow::on_scientist_button_clicked()
{
    _tempInput.clear();
    bool error = false;
    ui->scientist_name_error->clear();
    ui->scientist_gender_error->clear();
    ui->scientist_yob_error->clear();
    ui->scientist_yod_error->clear();
    QString fullName = ui->scientist_name_input->text();
    QString gender = ui->scientist_gender_input->text();
    QString yoB = ui->scientist_yob_input->text();
    QString yoD = ui->scientist_yod_input->text();

    if(fullName.isEmpty())
    {
        error = true;
        ui->scientist_name_error->setText("<span style='color: #b20c0c'>Name can not be empty!</span>");
    }
    if(gender.isEmpty())
    {
        ui->scientist_gender_error->setText("<span style='color: #b20c0c'>Gender can not be empty!</span>");
        error = true;
    }
    if(yoB.isEmpty())
    {
        ui->scientist_yob_error->setText("<span style='color: #b20c0c'>Scientist must have been born!</span>");
        error = true;
    }
    if(yoD.isEmpty())
    {
        yoD = "0";
    }

    if(!error)
    {

        TolPers pers;
        pers.fullName = fullName.toStdString();
        pers.gender = gender.toStdString();
        pers.yearOfBirth = yoB.toInt(0, 10);
        pers.yearOfDeath = yoD.toInt(0, 10);
        _tempInput.push_back(pers);
        _service.addToList(_tempInput);
        _tempInput.clear();
        displayAllScientists();
        ui->scientist_name_input->clear();
        ui->scientist_gender_input->clear();
        ui->scientist_yob_input->clear();
        ui->scientist_yod_input->clear();
    }
}

void MainWindow::on_scientist_delete_clicked()
{
    _tempInput.clear();
    int currentlySelectedScientist = ui->scientist_table->currentIndex().row();
    int scientistID = _currentScientistDisplay[currentlySelectedScientist].ID;

    TolPers pers;
    pers.fullName = _currentScientistDisplay[currentlySelectedScientist].fullName;
    pers.gender = _currentScientistDisplay[currentlySelectedScientist].gender;
    pers.yearOfBirth = _currentScientistDisplay[currentlySelectedScientist].yearOfBirth;
    pers.yearOfDeath = _currentScientistDisplay[currentlySelectedScientist].yearOfDeath;
    _tempInput.push_back(pers);

    _service.deleteFromList(1, scientistID, _tempInput);
    _tempInput.clear();
    ui->scientist_search->clear();
    displayAllScientists();
    displayScientistTrash();

    ui->scientist_delete->setEnabled(false);
}


void MainWindow::on_scientist_table_clicked()
{
    ui->scientist_delete->setEnabled(true);
}

void MainWindow::on_computer_search_textChanged(const QString &arg1)
{
    ui->computer_table->clearContents();
    _tempCompInput.clear();
    string keyword = arg1.toStdString();
    _service.searchComputers(_tempCompInput, keyword);
    _currentComputerDisplay = _tempCompInput;
    ui->computer_table->setRowCount(_currentComputerDisplay.size());
    for(unsigned int i = 0; i < _currentComputerDisplay.size(); i++)
    {
        QString name =  QString::fromStdString(_currentComputerDisplay[i].name);
        QString type =  QString::fromStdString(_currentComputerDisplay[i].type);
        QString built =  QString::number(_currentComputerDisplay[i].built);
        QString year =  QString::number(_currentComputerDisplay[i].year);

        ui->computer_table->setItem(i, 0, new QTableWidgetItem(name));
        ui->computer_table->setItem(i, 1, new QTableWidgetItem(type));
        ui->computer_table->setItem(i, 2, new QTableWidgetItem(built));

        if(built != "0")
        {
            ui->computer_table->setItem(i, 3, new QTableWidgetItem(year));
        }
    }
    _tempCompInput.clear();
}

void MainWindow::on_computer_button_clicked()
{
    _tempCompInput.clear();
    bool error = false;
    ui->computer_name_error->clear();
    ui->computer_type_error->clear();
    ui->computer_built_error->clear();
    ui->computer_year_error->clear();
    QString name = ui->computer_name_input->text();
    QString type = ui->computer_type_input->text();
    QString built = ui->computer_built_input->text();
    QString year = ui->computer_year_input->text();

    if(name.isEmpty())
    {
        error = true;
        ui->computer_name_error->setText("<span style='color: #b20c0c'>Name can not be empty!</span>");
    }
    if(type.isEmpty())
    {
        ui->computer_type_error->setText("<span style='color: #b20c0c'>Type can not be empty!</span>");
        error = true;
    }
    if(built.isEmpty())
    {
        ui->computer_built_error->setText("<span style='color: #b20c0c'>Was it built or not, fucknugget!</span>");
        error = true;
    }
    if(year.isEmpty())
    {
        year = "0";
    }

    if(!error)
    {

        TolComp comp;
        comp.name = name.toStdString();
        comp.type = type.toStdString();
        comp.built = built.toInt(0, 10);
        comp.year = year.toInt(0, 10);
        _tempCompInput.push_back(comp);
        _service.addToComp(_tempCompInput);
        _tempCompInput.clear();
        displayAllComputers();
        ui->computer_name_input->clear();
        ui->computer_type_input->clear();
        ui->computer_built_input->clear();
        ui->computer_year_input->clear();
    }
}

void MainWindow::on_computer_table_clicked(const QModelIndex &index)
{
    ui->computer_delete->setEnabled(true);
}

void MainWindow::on_computer_delete_clicked()
{
    _tempCompInput.clear();
    int currentlySelectedComputer = ui->computer_table->currentIndex().row();
    int computerID = _currentComputerDisplay[currentlySelectedComputer].ID;

    TolComp comp;
    comp.name = _currentComputerDisplay[currentlySelectedComputer].name;
    comp.type = _currentComputerDisplay[currentlySelectedComputer].type;
    comp.built =_currentComputerDisplay[currentlySelectedComputer].built;
    comp.year = _currentComputerDisplay[currentlySelectedComputer].year;
    _tempCompInput.push_back(comp);

    _service.deleteFromComp(1, computerID, _tempCompInput);
    _tempInput.clear();
    ui->scientist_search->clear();
    displayAllComputers();
    displayComputerTrash();

    ui->computer_delete->setEnabled(false);
}


void MainWindow::on_computer_trash_table_clicked(const QModelIndex &index)
{
    ui->computer_recover_button->setEnabled(true);
}

void MainWindow::on_scientist_trash_table_clicked(const QModelIndex &index)
{
    ui->scientist_recover_button->setEnabled(true);
}

void MainWindow::on_computer_recover_button_clicked()
{
    _tempCompInput.clear();
    int currentlySelectedComputer = ui->computer_trash_table->currentIndex().row();
    int computerID = _currentComputerTrashDisplay[currentlySelectedComputer].ID;

    TolComp comp;
    comp.name = _currentComputerTrashDisplay[currentlySelectedComputer].name;
    comp.type = _currentComputerTrashDisplay[currentlySelectedComputer].type;
    comp.built =_currentComputerTrashDisplay[currentlySelectedComputer].built;
    comp.year = _currentComputerTrashDisplay[currentlySelectedComputer].year;
    _tempCompInput.push_back(comp);

    _service.deleteFromComp(2, computerID, _tempCompInput);
    _tempCompInput.clear();
    displayAllComputers();
    displayComputerTrash();

    ui->computer_recover_button->setEnabled(false);
}

void MainWindow::on_scientist_recover_button_clicked()
{
    _tempInput.clear();
    int currentlySelectedScientist = ui->scientist_trash_table->currentIndex().row();
    int scientistID = _currentScientistTrashDisplay[currentlySelectedScientist].ID;

    TolPers pers;
    pers.fullName = _currentScientistTrashDisplay[currentlySelectedScientist].fullName;
    pers.gender = _currentScientistTrashDisplay[currentlySelectedScientist].gender;
    pers.yearOfBirth = _currentScientistTrashDisplay[currentlySelectedScientist].yearOfBirth;
    pers.yearOfDeath = _currentScientistTrashDisplay[currentlySelectedScientist].yearOfDeath;
    _tempInput.push_back(pers);

    _service.deleteFromList(2, scientistID, _tempInput);
    _tempInput.clear();
    displayAllScientists();
    displayScientistTrash();

    ui->scientist_recover_button->setEnabled(false);
}

void MainWindow::on_computer_empty_button_clicked()
{
    _service.emptyTrash(2);\
    displayComputerTrash();
}

void MainWindow::on_scientist_empty_button_clicked()
{
    _service.emptyTrash(1);
    displayScientistTrash();
}

void MainWindow::on_tabs_tabBarClicked(int index)
{
    if(index == 2)
    {
        _currentComputerDisplay.clear();
        _currentScientistDisplay.clear();
        QString item;

        _currentScientistDisplay = _service.getList(1);
        _currentComputerDisplay = _service.getCompList(1);
        for(unsigned int i = 0; i < _currentScientistDisplay.size(); i++)
        {
            item = QString::fromStdString(_currentScientistDisplay[i].fullName);
            ui->scientist_dropdown->addItem(item);

        }
        for(unsigned int i = 0; i < _currentComputerDisplay.size(); i++)
        {
            item = QString::fromStdString(_currentComputerDisplay[i].name);
            ui->computer_dropdown->addItem(item);
        }

        if(!_currentComputerDisplay.empty() && !_currentScientistDisplay.empty())
        {
            ui->link_button->setEnabled(true);
        }
        else
        {
            ui->link_button->setEnabled(false);
        }
    }
}

void MainWindow::on_link_button_clicked()
{
    _currentComputerDisplay.clear();
    _currentScientistDisplay.clear();
    _currentScientistDisplay = _service.getList(1);
    _currentComputerDisplay = _service.getCompList(1);
    int scientistI;
    int computerI;
    for(unsigned int i = 0; i < _currentScientistDisplay.size(); i++)
    {
        if(_currentScientistDisplay[i].fullName == ui->scientist_dropdown->currentText().toStdString())
        {
            scientistI = i;
        }
    }
    for(unsigned int i = 0; i < _currentComputerDisplay.size(); i++)
    {
        if(_currentComputerDisplay[i].name == ui->computer_dropdown->currentText().toStdString())
        {
            computerI = i;
        }
    }
    int scientistID = _currentScientistDisplay[scientistI].ID;
    int computerID = _currentComputerDisplay[computerI].ID;
    _service.linkPersonToComp(scientistID, computerID);
}

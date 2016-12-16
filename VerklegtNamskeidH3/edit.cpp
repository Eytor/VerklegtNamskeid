
#include "edit.h"
#include "ui_edit.h"

Edit::Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Edit)
{
    ui->setupUi(this);

}

Edit::~Edit()
{
    delete ui;
}

void Edit::on_buttonBox_accepted()
{
    QString name, gender, Yob, Yod;
    name=ui->scientist_edit_name->text();
    gender=ui->scientist_edit_gender->text();
    Yob=ui->scientist_edit_yob->text();
    Yod=ui->scientist_edit_yob->text();
    //_service.editPerson(_id, name, gender, Yob, Yod);
    //_main.editToService(name, gender, Yob, Yod);

}
void Edit::getCurrValues(int id, const QString name, const QString gender, const QString yob, const QString yod)
{
    _id = id;
    ui->scientist_edit_name->setText(name);
    ui->scientist_edit_gender->setText(gender);
    ui->scientist_edit_yob->setText(yob);
    ui->scientist_edit_yod->setText(yod);

}

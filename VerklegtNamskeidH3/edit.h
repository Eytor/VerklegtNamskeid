#ifndef EDIT_H
#define EDIT_H

#include <QDialog>

namespace Ui {
class Edit;
}

class Edit : public QDialog
{
    Q_OBJECT


public:
    explicit Edit(QWidget *parent = 0);
    ~Edit();
    void getCurrValues(const QString name, const QString gender, const QString yob, const QString yod);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Edit *ui;
};

#endif // EDIT_H

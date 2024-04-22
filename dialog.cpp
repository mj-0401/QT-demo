#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QMessageBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    // Connect Keyboard numbers
     connect(ui->btn_1, SIGNAL(clicked()), this, SLOT(onLetterButtonClicked()));
     connect(ui->btn_2, SIGNAL(clicked()), this, SLOT(onLetterButtonClicked()));

     updateLetterButtons();

     connect(ui->btn_11, SIGNAL(clicked()), this, SLOT(onLetterButtonClicked1()));
     connect(ui->btn_22, SIGNAL(clicked()), this, SLOT(onLetterButtonClicked1()));

     updateLetterButtons_1();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    qDebug() << "Page 1 is clicked";
}

void Dialog::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    qDebug() << "Page 2 is clicked";
}


void Dialog::on_back_clicked()
{
    qDebug() << "back button clicked";
    this->close();
}


void Dialog::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_back_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_enter_clicked()
{
    QString password = ui->lineEdit->text();

    if (password == "1") {
       qDebug() << "Correct password :)";
       emit engmodeenter();
        //this->close();

    } else {
        qDebug() << "Incorrect password! in Eng mode....";
        QMessageBox::warning(this, "Warning", "Please Enter correct Password...");

    }
    ui->lineEdit->clear();
    accept();
    ui->stackedWidget->setCurrentIndex(0);
}


void Dialog::on_enter_2_clicked()
{
    QString password = ui->lineEdit_2->text();
    if(password == "2"){
        qDebug() <<"Correct password :)";
        emit advmodeenter();

    }else{
        qDebug() << "Incorrect password :(";
        QMessageBox::warning(this, "Warning", "Please Enter correcrt password");

    }
    ui->lineEdit_2->clear();
    accept();
    ui->stackedWidget->setCurrentIndex(0);
}

void Dialog::updateLetterButtons()
{
    qDebug() << "Updating Letter Buttons...";

    // Update the appearance of all letter buttons based on Caps Lock state
    foreach (QPushButton *letterButton, findChildren<QPushButton*>()) {
        if (letterButton->text().length() == 1) {
            QChar character = letterButton->text().at(0); // Access the first character
//            if (character.isLetter()) {
//                QString updatedText = capsLockEnabled ? character.toUpper() : character.toLower();
//                letterButton->setText(shiftEnabled ? updatedText.toUpper() : updatedText);
//            }
        }
    }
}

void Dialog::onLetterButtonClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString letter = clickedButton->text();
        qDebug() << "Letter Button Clicked: " << letter;

//        if(shiftEnabled){   //for shift on function
//            letter = letter.toUpper();
//            shiftEnabled = true;
//        }
        ui->lineEdit->insert(letter);
//        if(!shiftEnabled){   //for shift off function
//            qDebug() << "Shift OFF";

            updateLetterButtons();
        }
    }

void Dialog::updateLetterButtons_1()
{
    qDebug() << "Updating Letter Buttons...";

    // Update the appearance of all letter buttons based on Caps Lock state
    foreach (QPushButton *letterButton, findChildren<QPushButton*>()) {
        if (letterButton->text().length() == 1) {
            QChar character = letterButton->text().at(0); // Access the first character

//            if (character.isLetter()) {
//                QString updatedText = capsLockEnabled ? character.toUpper() : character.toLower();
//                letterButton->setText(shiftEnabled ? updatedText.toUpper() : updatedText);
//            }

        }
    }
}

void Dialog::onLetterButtonClicked1()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        QString letter = clickedButton->text();
        qDebug() << "Letter Button Clicked: " << letter;

//        if(shiftEnabled){   //for shift on function
//            letter = letter.toUpper();
//            shiftEnabled = true;
//        }
        ui->lineEdit_2->insert(letter);
//        if(!shiftEnabled){   //for shift off function
//            qDebug() << "Shift OFF";
            updateLetterButtons_1();
        }
    }

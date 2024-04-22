#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog(this);
    connect(dialog, &Dialog::engmodeenter, this, &MainWindow::Engmodeclicked);
    connect(dialog, &Dialog::advmodeenter, this, &MainWindow::Advmodeclicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    qDebug() << "Login Clicked";
    QPoint mainWindowCenter = this->geometry().center();
    QPoint dialogTopLeft = mainWindowCenter - QPoint(dialog->width() / 2, dialog->height() / 2);
    dialog->move(dialogTopLeft);

    dialog->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint  | Qt::MSWindowsFixedSizeDialogHint);
    dialog->setWindowModality(Qt::WindowModal);
    dialog->show();
}

void MainWindow::Engmodeclicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::Advmodeclicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_4_clicked() //back emg mode
{
    qDebug() << "back to home";
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_5_clicked()  //back adv mode
{
     qDebug() << "back to home111";
     ui->stackedWidget->setCurrentIndex(0);
}


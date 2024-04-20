#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void engmodeenter();
    void advmodeenter();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_back_clicked();

    void on_back_2_clicked();

    void on_back_3_clicked();

    void on_enter_clicked();

    void on_enter_2_clicked();

    void updateLetterButtons();

    void onLetterButtonClicked();

    void updateLetterButtons_1();

    void onLetterButtonClicked1();


private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H

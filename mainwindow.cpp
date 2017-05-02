#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_00,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digit_pressed()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digit_pressed()));

    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_substract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));
    connect(ui->pushButton_power,SIGNAL(released()),this,SLOT(binary_operation_pressed()));

    ui->pushButton_add->setCheckable(true);
    ui->pushButton_substract->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
    ui->pushButton_power->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double lineNumber;
    QString newLine;

    if ((ui->pushButton_add->isChecked() || ui->pushButton_substract->isChecked() ||
            ui->pushButton_multiply->isChecked() || ui->pushButton_power->isChecked() || ui->pushButton_divide->isChecked()) && (!userIsTypingSecondNumber))
    {
        lineNumber = button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLine = QString::number(lineNumber,'g',15);
    }
    else
    {
        if(ui->lineEdit->text().contains('.') && button->text() == "0")
        {
            newLine= ui->lineEdit->text() + button->text();
        }
        else
        {
          lineNumber = (ui->lineEdit->text() + button->text()).toDouble();
          newLine = QString::number(lineNumber,'g',15);
        }

    }

    ui->lineEdit->setText(newLine);
}

void MainWindow::on_pushButton_point_released()
{
    ui->lineEdit->setText(ui->lineEdit->text()+ ".");
}

void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_substract->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);
    ui->pushButton_power->setChecked(false);

    userIsTypingSecondNumber = false;

    ui->lineEdit->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double lineNumber, secondNum;
    QString newline;

    secondNum = ui->lineEdit->text().toDouble();


    if (ui->pushButton_add->isChecked())
    {
        lineNumber = firstNum + secondNum;
        newline = QString::number(lineNumber,'g',15);
        ui->lineEdit->setText(newline);
        ui->pushButton_add->setChecked(false);

    }
    else if (ui->pushButton_substract->isChecked())
    {
        lineNumber = firstNum - secondNum;
        newline = QString::number(lineNumber,'g',15);
        ui->lineEdit->setText(newline);
        ui->pushButton_substract->setChecked(false);

    }
    else if (ui->pushButton_multiply->isChecked())
    {
        lineNumber = firstNum * secondNum;
        newline = QString::number(lineNumber,'g',15);
        ui->lineEdit->setText(newline);
        ui->pushButton_multiply->setChecked(false);

    }
    else if (ui->pushButton_divide->isChecked())
    {
        lineNumber = firstNum / secondNum;
        newline = QString::number(lineNumber,'g',15);
        ui->lineEdit->setText(newline);
        ui->pushButton_divide->setChecked(false);

    }
    else if (ui->pushButton_power->isChecked())
    {
        lineNumber = pow(firstNum, secondNum);
        newline = QString::number(lineNumber,'g',15);
        ui->lineEdit->setText(newline);
        ui->pushButton_power->setChecked(false);

    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    firstNum = ui->lineEdit->text().toDouble();

    button->setChecked(true);
}

#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>
#include <QRegularExpressionMatchIterator>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_edt_small_textChanged()
{

}


void MainWindow::on_convert_clicked()
{
    QString input = ui->edt_small->toPlainText();
    QString output= input.toUpper();
    ui->edt_capital->setPlainText(output);
}


void MainWindow::on_edt_capital_textChanged()
{

}

void MainWindow::calculateResult()
{
    float a = ui->edta->toPlainText().toFloat();
    float b = ui->edtb->toPlainText().toFloat();
    float c = ui->edtc->toPlainText().toFloat();
    float x = ui->edtx->toPlainText().toFloat();

    double result = (a * x * x) + (b * x) + c;
    ui->edtres->setPlainText(QString::number(result));
}

void MainWindow::on_edta_textChanged()
{
    calculateResult();
}


void MainWindow::on_edtb_textChanged()
{
    calculateResult();
}


void MainWindow::on_edtc_textChanged()
{
    calculateResult();
}


void MainWindow::on_edtx_textChanged()
{
    calculateResult();
}


void MainWindow::on_edtres_textChanged()
{

}
void MainWindow::calculatePolynomial()

{

    QString poly= ui->edtpoly->toPlainText();
    double x= ui->edt_x->toPlainText().toDouble();
    double result =0.0;


    poly.remove(" ");

    QRegularExpression re("([+-]?\\d*\\.?\\d*)(x\\^2|x)?");
    QRegularExpressionMatchIterator it= re.globalMatch(poly);

    while (it.hasNext())
    {
        QRegularExpressionMatch match=it.next();
        QString coeffStr= match.captured(1);
        QString varStr=match.captured(2);
        double coeff = 0;


        if (coeffStr == "+" || coeffStr == "-")

            coeff = (coeffStr == "+") ? 1 : -1;

        else if (!coeffStr.isEmpty())

            coeff = coeffStr.toDouble();

        else if (!varStr.isEmpty())
            coeff = 1;

        if (varStr == "x^2")

            result += coeff * x * x;
        else if (varStr == "x")

            result += coeff * x;
        else
            result += coeff;

    }

    ui->edt_res->setPlainText(QString::number(result));
}


void MainWindow::on_edtpoly_textChanged()
{
    calculatePolynomial();
}


void MainWindow::on_edt_x_textChanged()
{
   calculatePolynomial();
}


void MainWindow::on_edt_res_textChanged()
{

}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_edt_small_textChanged();

    void on_convert_clicked();

    void on_edt_capital_textChanged();

    void on_edta_textChanged();

    void on_edtb_textChanged();

    void on_edtc_textChanged();

    void on_edtx_textChanged();

    void on_edtres_textChanged();
    void calculateResult();
    void calculatePolynomial();
    void on_edtpoly_textChanged();

    void on_edt_x_textChanged();

    void on_edt_res_textChanged();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

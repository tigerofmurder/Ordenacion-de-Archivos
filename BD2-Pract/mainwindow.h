#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <read.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void actualizar();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    enum{
        REGISTRO,
        CUENTA,
        NOMBRE,
        SALDO
    };

    Read table;
};

#endif // MAINWINDOW_H

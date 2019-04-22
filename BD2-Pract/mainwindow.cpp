#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    QStringList titulos;
    titulos<<"REGISTRO"<<"CUENTA"<<"NOMBRE"<<"SALDO";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
    table.Lecture();

    ////////////////////////////////////////
    ui->tableWidget_2->setColumnCount(1);
    QStringList titu;
    titu<<"REGISTRO";
    ui->tableWidget_2->setHorizontalHeaderLabels(titu);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(0);
    table.Registre.clear();
    table.Delete.clear();
    ui->tableWidget_2->setRowCount(0);
    table.i=0;
    table.Lecture();
    for(auto it=table.Registre.begin();it!=table.Registre.end();it++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int fila = ui->tableWidget->rowCount()-1;
        ui->tableWidget->setItem(fila,REGISTRO,new QTableWidgetItem(QString::number((*(it))->registro)));
        ui->tableWidget->setItem(fila,CUENTA,new QTableWidgetItem((*(it))->cuenta));
        ui->tableWidget->setItem(fila,NOMBRE,new QTableWidgetItem((*(it))->name));
        ui->tableWidget->setItem(fila,SALDO,new QTableWidgetItem((*(it))->saldo));
    }

}

void MainWindow::on_pushButton_2_clicked()
{

    table.Delete1(ui->lineEdit->text().toInt());
    ui->lineEdit->clear();
    actualizar();
}

void MainWindow::actualizar(){
    ui->tableWidget->setRowCount(0);
    for(auto it=table.Registre.begin();it!=table.Registre.end();it++){
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        int fila = ui->tableWidget->rowCount()-1;
        ui->tableWidget->setItem(fila,REGISTRO,new QTableWidgetItem(QString::number((*(it))->registro)));
        ui->tableWidget->setItem(fila,CUENTA,new QTableWidgetItem((*(it))->cuenta));
        ui->tableWidget->setItem(fila,NOMBRE,new QTableWidgetItem((*(it))->name));
        ui->tableWidget->setItem(fila,SALDO,new QTableWidgetItem((*(it))->saldo));
    }

    ui->tableWidget_2->setRowCount(0);
    for(auto it=table.Delete.begin();it!=table.Delete.end();it++){
        ui->tableWidget_2->insertRow(ui->tableWidget_2->rowCount());
        int fila = ui->tableWidget_2->rowCount()-1;
        ui->tableWidget_2->setItem(fila,REGISTRO,new QTableWidgetItem(QString::number((*(it))->registro)));
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    table.Delete2(ui->lineEdit_2->text().toInt());
    ui->lineEdit_2->clear();
    actualizar();
}

void MainWindow::on_pushButton_5_clicked()
{
    table.insert(ui->lineEdit_4->text().toStdString(),ui->lineEdit_4->text().toStdString(),ui->lineEdit_4->text().toStdString());
    ui->lineEdit_4->clear();ui->lineEdit_5->clear();ui->lineEdit_6->clear();
    actualizar();
}

void MainWindow::on_pushButton_4_clicked()
{
    table.Delete3(ui->lineEdit_3->text().toInt());
    ui->lineEdit_3->clear();
    actualizar();
}

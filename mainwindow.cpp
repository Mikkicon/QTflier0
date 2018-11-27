#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <stdlib.h>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->fgConsoleOutput->setStyleSheet("background-color: black; color: green; font-family: Consolas; font: 18px;");
    ui->halConsoleOutput->setStyleSheet("background-color: black; color: green; font-family: Consolas; font: 18px;");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    if(ui->start->text()=="STOP"){
        ui->start->setText("START");
        ui->fgConsoleOutput->clear();
        ui->halConsoleOutput->clear();
    }else{

        ui->start->setText("STOP");
        QProcess *process = new QProcess(this);
        QString file = ui->pathInput->text().isEmpty()? "C:/Users/USER/Desktop/C++/QTflier0/fgfs.exe" :ui->pathInput->text();
        try {
            QStringList arguments;
            arguments<< "--generic=socket,out,"+ui->frInput->text() +","+ui->halIpInput->text()+","+ui->halPortInput->text()+",udp,"+ui->trProtInput->text()<<
                        "--generic=socket,in,"+ui->frInput->text() +","+ui->fgIpInput->text()+","+ui->fgPortInput->text()+",udp,"+ui->ReadProtInput->text() ;
//            arguments <<ui->fgIpInput->text()<< ui->halIpInput->text();
            process->start(file,arguments);
        } catch (std::exception e) {
            qDebug() << e.what();
        }

            process->waitForReadyRead();
            QString s = process->readAll();
            int x = s.indexOf("FG");
            QString s1 = s.mid(x,s.length()-x-1);
            x = s.indexOf("FG");
            s = s.mid(0,x);
            ui->fgConsoleOutput->append(s1);
            ui->halConsoleOutput->append(s);
    }
}

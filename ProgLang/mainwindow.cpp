#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QString>
#include <QListWidget>
#include <QIcon>


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

void MainWindow::on_pushDelete_clicked()
{
    qDeleteAll(ui->listWidget->selectedItems());
}

void MainWindow::on_addPush_clicked()
{
    QListWidgetItem* items = new QListWidgetItem(QIcon(":logos/logos/reddot.png"),
                                QInputDialog::getText(this,"Добавление языка","Язык программирования"));
    ui->listWidget->addItem(items);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1) {
        ui->listWidget->setViewMode(QListWidget::IconMode);
    } else {
        ui->listWidget->setViewMode(QListWidget::ListMode);
        ui->listWidget->setMovement(QListView::Snap);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    close();
}

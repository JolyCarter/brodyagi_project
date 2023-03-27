#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QtWidgets/qlabel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->labelYourTask->setText("У вас нет задач.");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()  // нажатие на кнопку добавить
{

    QString str = ui->lineEdit->text();



    if (str == "") {
        return;
    }

    ui->listWidget->addItem("- "+ str);
    ui->lineEdit->clear();

}


void MainWindow::on_pushButtonDel_clicked() // нажатие на кнопку удалить
{
    QListWidgetItem *it = ui->listWidget->item(ui->listWidget->currentRow());
    delete it;

    if (ui->listWidget->count() == 0) {
        ui->labelYourTask->setText("У вас нет задач.");
    }

}


void MainWindow::keyPressEvent(QKeyEvent* event) // распознавание нажатий
{
    if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
       ui->labelYourTask->setText("Ваши задачи:");
       on_pushButton_clicked();
    }
}

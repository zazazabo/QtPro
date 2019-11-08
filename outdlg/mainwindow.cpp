#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<qdebug.h>
#include <QStandardItemModel>
#include <QTextEncoder>
#include <QTextCodec>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked()
{

    New_window* pnew = new New_window;
    pnew->setModal(true);
    pnew->show();
    qDebug()<<"xxxxxxxxxxxxxxx";
//    pNewWind->show();

    //Dialog* d=new Dialog(this);
//    d->show();
//        QMessageBox::warning(NULL,"ok","bbb");
}

void MainWindow::on_pushButton_4_clicked()
{
    int val = ui->lineEdit->text().toInt();
    QString str=QString::number(val+1);
    ui->lineEdit->setText(str);
}

void MainWindow::on_pushButton_5_clicked()
{
    QString val = ui->lineEdit->text();
    qDebug()<<val;
}

void MainWindow::on_pushButton_7_clicked()
{
    int val = ui->textEdit->toPlainText().toInt();
     QString str=QString::number(val+1);
     ui->textEdit->setText(str);

}

void MainWindow::on_pushButton_6_clicked()
{
    QString str = ui->textEdit->toPlainText();
    qDebug()<<str;
}

void MainWindow::on_pushButton_2_clicked()
{
    New_window* pnew = new New_window;
    pnew->show();

}

void MainWindow::on_pushButton_clicked()
{
    ui->comboBox->clear();

    for (int i=0;i<10;i++) {
           QString str=QString::number(i+1);
           ui->comboBox->addItem(str,QVariant(i));
    }

}

void MainWindow::on_pushButton_8_clicked()
{
    QString text = ui->comboBox->currentText();
    int  index = ui->comboBox->currentIndex();
    QVariant  userdata =    ui->comboBox->currentData(Qt::UserRole);

    qDebug()<<text<<index<<userdata.toInt();

}

void MainWindow::on_pushButton_9_clicked()
{




    QStringList strlist;
    strlist.append("name");
    strlist.append("age");
    strlist.append("sex");
    QStandardItemModel*  itemModel = new QStandardItemModel(this);

    int nCount = strlist.size();
     for(int i = 0; i < nCount; i++)
     {
         QString  liststr = static_cast<QString>(strlist.at(i));
         QStandardItem *item = new QStandardItem(liststr);
        itemModel->appendRow(item);
     }
     ui->listView->setModel(itemModel);

}

void MainWindow::on_pushButton_10_clicked()
{

    QModelIndex index = ui->listView->currentIndex();
    int irow =  index.row();
    QVariant data = index.data();
    qDebug()<<index<<irow<<data.toString();



}

void MainWindow::on_pushButton_11_clicked()
{
    int row = ui->listView->currentIndex().row();
    ui->listView->model()->removeRow(row);
}

void MainWindow::on_pushButton_12_clicked()
{

}

void MainWindow::on_pushButton_15_clicked()
{
    QStandardItemModel* pItem = static_cast<QStandardItemModel*>(ui->listView->model());
     pItem->clear();
}

void MainWindow::on_pushButton_16_clicked()
{

     int row =ui->listView->currentIndex().row();
     if(row>0){
         QStandardItemModel* pItem = static_cast<QStandardItemModel*>(ui->listView->model());
         pItem->removeRow(row);
     }
}

void MainWindow::on_pushButton_18_clicked()
{
         int row =ui->listView->model()->rowCount();
         QString str=QString::number(row+1);
          QStandardItemModel* pItemModel = static_cast<QStandardItemModel*>(ui->listView->model());
          QStandardItem* pItem=new QStandardItem(str);
          pItemModel->appendRow(pItem);
}

void MainWindow::on_pushButton_17_clicked()
{
    int nrow = ui->listView->currentIndex().row();
     QString str=QString::number(nrow+1);
     QStandardItemModel* pItemModel = static_cast<QStandardItemModel*>(ui->listView->model());
     QStandardItem* pItem=new QStandardItem(str);
     pItemModel->insertRow(nrow,pItem);
}

void MainWindow::on_pushButton_19_clicked()
{

    //准备数据模型

        QStandardItemModel *student_model = new QStandardItemModel();
        student_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("Name")));
        student_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("NO.")));
        student_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("Sex")));
        student_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("Age")));
        student_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("College")));


        student_model->setItem(0, 0, new QStandardItem(QString("zhengshang")));
        student_model->setItem(0, 1, new QStandardItem(QString("20120202")));
        student_model->setItem(0, 2, new QStandardItem("man"));
        student_model->setItem(0, 3, new QStandardItem("18"));
        student_model->setItem(0, 4, new QStandardItem("match school"));

        student_model->setItem(1, 0, new QStandardItem(QString("xiaoming")));
        student_model->setItem(1, 1, new QStandardItem(QString("20120202")));
        student_model->setItem(1, 2, new QStandardItem("woman"));
        student_model->setItem(1, 3, new QStandardItem("20"));
        student_model->setItem(1, 4, new QStandardItem("english school"));
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        //利用setModel()方法将数据模型与QTableView绑定
        ui->tableView->setModel(student_model);


}

void MainWindow::on_pushButton_20_clicked()
{
    int nrow= ui->tableView->currentIndex().row();
    qDebug()<<nrow;
    QModelIndex mModule = ui->tableView->currentIndex();
    qDebug()<<"row:"<<mModule.row()<<" colunm:"<<mModule.column()<<"data:"<<mModule.data();
}

void MainWindow::on_pushButton_21_clicked()
{
   QStandardItemModel* itemModel = static_cast<QStandardItemModel*>(ui->tableView->model());
   if(itemModel){
        QModelIndex mModule = ui->tableView->currentIndex();
        if(mModule.row()>=0){
                itemModel->removeRow(mModule.row());
        }
   }
}

void MainWindow::on_pushButton_22_clicked()
{
    QStandardItemModel* itemModel = static_cast<QStandardItemModel*>(ui->tableView->model());
    int allrow=itemModel->rowCount();
    itemModel->setItem(allrow, 0, new QStandardItem(QString("xiaoming_")+QString::number(allrow)));
    itemModel->setItem(allrow, 1, new QStandardItem(QString("20120202_")+QString::number(allrow)));
    itemModel->setItem(allrow, 2, new QStandardItem("woman_"+QString::number(allrow)));
    itemModel->setItem(allrow, 3, new QStandardItem("20_"+QString::number(allrow)));
    itemModel->setItem(allrow, 4, new QStandardItem("english school_"+QString::number(allrow)));
}

void MainWindow::on_pushButton_23_clicked()
{
    QStandardItemModel* itemModel = static_cast<QStandardItemModel*>(ui->tableView->model());
    itemModel->clear();

}

void MainWindow::on_pushButton_13_clicked()
{

}

void MainWindow::on_pushButton_24_clicked()
{
    QStandardItemModel* itemModel = static_cast<QStandardItemModel*>(ui->tableView->model());
    QModelIndex mModule = ui->tableView->currentIndex();
    int  allrow  = mModule.row();
    if(allrow>0){
         itemModel->setItem(allrow, 0, new QStandardItem(QString("xiaoming_")+QString::number(allrow)));
         itemModel->setItem(allrow, 1, new QStandardItem(QString("20120202_")+QString::number(allrow)));
         itemModel->setItem(allrow, 2, new QStandardItem("woman_"+QString::number(allrow)));
         itemModel->setItem(allrow, 3, new QStandardItem("20_"+QString::number(allrow)));
         itemModel->setItem(allrow, 4, new QStandardItem("english school_"+QString::number(allrow)));

         //itemModel->insertRow(allrow,)
    }

}

#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>

#define NAME_COL 0
#define ID_COL 1

void MyDialog::printSize()
{
qDebug() << "Size " << ui->tableView->horizontalHeader()->sectionSize(NAME_COL)
                << ui->tableView->horizontalHeader()->sectionSize(ID_COL)
                   ;
}

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);


    m_model = new QStandardItemModel(3, 2);

    // set header
    QStringList headList;
    headList << "File Name" << "ID";
    m_model->setHorizontalHeaderLabels(headList);
    ui->tableView->setModel(m_model);
    ui->tableView->setMouseTracking(true);

    // push data
//    QList<QStandardItem*> oneRow;
//    oneRow.append(new QStandardItem("/TableViewTest/home/test1/test2/test3/file4"));
//    oneRow.append(new QStandardItem("1"));

//    m_model->appendRow(oneRow);
//    oneRow.clear();
//    oneRow.append(new QStandardItem("/TableViewTest/home/name1/name2/name3/name4/file5"));
//    oneRow.append(new QStandardItem("1"));

//    m_model->appendRow(oneRow);

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 2; ++column) {
            if(column == 0) {
                QStandardItem *item = new QStandardItem(QString("/TableViewTest/home/name1/name2/name3/name4/file %0").arg(row));
//                qDebug() << item->data().toString() << "|" << item->data(Qt::DisplayRole).toString();
                item->setData(QString("/TableViewTest/home/name1/name2/name3/name4/file %0").arg(row), Qt::UserRole+1);
                item->setData(QString("/TableViewTest/home/name1/name2/name3/name4/file %0").arg(row), Qt::ToolTipRole);
                m_model->setItem(row, column, item);
            } else {
                QStandardItem *item = new QStandardItem(QString("%0").arg(row));
                item->setData(QString("%0").arg(row), Qt::UserRole+1);
                item->setData(QString("%0").arg(row), Qt::ToolTipRole);
                m_model->setItem(row, column, item);
            }
        }
    }

    // set property

    ui->tableView->horizontalHeader()->setResizeMode(NAME_COL, QHeaderView::Fixed);
    ui->tableView->horizontalHeader()->setResizeMode(ID_COL, QHeaderView::Fixed);
    qDebug() << this->geometry().width();


    ui->tableView->horizontalHeader()->resizeSection(ID_COL, 100);
    ui->tableView->horizontalHeader()->resizeSection(NAME_COL, geometry().width() - 100);
    printSize();
//    ui->tableView->resizeColumnToContents(NAME_COL);
//    printSize();
}

MyDialog::~MyDialog()
{
    delete ui;
}
static int resize_count = 0;
void MyDialog::auto_adjust_length()
{
    qDebug() << "auto_adjust_length " << resize_count++;
    printSize();

    ui->tableView->horizontalHeader()->resizeSection(ID_COL, 100);
    ui->tableView->horizontalHeader()->resizeSection(NAME_COL, geometry().width() - 100);

    for(int r=0; r<m_model->rowCount(); r++) {
        QString fullName = m_model->item(r,NAME_COL)->data(Qt::ToolTipRole).toString();
        int width = ui->tableView->columnWidth(NAME_COL);
        QString elidedString = ui->tableView->fontMetrics().elidedText(fullName,Qt::ElideMiddle, width-4);

//        qDebug() << elidedString;

        m_model->item(r,NAME_COL)->setData(elidedString, Qt::DisplayRole);
    }
}
void MyDialog::resizeEvent(QResizeEvent *event)
{

    auto_adjust_length();
    QDialog::resizeEvent(event);
}

void MyDialog::mouseDoubleClickEvent(QMouseEvent * event)
{
    auto_adjust_length();
    printSize();
}

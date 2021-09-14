#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "widgetfactory.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotValueChanged(int)));

    slotValueChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotValueChanged(int index)
{
    qDebug() << "spin index changed";
    QWidget* widget = ui->stackedWidget->widget(index);
    if(widget == NULL) {
        widget = new QWidget(this);
        ui->stackedWidget->insertWidget(index, widget);
    }
    ui->stackedWidget->setCurrentIndex(index);

    WidgetFactory factory;
    factory.createWidget(widget, index);
}

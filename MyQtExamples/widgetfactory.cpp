#include "widgetfactory.h"
#include <QLineEdit>
#include <QVBoxLayout>
WidgetFactory::WidgetFactory(QWidget *parent) : QWidget(parent)
{

}

void WidgetFactory::createWidget(QWidget* widget, int index)
{
    switch(index) {
    case 0:
        return makeWidget0(widget);
        break;
    default:
        break;
    }
    return;
}

void WidgetFactory::makeWidget0(QWidget* widget)
{
    static bool maked = false;
    maked = true;
    if(widget == NULL) return;
    QLayout* layout = new QVBoxLayout(widget);
    widget->setLayout(layout);

    QLineEdit* le = new QLineEdit(widget);
    QLineEdit* le2 = new QLineEdit(widget);
    layout->addWidget(le);
    layout->addWidget(le2);
    return;
}

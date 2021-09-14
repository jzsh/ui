#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include <QWidget>

class WidgetFactory : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetFactory(QWidget *parent = NULL);
    void createWidget(QWidget* widget, int index);
    void makeWidget0(QWidget* widget);
signals:

public slots:
};

#endif // WIDGETFACTORY_H

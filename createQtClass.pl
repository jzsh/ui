#!/usr/bin/perl

use strict;
use warnings;

my $scriptName = $0;
my $total = $#ARGV + 1;
my $counter = 1;
print "Total args passed to $scriptName : $total\n";
foreach my $a (@ARGV) {
    print "Arg # $counter : $a\n";
    $counter++;
}
############## Parse
our $className = $ARGV[0];
our $baseClassName = $ARGV[1];
our $noui = 0;
while ($#ARGV > -1) {
    if($ARGV[0] =~ /-noui/) {
        $noui = 1;
        shift;
    } else {
        shift;
    }
}


#### Cpp file
sub genCPP {
    my $fileContent = << "END_MESSAGE";
#include "$className.h"
#include "ui_$className.h"

$className::$className(QWidget *parent) :
$baseClassName(parent),
    ui(new Ui::$className)
{
    ui->setupUi(this);
}


${className}::~${className}()
{
    delete ui;
}

END_MESSAGE

    # write to file
    print $fileContent;
    open(fCPP, ">$className.cpp");
    print fCPP $fileContent;
    close fCPP;

}

# generate header
sub genH {
my $fileContent = << "END_MESSAGE";
#ifndef ${className}_H
#define ${className}_H

#include <${baseClassName}>

namespace Ui {
    class $className;
};


class $className : public $baseClassName
{
    Q_OBJECT

public:
    explicit $className(QWidget *parent = 0);
    ~$className();

private slots:

private:
    Ui::$className *ui;
};

#endif
END_MESSAGE

    # write to file
    open(fH, ">$className.h") or die("open fail");
    print fH $fileContent;
    close fH;

}

sub genMain {
    my $main ="
#include <QApplication>
#include \"$className.h\"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    $className m;
    m.show();
    return a.exec();
}
";
    open(fMain, ">main.cpp") or die("open fail");
    print fMain $main;
    close fMain;
}


sub genUI {
my $uiString = << "END_MESSAGE";
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>$className</class>
 <widget class="QWidget" name="$className">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Form</string>
  </property>
 </widget>
 <resources/>
 <connections/>
</ui>
END_MESSAGE

open(fp, ">$className.ui");
print fp $uiString;
close fp;
}
if($noui != 1) {
    `touch $className.ui`
}

genCPP();
genH();
genUI();
genMain();



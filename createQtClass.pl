#!/usr/bin/perl

my $scriptName = $0;
my $total = $#ARGV + 1;
my $counter = 1;
print "Total args passed to $scriptName : $total\n";
foreach my $a (@ARGV) {
	print "Arg # $counter : $a\n";
	$counter++;
}

$className = $ARGV[0];
$baseClassName = $ARGV[1];

#### Cpp file
sub genCPP {
	open(fCPP, ">$className.cpp");
	
	print fCPP "#include \"$className.h\"\n";
	print fCPP "#include \"ui_$className.h\"\n";

	print fCPP "$className::$className(QWidget *parent) :
$baseClassName(parent),
    ui(new Ui::$className)
{
    ui->setupUi(this);
}
";

	print fCPP "${className}::~${className}()
{
    delete ui;
}
";

}

sub genH {
	open(fH, ">$className.h") or die("open fail");
	print fH "#ifndef ${className}_H
#define ${className}_H
";

	print fH "#include <${baseClassName}>\n";

	print fH "namespace Ui {
class $className;
};
";

	print fH "
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

";

	print fH "#endif";

}

sub genMain {
	open(fMain, ">main.cpp") or die("open fail");
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
	print fMain $main;
}


genCPP();
genH();
genMain();



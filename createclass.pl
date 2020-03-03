#!/usr/bin/perl

print "@ARGV\n"; 
$fileName = $ARGV[0];
$className = $ARGV[0];
$baseClassName = $ARGV[1];

open(fH, ">$className.h") or die("open fail");
open(fCPP, ">$className.cpp");

print fH "#ifndef ${className}_H
#define ${className}_H
";

### include
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

#### Cpp file
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


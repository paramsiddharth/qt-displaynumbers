#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QWidget>
#include <string>

#include "mywin.h"

MyWin::MyWin(QMainWindow* parent): QMainWindow(parent) {
	quit = new QPushButton(tr("Quit"));
	quit->setFont(QFont("Times", 18, QFont::Bold));

	lcd = new QLCDNumber(2);
	lcd->setSegmentStyle(QLCDNumber::Filled);
	lcd->display(1);

	spinbox = new QSpinBox;
	spinbox->setRange(1, 15);
	spinbox->setValue(1);

	QPushButton* btnBin = new QPushButton(tr("Binary")),
		* btnOct = new QPushButton(tr("Octal")),
		* btnDec = new QPushButton(tr("Decimal")),
		* btnHex = new QPushButton(tr("Hexadecimal"));

	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(spinbox, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
	connect(btnBin, SIGNAL(clicked()), this, SLOT(handleBin()));
	connect(btnOct, SIGNAL(clicked()), this, SLOT(handleOct()));
	connect(btnDec, SIGNAL(clicked()), this, SLOT(handleDec()));
	connect(btnHex, SIGNAL(clicked()), this, SLOT(handleHex()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(quit);
	layout->addWidget(lcd);
	layout->addWidget(spinbox);
	QHBoxLayout* buttons = new QHBoxLayout;
	buttons->addWidget(btnBin);
	buttons->addWidget(btnOct);
	buttons->addWidget(btnDec);
	buttons->addWidget(btnHex);
	layout->addLayout(buttons);

	QWidget* widget = new QWidget;
	widget->setLayout(layout);
	setCentralWidget(widget);
}

void MyWin::handleBin() {
	lcd->setMode(QLCDNumber::Bin);
	lcd->setDigitCount(4);
	lcd->display(spinbox->value());
}

void MyWin::handleOct() {
	lcd->setMode(QLCDNumber::Oct);
	lcd->setDigitCount(2);
	lcd->display(spinbox->value());
}

void MyWin::handleDec() {
	lcd->setMode(QLCDNumber::Dec);
	lcd->setDigitCount(2);
	lcd->display(spinbox->value());
}

void MyWin::handleHex() {
	lcd->setMode(QLCDNumber::Hex);
	lcd->setDigitCount(1);
	lcd->display(spinbox->value());
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MyWin primary;
	primary.show();
	return app.exec();
}
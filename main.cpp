#include <QApplication>
#include <QFont>
#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QWidget>
#include <string>

#include "mywidget.h"

MyWidget::MyWidget(QWidget* parent): QWidget(parent) {
	quit = new QPushButton(tr("Quit"));
	quit->setFont(QFont("Times", 18, QFont::Bold));

	lcd = new QLCDNumber(2);
	lcd->setSegmentStyle(QLCDNumber::Filled);
	// lcd->setMode(QLCDNumber::Bin);
	// lcd-setDigitCount(4);

	slider = new QSlider(Qt::Horizontal);
	slider->setRange(1, 10);
	slider->setValue(1);

	QPushButton* btnBin = new QPushButton(tr("Binary")),
		* btnOct = new QPushButton(tr("Octal")),
		* btnDec = new QPushButton(tr("Decimal")),
		* btnHex = new QPushButton(tr("Hexadecimal"));

	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));
	connect(btnBin, SIGNAL(clicked()), this, SLOT(handleBin()));
	connect(btnOct, SIGNAL(clicked()), this, SLOT(handleOct()));
	connect(btnDec, SIGNAL(clicked()), this, SLOT(handleDec()));
	connect(btnHex, SIGNAL(clicked()), this, SLOT(handleHex()));

	QVBoxLayout* layout = new QVBoxLayout;
	layout->addWidget(quit);
	layout->addWidget(lcd);
	layout->addWidget(slider);
	QHBoxLayout* buttons = new QHBoxLayout;
	buttons->addWidget(btnBin);
	buttons->addWidget(btnOct);
	buttons->addWidget(btnDec);
	buttons->addWidget(btnHex);
	layout->addLayout(buttons);
	setLayout(layout);
}

void MyWidget::handleBin() {
	lcd->setMode(QLCDNumber::Bin);
	lcd->setDigitCount(4);
	lcd->display(slider->value());
}

void MyWidget::handleOct() {
	lcd->setMode(QLCDNumber::Oct);
	lcd->setDigitCount(2);
	lcd->display(slider->value());
}

void MyWidget::handleDec() {
	lcd->setMode(QLCDNumber::Dec);
	lcd->setDigitCount(2);
	lcd->display(slider->value());
}

void MyWidget::handleHex() {
	lcd->setMode(QLCDNumber::Hex);
	lcd->setDigitCount(1);
	lcd->display(slider->value());
}

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MyWidget widget;
	widget.show();
	return app.exec();
}
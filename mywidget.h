#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QLCDNumber>
#include <QPushButton>
#include <QSlider>
#include <QWidget>

class MyWidget: public QWidget {
	Q_OBJECT // Requirement for customized slots to work
	public:
		MyWidget(QWidget* parent = nullptr);
		
	private slots:
		void handleBin();
		void handleOct();
		void handleDec();
		void handleHex();
		
	private:
		QLCDNumber* lcd = nullptr;
		QSlider* slider = nullptr;
		QPushButton* quit;
};

#endif
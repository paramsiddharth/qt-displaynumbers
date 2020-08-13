#ifndef MYWIN_H
#define MYWIN_H

#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>
#include <QMainWindow>

namespace ui { class MyWin; }

class MyWin: public QMainWindow {
	Q_OBJECT // Requirement for customized slots to work
	public:
		MyWin(QMainWindow* parent = nullptr);
		
	private slots:
		void handleBin();
		void handleOct();
		void handleDec();
		void handleHex();
		
	private:
		QLCDNumber* lcd = nullptr;
		QSpinBox* spinbox = nullptr;
		QPushButton* quit;
};

#endif
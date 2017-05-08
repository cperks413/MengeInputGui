#include "MengeInputGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MengeInputGUI *w = new MengeInputGUI;
	w->show();
	return a.exec();
}

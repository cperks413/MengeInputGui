#pragma once
#include <QtWidgets/QMainWindow>
#include <QPushButton>
#include <QGridLayout>
#include "QSpinBox.h"
#include <MainDisplay.h>

class MengeInputGUI : public QMainWindow
{
	Q_OBJECT
public:
	MengeInputGUI(QWidget *parent = Q_NULLPTR);
	QGridLayout *windowLayout;
	QWidget* mainWidget;
	MainDisplay* md;
	void resetAllButtons();
	QPushButton* selectButton1;
	QPushButton* selectButton2;
	QPushButton* selectButton3;
	QPushButton* selectButton4;
	QPushButton* selectButton5;
	QPushButton* selectButton6;
	QPushButton* selectButton7;
	QPushButton* selectButton8;
	QPushButton* selectButton9;
	QPushButton* createButton;
	QLineEdit* fileNameBox;

	QSpinBox* spinBox1;
	QSpinBox* spinBox2;
	QSpinBox* spinBox3;
	QSpinBox* spinBox4;
	QSpinBox* spinBox5;
	QSpinBox* spinBox6;
	QSpinBox* spinBox7;
	QSpinBox* spinBox8;
	std::vector<QSpinBox*> spinBoxVector;

private slots:
	void createButtonPressed();
	void selectButtonPressed();
};

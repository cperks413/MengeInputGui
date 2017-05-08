#include "MengeInputGUI.h"
#include "Writer.h"
#include "AgentGroup.h"
#include "QButtonWidget.h"
#include "qlineedit.h"
#include <fstream>
#include <iostream>
#include <sstream>

MengeInputGUI::MengeInputGUI(QWidget *parent)
	: QMainWindow(parent)
{
	md = new MainDisplay(this);

	mainWidget = new QWidget;
	selectButton1 = new QPushButton("Agent Group 1 Spawn");
	selectButton2 = new QPushButton("Agent Group 1 Destination");
	selectButton3 = new QPushButton("Agent Group 2 Spawn");
	selectButton4 = new QPushButton("Agent Group 2 Destination");
	selectButton5 = new QPushButton("Agent Group 3 Spawn");
	selectButton6 = new QPushButton("Agent Group 3 Destination");
	selectButton7 = new QPushButton("Agent Group 4 Spawn");
	selectButton8 = new QPushButton("Agent Group 4 Destination");
	selectButton9 = new QPushButton("Obstacles");
	createButton = new QPushButton("Create");
	fileNameBox = new QLineEdit();

	spinBox1 = new QSpinBox();
	spinBox2 = new QSpinBox();
	spinBox3 = new QSpinBox();
	spinBox4 = new QSpinBox();
	spinBox5 = new QSpinBox();
	spinBox6 = new QSpinBox();
	spinBox7 = new QSpinBox();
	spinBox8 = new QSpinBox();
	spinBox8 = new QSpinBox();

	spinBoxVector.push_back(spinBox1);
	spinBoxVector.push_back(spinBox2);
	spinBoxVector.push_back(spinBox3);
	spinBoxVector.push_back(spinBox4);
	spinBoxVector.push_back(spinBox5);
	spinBoxVector.push_back(spinBox6);
	spinBoxVector.push_back(spinBox7);
	spinBoxVector.push_back(spinBox8);

	windowLayout = new QGridLayout(NULL);

	selectButton1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton3->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton4->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton5->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton6->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton7->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton8->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	selectButton9->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	createButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	selectButton1->setCheckable(true);
	selectButton2->setCheckable(true);
	selectButton3->setCheckable(true);
	selectButton4->setCheckable(true);
	selectButton5->setCheckable(true);
	selectButton6->setCheckable(true);
	selectButton7->setCheckable(true);
	selectButton8->setCheckable(true);
	selectButton9->setCheckable(true);

	connect(selectButton1, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton2, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton3, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton4, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton5, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton6, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton7, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton8, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(selectButton9, SIGNAL(released()), this, SLOT(selectButtonPressed()));
	connect(createButton, SIGNAL(released()), this, SLOT(createButtonPressed()));

	windowLayout->addWidget(selectButton1, 0, 0, 2, 1);
	windowLayout->addWidget(selectButton2, 0, 1, 2, 1);
	windowLayout->addWidget(selectButton3, 2, 0, 2, 1);
	windowLayout->addWidget(selectButton4, 2, 1, 2, 1);
	windowLayout->addWidget(selectButton5, 4, 0, 2, 1);
	windowLayout->addWidget(selectButton6, 4, 1, 2, 1);
	windowLayout->addWidget(selectButton7, 6, 0, 2, 1);
	windowLayout->addWidget(selectButton8, 6, 1, 2, 1);
	windowLayout->addWidget(selectButton9, 8, 0, 1, 3);
	windowLayout->addWidget(createButton, 9, 4, 1, 1);
	windowLayout->addWidget(fileNameBox, 9, 0, 1, 4);

	windowLayout->addWidget(spinBox1, 0, 2, 1, 1);
	windowLayout->addWidget(spinBox2, 1, 2, 1, 1);
	windowLayout->addWidget(spinBox3, 2, 2, 1, 1);
	windowLayout->addWidget(spinBox4, 3, 2, 1, 1);
	windowLayout->addWidget(spinBox5, 4, 2, 1, 1);
	windowLayout->addWidget(spinBox6, 5, 2, 1, 1);
	windowLayout->addWidget(spinBox7, 6, 2, 1, 1);
	windowLayout->addWidget(spinBox8, 7, 2, 1, 1);

	windowLayout->addWidget(md, 0, 3, 9, 2);
	mainWidget->setLayout(windowLayout);
	setCentralWidget(mainWidget);
	md->update();
}

void MengeInputGUI::createButtonPressed()
{
	Writer w = Writer();
	std::string str = fileNameBox->text().toStdString();
	const char* p = str.c_str();
	if (fileNameBox->text().isEmpty())
	{
		w.setFolderName("testFolder");
	}
	else {
		w.setFolderName(p);
	}

	std::ofstream errorFile;
	errorFile.open("error.txt");

	errorFile << p;

	errorFile << "step 1\n";
	for (int i = 0; i < md->squareList.size(); i+=2)
	{
		if (md->squareList.at(i) != Square(0, 0, 0, 0) && md->squareList.at(i + 1) != Square(0, 0, 0, 0))
		{
			QSpinBox* firstSpinBox = spinBoxVector.at(i);
			QSpinBox* secondSpinBox = spinBoxVector.at(i + 1);

			AgentGroup ag = AgentGroup(md->squareList.at(i).enlarge(), md->squareList.at(i + 1).enlarge(), firstSpinBox->value(), secondSpinBox->value());
			Square mmmmm = md->squareList.at(i + 1);
			errorFile << mmmmm.x << "|" << mmmmm.y << "|" << mmmmm.offsetX << "|" << mmmmm.offsetY << "\n";
			mmmmm = md->squareList.at(i + 1).enlarge();
			errorFile << mmmmm.x << "|" << mmmmm.y << "|" << mmmmm.offsetX << "|" << mmmmm.offsetY << "\n";
			w.addAgentGroup(ag);
		}
	}
	errorFile << "step 2\n";
	for (int i = 0; i < md->obstacleList.size(); i++)
	{
		if (md->obstacleList.at(i) != Square(0, 0, 0, 0))
		{
			w.addObstacle(md->obstacleList.at(i).enlarge());
		}
	}
	errorFile << "step 3\n";
	w.write();
}

void MengeInputGUI::resetAllButtons()
{
	selectButton1->setChecked(false);
	selectButton2->setChecked(false);
	selectButton3->setChecked(false);
	selectButton4->setChecked(false);
	selectButton5->setChecked(false);
	selectButton6->setChecked(false);
	selectButton7->setChecked(false);
	selectButton8->setChecked(false);
	selectButton9->setChecked(false);
}

void MengeInputGUI::selectButtonPressed()
{
	resetAllButtons();
	QObject* obj = sender();
	((QPushButton*)obj)->setChecked(true);
	if (obj == selectButton1)
	{
		md->state = 0;
	} else 	if (obj == selectButton2)
	{
		md->state = 1;
	}
	else if (obj == selectButton3)
	{
		md->state = 2;
	}
	else if (obj == selectButton4)
	{
		md->state = 3;
	}
	else if (obj == selectButton5)
	{
		md->state = 4;
	}
	else if (obj == selectButton6)
	{
		md->state = 5;
	}
	else if (obj == selectButton7)
	{
		md->state = 6;
	}
	else if (obj == selectButton8)
	{
		md->state = 7;
	}
	else if (obj == selectButton9)
	{
		md->state = 8;
	}
}
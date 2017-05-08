#include "QButtonWidget.h"
#include <math.h> 

QButtonWidget::QButtonWidget(QWidget *parent)
	: QWidget(this)
{
	parent = NULL;
	buttonLayout = new QGridLayout();
	for (int i = 0; i < 9; i++)
	{
		QPushButton* currButton = new QPushButton(std::to_string(i).c_str());
		buttonLayout->addWidget(currButton, i % 2, i / 2);
		buttonList.push_back(currButton);
	}
	setLayout(buttonLayout);
}
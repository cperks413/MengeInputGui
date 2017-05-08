#pragma once
#include <QWidget>
#include <QPushButton>
#include <QSpinBox>
#include <QGridLayout>
#include <vector>

class QButtonWidget : public QWidget
{
public:
	QButtonWidget(QWidget *parent = Q_NULLPTR);
	QGridLayout* buttonLayout;
	std::vector<QPushButton*> buttonList;
	std::vector<QSpinBox*> spinBoxList;
};
#pragma once
#include <qwidget.h>
#include <Square.h>
#include <vector>

class MainDisplay : public QWidget
{
public:
	MainDisplay(QWidget *parent = Q_NULLPTR);
	bool held;
	std::vector<Square> squareList;
	std::vector<Square> obstacleList;
	int xPress, yPress, xDist, yDist, state, obstNum;
	void MainDisplay::mousePressEvent(QMouseEvent * event);
	void MainDisplay::mouseMoveEvent(QMouseEvent * event);
	void MainDisplay::mouseReleaseEvent(QMouseEvent * event);
	void MainDisplay::paintEvent(QPaintEvent * event);
};
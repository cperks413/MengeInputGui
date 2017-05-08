#include "MainDisplay.h"
#include "QPainter"
#include "QMouseEvent"

MainDisplay::MainDisplay(QWidget *parent)
	: QWidget(parent)
{
	setFixedHeight(700);
	setFixedWidth(700);
	QPalette pal = palette();
	pal.setColor(QPalette::Background, Qt::black);
	setAutoFillBackground(true);
	setPalette(pal);
	setMouseTracking(true);
	held = false;
	state = 0;
	for (int i = 0; i < 8; i++)
	{
		squareList.push_back(Square(0, 0, 0, 0));
	}
	obstNum = 0;
}
void MainDisplay::mousePressEvent(QMouseEvent * event)
{
	held = true;
	xPress = event->x();
	yPress = event->y();
	if (state == 8) {
		obstNum = obstacleList.size();
		obstacleList.push_back(Square(0, 0, 0, 0));
	}
}
void MainDisplay::mouseReleaseEvent(QMouseEvent * event)
{
	held = false;
}
void MainDisplay::mouseMoveEvent(QMouseEvent * event)
{
	if (held == true && state < 8)
	{
		xDist = event->x() - xPress;
		yDist = event->y() - yPress;
		squareList.at(state) = Square(xPress, yPress, xDist, yDist);
		update();
	}
	if (held == true && state == 8)
	{
		xDist = event->x() - xPress;
		yDist = event->y() - yPress;
		update();
		obstacleList.at(obstNum) = Square(xPress, yPress, xDist, yDist);
	}
};
void MainDisplay::paintEvent(QPaintEvent * event)
{
	QPainter painter(this);
	for (int i = 0; i < squareList.size(); i++)
	{
		if (i % 2 == 0)
			painter.setPen(Qt::blue);
		else
			painter.setPen(Qt::red);
		painter.drawRect(squareList.at(i).x, squareList.at(i).y, squareList.at(i).offsetX, squareList.at(i).offsetY);
	}
	for (int i = 0; i < obstacleList.size(); i++)
	{
		painter.setPen(Qt::gray);
		painter.drawRect(obstacleList.at(i).x, obstacleList.at(i).y, obstacleList.at(i).offsetX, obstacleList.at(i).offsetY);
	}
};
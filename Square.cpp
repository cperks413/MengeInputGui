#include "Square.h"

Square::Square()
{
	x = 0;
	y = 0;
	offsetX = 0;
	offsetY = 0;
}

Square::Square(float X, float Y, float OffsetX, float OffsetY)
{
	x = X;
	y = Y;
	offsetX = OffsetX;
	offsetY = OffsetY;
};

float Square::getMinX()
{
	if (x < (x + offsetX))
	{
		return x;
	}
	return (x + offsetX);
};

float Square::getMaxX()
{
	if (x > (x + offsetX))
	{
		return x;
	}
	return (x + offsetX);
};

float Square::getMinY()
{
	if (y < (y + offsetY))
	{
		return y;
	}
	return (y + offsetY);
};

float Square::getMaxY()
{
	if (y >(y + offsetY))
	{
		return y;
	}
	return (y + offsetY);
};

Square Square::enlarge()
{
	float xPercent = ((float)x) / 7.0;
	float yPercent = ((float)y) / 7.0;

	float xOutof40 = 0.4 * xPercent;
	float yOutof40 = 0.3 * yPercent;

	float newX = xOutof40 - 20;
	float newY = yOutof40 - 15;

	xPercent = ((float)x + offsetX) / 7.0;
	yPercent = ((float)y + offsetY) / 7.0;

	xOutof40 = 0.4 * xPercent;
	yOutof40 = 0.3 * yPercent;

	float newOffsetX = (xOutof40 - 20) - newX;
	float newOffsetY = (yOutof40 - 15) - newY;

	return Square(newX, newY, newOffsetX, newOffsetY);
};
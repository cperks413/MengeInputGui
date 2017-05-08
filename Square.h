#pragma once

class Square
{
public:
	Square();
	Square(float X, float Y, float OffsetX, float OffsetY);
	float x, y, offsetX, offsetY;
	float Square::getMinX();
	float Square::getMinY();
	float Square::getMaxX();
	float Square::getMaxY();
	Square Square::enlarge();
	bool Square::operator==(const Square &other) const {
		return (other.x == x && other.y == y && other.offsetX == offsetX && other.offsetY == y);
	}
	bool Square::operator!=(const Square &other) const {
		return !(other.x == x && other.y == y && other.offsetX == offsetX && other.offsetY == y);
	}
};
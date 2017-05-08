#pragma once
#include 

class GLPolygonWidget : public QGLWidget
{
public:
	//constructor
	GLPolygonWidget(QWidget *parent, GLPolygon *newPolygon);

	//polygon local assignment
	GLPolygon* thePolygon;

protected:
	//inherited methods
	void initializeGL();
	void resizeGL(int w, int h);
	void paintGL();

};
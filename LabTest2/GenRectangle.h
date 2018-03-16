#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H

#include <string>
using namespace std;

class GenRectangle {
private: 
	int x;
	int y;
	int width;
	int height;

public: 
	GenRectangle(); // sets x = 100, y = 25, w = 20, h = 30
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	int getArea();
	int getPerimeter();
	void setWidth(int width);
	void setHeight(int height);
	void setX(int x);
	void setY(int y);
	string getType();
	void draw(); 
};

#endif


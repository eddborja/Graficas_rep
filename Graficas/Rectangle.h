#pragma once
class Rectangle {
private:
	float _width;
	float _height;
public:
	Rectangle();
	Rectangle(float w, float h);
	float GetWidth();
	void SetWidth(float w);
	float GetHeight();
	void SetHeight(float h);
	float GetArea();
	float GetPerimeter();

};
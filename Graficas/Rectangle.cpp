#include "Rectangle.h"
Rectangle::Rectangle() {
	_width = 1.0f;
	_height = 1.0f;
}
Rectangle::Rectangle(float w, float h) {
	_width = w;
	_height = h;

}
float Rectangle::GetWidth() {
	return _width;
}

void Rectangle::SetWidth(float w) {
	_width = w;

}
float Rectangle::GetHeight() {
	return _height;
}
void Rectangle::SetHeight(float h) {
	_height = h;
}
float Rectangle::GetArea() {
	float area = _width*_height;;
		return area;
}
float Rectangle::GetPerimeter() {
	float perimeter = _width + _width + _height + _height;
	return perimeter;
}

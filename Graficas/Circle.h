#pragma once
#include<string>
class Circle {
private:
	double _radius;
	std::string _color;
public:
	Circle();
	Circle(double r);
	Circle(double r, std::string c);
	double GetRadius();
	double GetArea();
	std::string GetColor(); 
	void SetRadius(double r);
	void SetColor(std::string c);




}
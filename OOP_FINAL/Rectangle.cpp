#include"Object.h"

Rectangle::Rectangle() : Shape("Rectangle") {
	_width = 0;
	_height = 0;
}

Rectangle::Rectangle(float width, float height) : Shape("Rectangle") {
	_width = width;
	_height = height;
}

Rectangle* Rectangle::Instance() {
	if (_instance == nullptr) {
		_instance = new Rectangle();
	}
	return _instance;
}

Rectangle* Rectangle::Instance(float width, float height) {
	if (_instance == nullptr) {
		_instance = new Rectangle(width, height);
	}
	return _instance;
}

float Rectangle::Area() {
	return _width * _height;
}

float Rectangle::Perimeter() {
	return 2 * (_width + _height);
}

string Rectangle::ToString() {
	stringstream ss;
	ss << _name << " with width = " << _width << " and height = " << _height << " has area = " << Area() << " and perimeter = " << Perimeter();
	return ss.str();
}
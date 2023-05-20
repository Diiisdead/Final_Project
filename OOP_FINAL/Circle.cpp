#include"Object.h"

Circle::Circle() : Shape("Circle") {
	_radium = 0;
}

Circle::Circle(float radium) : Shape("Circle") {
	_radium = radium;
}

Circle* Circle::Instance() {
	if (_instance == nullptr) {
		_instance = new Circle();
	}
	return _instance;
}

Circle* Circle::Instance(float radium) {
	if (_instance == nullptr) {
		_instance = new Circle(radium);
	}
	return _instance;
}

float Circle::Area() {
	return PI * _radium * _radium;
}

float Circle::Perimeter() {
	return 2 * PI * _radium;
}

string Circle::ToString() {
	stringstream ss;
	ss << _name << " with radium = " << _radium << " has area = " << Area() << " and perimeter = " << Perimeter();
	return ss.str();
}
#include "Object.h"

Square::Square() : Shape("Square") {
	_side = 0;
}

Square::Square(float side) : Shape("Square") {
	_side = side;
}

Square* Square::Instance() {
	if (_instance == nullptr) {
		_instance = new Square();
	}
	return _instance;
}

Square* Square::Instance(float side) {
	if (_instance == nullptr) {
		_instance = new Square(side);
	}
	return _instance;
}

float Square::Area() {
	return _side * _side;
}

float Square::Perimeter() {
	return 4 * _side;
}

string Square::ToString() {
	stringstream ss;
	ss << _name << " with side = " << _side << " has area = " << Area() << " and perimeter = " << Perimeter();
	return ss.str();
}

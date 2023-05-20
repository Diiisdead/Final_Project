#include "Object.h"

Shape::Shape(string name) {
	_name = name;
}

Shape* CircleParser::Parse(string data) {
	float radium = stof(data.substr(data.find_first_of('=') + 1));
	Circle* circle = Circle::Instance(radium);
	return circle;
}

string CircleParser::ToString() {
	return "CircleParser";
}

Shape* RectangleParser::Parse(string data) {
	float width = stof(data.substr(data.find_first_of('=') + 1, data.find_last_of(',') - 1 ));
	float height = stof(data.substr(data.find_last_of('=') + 1));
	Rectangle* rectangle = Rectangle::Instance(width, height);
	return rectangle;
}

string RectangleParser::ToString() {
	return "RectangleParser";
}

Shape* SquareParser::Parse(string data) {
	float side = stof(data.substr(data.find_first_of('=') + 1));
	Square* square = Square::Instance(side);
	return square;
}

string SquareParser::ToString() {
	return "SquareParser";
}

void ParserFactory::Register(string type, IParser* parser) {
	_prototypes.insert({ type, parser });
}

string ParserFactory::ToString() {
	return "ParserFactory";
}

IParser* ParserFactory::select(string type) {
	IParser* parser = nullptr;
	if (_prototypes.contains(type)) {
		parser = _prototypes[type];
	}
	return parser;
}






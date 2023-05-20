#include "Object.h"
#include <fstream>

int main() {
	ParserFactory factory;
	factory.Register("Circle", new CircleParser());
	factory.Register("Rectangle", new RectangleParser());
	factory.Register("Square", new SquareParser());
	string data = "shapes.txt";
	ifstream file(data);
	string line;
	getline(file, line);
	int count = stoi(line);
	cout << "Reading shapes from file: " << data << endl;
	cout << "Find  " << count << " shapes" << endl;
	for (int i = 0; i < count; i++) {
		getline(file, line);
		stringstream buffer(line);
		string type;
		string data;
		getline(buffer, type, ':');
		getline(buffer, data);
		IParser* parser = factory.select(type);
		if (parser != nullptr) {
			Shape* shape = parser->Parse(data);
			cout << shape->ToString() << endl;
		}
	}
	return 0;
}
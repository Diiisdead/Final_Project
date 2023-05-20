#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>

#define PI 3.14
using namespace std;



class Object {
public:
	virtual string ToString() = 0;
};

class Shape : public Object {
protected:
	string _name;
public:
	Shape(string);
	virtual float Area() = 0;
	virtual float Perimeter() = 0;
};

class Circle : public Shape {
private:
	float _radium;
	inline static  Circle* _instance = nullptr;
	Circle();
	Circle(float);
public:
	static Circle* Instance();
	static Circle* Instance(float);
	Circle(const Circle&) = delete;
	Circle& operator=(const Circle&) = delete;
	float Area() override;
	float Perimeter() override;
	string ToString() override;
};

class Rectangle : public Shape {
private:
	float _width;
	float _height;
	inline static Rectangle* _instance = nullptr;
	Rectangle();
	Rectangle(float, float);
public:
	static Rectangle* Instance();
	static Rectangle* Instance(float, float);
	Rectangle(const Rectangle&) = delete;
	Rectangle& operator=(const Rectangle&) = delete;
	float Area() override;
	float Perimeter() override;
	string ToString() override;
};

class Square : public Shape {
private:
	float _side;
	inline static Square* _instance = nullptr;
	Square();
	Square(float);
public:
	static Square* Instance();
	static Square* Instance(float);
	Square(const Square&) = delete;
	Square& operator=(const Square&) = delete;
	float Area() override;
	float Perimeter() override;
	string ToString() override;
};

class IParser : public Object {
public:
	virtual Shape* Parse(string) = 0;
};

class CircleParser : public IParser {
public:
	Shape* Parse(string) override;
	string ToString();
};

class RectangleParser : public IParser {
public:
	Shape* Parse(string) override;
	string ToString();
};

class SquareParser : public IParser {
public:
	Shape* Parse(string) override;
	string ToString();
};

class ParserFactory : public Object {
private:
	map<string, IParser*> _prototypes;
public:
	void Register(string, IParser*);
	IParser* select(string);
	string ToString();
};



#include <iostream>
#include <string>
using namespace std;

class Color{
	public:
		virtual ~Color() {}
		virtual string printColor() const = 0;
};

class Red:public Color{
	public:
		string printColor() const override {
			return "Red color!\n";	
		}
};

class Blue:public Color{
	public:
		string printColor() const override {
			return "Blue color!\n";	
		}
};

class Shape{
	protected:
		Color* color_;

	public:
		Shape(Color* color) : color_(color){}

		virtual ~Shape() {}
		virtual string funcShape() const {
			return "Shape: Base Shape with " + color_->printColor();	
		}
};

class Circle:public Shape{
	public:
		Circle(Color* color) : Shape(color){}
		string funcShape() const override {
			return "Shape: Circle Shape with " + color_->printColor();	
		}
};

void ClientCode(const Shape& shape){
	cout << shape.funcShape();
}

int main(){
	Color* color = new Red;
	Shape* shape =  new Circle(color);
	ClientCode(*shape);
	cout << endl;

	return 0;
}

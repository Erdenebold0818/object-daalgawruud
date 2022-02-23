#include <iostream>
#include <math.h>
#define PI 3.14159

using namespace std;
class Shape{
	protected:
		char *name;
	public:
		void setName(char *ner){
			name = new char[strlen(ner) + 1];
			strcpy(name, ner);
		}
		Shape(char *ner){
			name = new char[strlen(ner) + 1];
			strcpy(name, ner);
			cout << "Dvrs vvssen" << endl << endl;
		}
		Shape(){
			cout << "Dvrs vvssen" << endl << endl;
		}
		~Shape(){
			delete name;
			cout << "Dvrs ustgagdaw" << endl;
		}
};

class TwoDimensionalShape : public Shape{
	protected:
		int x;
		int y;
		int r;
	public:
		TwoDimensionalShape(char *ner, int a, int b, int urt) : Shape(ner){
			x = a;
			y = b;
			r = urt;
		}
		TwoDimensionalShape(char *ner) : Shape(ner){
		}
		int getRadius(){
			return r;
		}
};

class Circle : public TwoDimensionalShape{
	public:
		float findArea(){
			return PI * r * r;
		}
		float findCircle(){
			return 2 * PI * r;
		}
		Circle() : TwoDimensionalShape("Dugui"){
			x = 0;
			y = 0;
		}
		Circle(char *ner, int a, int b, int urt) : TwoDimensionalShape(ner, a, b, urt){
		}
		void setRadius(float a){
			r = a;
		}
		void print(){
			cout <<"Ner: " << name << endl;
			cout << "Toirgiin tuw: " << x << " " << y << endl;
			cout << "Radius: " << r << " " << endl;
			cout << "Talbai: " << findArea() << endl;
			cout << "Urt: " << findCircle() << endl << endl;
		}
};

class Square : public TwoDimensionalShape{
	private:
		int x1, x2, x3, y1, y2, y3;
	public:
		float findArea(){
			return r * r;
		}
		float findFrame(){
			return 4 * r;
		}
		Square() : TwoDimensionalShape("Kvadrat"){
			x = 0;
			y = 0;
			r = 1;
			x1 = x + r;
			y1 = y;
			x2 = x + r;
			y2 = y + r;
			x3 = x;
			y3 = y + r;
		}
		Square(char *ner, int a, int b, int urt) : TwoDimensionalShape(ner, a, b, urt){
			x1 = x + r;
			y1 = y;
			x2 = x + r;
			y2 = y + r;
			x3 = x;
			y3 = y + r;
		}
		void setLength(float l){
			r = l;
		}
		void setA(float a, float b){
			x = a;
			y = b;
			x1 = x + r;
			y1 = y;
			x2 = x + r;
			y2 = y + r;
			x3 = x;
			y3 = y + r;
		}
		void print(){
			cout <<"Ner: " << name << endl;
			cout << "Koordinatuud: " << endl;
			cout << "a(" << x << ", " << y << ") ";
			cout << "b(" << x1 << ", " << y1 << ") " << endl;
			cout << "c(" << x2 << ", " << y2 << ") ";
			cout << "d(" << x3 << ", " << y3 << ") " << endl;
			cout << "Urt: " << r << " " << endl;
			cout << "Talbai: " << findArea() << endl;
			cout << "Perimeter: " << findFrame() << endl << endl;
		}
};

class Triangle : public TwoDimensionalShape{
	private:
		float x1, x2, y1, y2;
	public:
		float findArea(){
			return (r * r * sqrt(3) /2 /2);
		}
		float findFrame(){
			return 3 * r;
		}
		Triangle() : TwoDimensionalShape("Gurvaljin"){
		}
		Triangle(char *ner, int a, int b, int urt) : TwoDimensionalShape(ner, a, b, urt){
			y1 = r * cos(30 * PI /180.00) + y;
			y2 = r * cos(30 * PI /180.00) + y;
			x1 = r * sin(30 * PI/180.00) + x;
			x2 = x - r * sin(30 * PI/180.00);
		}
		void setLength(float l){
			r = l;
		}
		void setA(float a, float b){
			x = a;
			y = b;
			y1 = r * cos(30 * PI /180.00) + y;
			y2 = r * cos(30 * PI /180.00) + y;
			x1 = r * sin(30 * PI/180.00) + x;
			x2 = x - r * sin(30 * PI/180.00);
		}
		void print(){
			cout <<"Ner: " << name << endl;
			cout << "Koordinatuud: " << endl;
			cout << "a(" << x << ", " << y << ") ";
			cout << "b(" << x1 << ", " << y1 << ") ";
			cout << "c(" << x2 << ", " << y2 << ") " << endl;
			cout << "Urt: " << r << " " << endl;
			cout << "Talbai: " << findArea() << endl;
			cout << "Perimeter: " << findFrame() << endl << endl;
		}
};


int main(){

	//Toirog
	Circle a("toirog", 10, 10, 5);
	a.print();
	//Kvadrat
	Square s("Kvadrat", 10, 10, 2);
	s.print();
	//Gurvaljin
	Triangle c("Gurvaljin", 10, 10, 8);
	c.print();
}

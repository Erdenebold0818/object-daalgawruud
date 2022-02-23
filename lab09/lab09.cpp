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
			cout << "******Dvrs vvssen******" << endl << endl;
		}
		Shape(){
			cout << "******Dvrs vvssen******" << endl << endl;
		}
		~Shape(){
			delete name;
			cout << ">>Dvrs ustgagdaw<<" << endl;
		}
		virtual float findPerimeter() = 0;
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
		virtual float findArea() = 0;
};

class Circle : public TwoDimensionalShape{
	public:
		float findArea(){
			return PI * r * r;
		}
		float findPerimeter(){
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
			cout <<"\tNer: " << name << endl;
			cout << "\tToirgiin tuw: O(" << x << ", " << y << ")" <<endl;
			cout << "\tRadius: " << r << " " << endl;
			cout << "\tTalbai: " << findArea() << endl;
			cout << "\tUrt: " << findPerimeter() << endl << endl;
		}
};

class Square : public TwoDimensionalShape{
	private:
		int x1, x2, x3, y1, y2, y3;
	public:
		float findArea(){
			return r * r;
		}
		float findPerimeter(){
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
			x1 = x + r;
			y1 = y;
			x2 = x + r;
			y2 = y + r;
			x3 = x;
			y3 = y + r;
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
			cout <<"\tNer: " << name << endl;
			cout << "\tKoordinatuud: ";
			cout << "\ta(" << x << ", " << y << ") ";
			cout << "b(" << x1 << ", " << y1 << ") ";
			cout << "c(" << x2 << ", " << y2 << ") ";
			cout << "d(" << x3 << ", " << y3 << ") " << endl;
			cout << "\tUrt: " << r << " " << endl;
			cout << "\tTalbai: " << findArea() << endl;
			cout << "\tPerimeter: " << findPerimeter() << endl << endl;
		}
};

class Triangle : public TwoDimensionalShape{
	private:
		float x1, x2, y1, y2;
	public:
		float findArea(){
			return (r * r * sqrt(3) /2 /2);
		}
		float findPerimeter(){
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
			y1 = r * cos(30 * PI /180.00) + y;
			y2 = r * cos(30 * PI /180.00) + y;
			x1 = r * sin(30 * PI/180.00) + x;
			x2 = x - r * sin(30 * PI/180.00);
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
			cout <<"\tNer: " << name << endl;
			cout << "\tKoordinatuud: ";
			cout << "\ta(" << x << ", " << y << ") ";
			cout << "b(" << x1 << ", " << y1 << ") ";
			cout << "c(" << x2 << ", " << y2 << ") " << endl;
			cout << "\tUrt: " << r << " " << endl;
			cout << "\tTalbai: " << findArea() << endl;
			cout << "\tPerimeter: " << findPerimeter() << endl << endl;
		}
};


int main(){
	int tmp, i, j;
	float areas[6];
	//Toirog
	Circle c1("toirog1", 10, 10, 5);
	Circle c2("toirog2", 20, 20, 12);
	
	//Kvadrat
	Square s1("Kvadrat1", 10, 10, 2);
	Square s2("Kvadrat2", 20, 20, 5);

	//Gurvaljin
	Triangle t1("Gurvaljin1", 10, 10, 8);
	Triangle t2("Gurvaljin2", 10, 10, 6);
	c1.print();
	c2.print();
	s1.print();
	s2.print();
	t1.print();
	t2.print();
	
	areas[0] = c1.findArea();
	areas[1] = c2.findArea();
	areas[2] = s1.findArea();
	areas[3] = s2.findArea();
	areas[4] = t1.findArea();
	areas[5] = t2.findArea();
	for(i = 0; i < 5; i++){
	   for(j = i + 1; j < 5; j++){
	      if(areas[j] < areas[i]){
	         tmp = areas[i];
	         areas[i] = areas[j];
	         areas[j] = tmp;
	      }
	   }
	}
	for(i = 0; i < 6; i++) {
   		cout << "Talbai" << i+1 << ": " << areas[i]<<"\n";
	}
}

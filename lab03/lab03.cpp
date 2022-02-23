#include <iostream>
using namespace std;
/*Ажилчны Классийг Тодорхойлох*/
class employee{
	public:
		int id;
		char name[20];
		char position[10];
		float workHour;
		
		void value(int, char*, char*, float);
		void input();
		void output();
		float salary(float);
		float ceoSalary();
		int addHour();
};
/*Гарааны утга оноох функц*/
void employee::value(int dugaar, char *ner, char *tushaal, float tsag){
	id = dugaar;
	strcpy(name, ner);
	strcpy(position, tushaal);
	workHour = tsag;
}
/*Гараас утга авах функц*/
void employee::input(){
	cout << "ID: ";
	cin >> id;
	cout << "Ner: ";
	cin >> name;
	cout << "Tushaal: ";
	cin >> position;
	cout << "Ajillasan tsag: ";
	cin >> workHour;
}
/*Мэдээлэл дэлгэцлэх*/
void employee::output(){
	cout << "ID: " << id << endl;
	cout << "Ner: " << name << endl;
	cout << "Tushaal: "<< position << endl;
	cout << "Ajillasan tsag: " << workHour << endl;
}
/*Нийт цалин бодох*/
float employee::salary(float hourSalary){
	int total = 0;
	addHour();	
	if(strcmp(position, "ceo") == 0)
		total = ceoSalary() + hourSalary*workHour;
	else 
		total =  hourSalary*workHour;
	return total;
}
/*Захирлын цалин бодох*/
float employee::ceoSalary(){
	int hour;
	cout << "Zahirliin tsagiin tsalin: ";
	cin >> hour;
	return hour*workHour;
}
/*Ажилласан цаг нэмэгдүүлэх*/
int employee::addHour(){
	int nemelt;
	cout << "Nemelt tsag: ";
	cin >> nemelt;
	if(nemelt > 0 && nemelt <= 24){
		workHour += nemelt;
		return 1;
	}
	return 0;
}

int main(){
	char a[]="manager", b[]="Bold";
	int hourSalary, total;
	employee bat, bold;
	bat.input();
	cout << "Tsagiin tsalin: "; 
	cin >> hourSalary;
//	bold.value(15, b, a, 8);
//	bold.output();
	total = bat.salary(hourSalary);
	cout << endl << "Niit tsalin: " << total << endl;
}








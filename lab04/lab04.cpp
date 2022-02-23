#include <iostream>
using namespace std;
/*Ажилчны Классийг Тодорхойлох*/
class Employee{
	private:
		int id;
		char *name;
		char *position;
		float workHour;
		int hourSalary;
		float ceoSalary();
	public:
		void input();
		void output();
		float salary();
		bool addHour(float );
		Employee(){
			name = new char[20];
			position = new char[10];
		}
		Employee(int tsagiinHuls){
			name = new char[20];
			position = new char[10];
			workHour = tsagiinHuls;
		}
		Employee(int tsagiinHuls, int dugaar, char *ner, char *tushaal, float tsag){
			name = new char[20];
			position = new char[10];
			id = dugaar;
			strcpy(name, ner);
			strcpy(position, tushaal);
			workHour = tsag;
		}
		~Employee(){
			delete name;
			delete position;
			cout << "Deleted successfully\n";
		}
};
/*Гараас утга авах функц*/
void Employee::input(){
	cout << "ID: ";
	cin >> id;
	cout << "Ner: ";
	cin >> name;
	cout << "Tushaal: ";
	cin >> position;
	cout << "Ajillasan tsag: ";
	cin >> workHour;
	cout << "Tsagiin tsalin: ";
	cin >> hourSalary;
}
/*Мэдээлэл дэлгэцлэх*/
void Employee::output(){
	cout << "ID: " << id << endl;
	cout << "Ner: " << name << endl;
	cout << "Tushaal: "<< position << endl;
	cout << "Ajillasan tsag: " << workHour << endl;
}
/*Нийт цалин бодох*/
float Employee::salary(){
	int total = 0, add;
	cout << "Nemelt tsag: ";
	cin >> add;
	if(addHour(add))
		workHour += add;
	else
		cout << "Buruu utga oruulsan\n";
		
	if(strcmp(position, "ceo") == 0)
		total = ceoSalary() + hourSalary*workHour;
	else 
		total =  hourSalary*workHour;
	return total;
}
/*Захирлын цалин бодох*/
float Employee::ceoSalary(){
	int hour = 20000;
	return hour*workHour;
}
/*Ажилласан цаг нэмэгдүүлэх*/
bool Employee::addHour(float nemelt){
	if(nemelt > 0 && nemelt <= 24){
		return 1;
	}
	return 0;
}

int main(){
	int total[3];
	Employee *ajilchid = new Employee[3];
	for(int i = 0; i < 3; i++){
		(ajilchid+i)->input();
		*(total+i) = (ajilchid+i)->salary();
		cout << endl << "Niit tsalin: " << *(total+i) << endl;
	}

	int temp, j, i;
	for(i = 0; i < 3; i++){
   		for(j = i + 1; j < 3; j++){
      		if(total[j] < total[i]){
         		temp = total[i];
        		total[i] = total[j];
         		total[j] = temp;
      		}
   		}
	}
	
	for(i = 0; i < 3; i++)
		cout << total[i]<< endl;
}








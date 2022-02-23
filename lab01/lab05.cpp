#include <iostream>
using namespace std;
inline int* digits(int n);
int main(){
	int N;
	int *a = new int[100];
	cout << "Natural toog oruul: ";
	cin >> N;
	a = digits(N);
	cout << a[0] << " Orontoi\n";
	cout << "Ug toonii tsifrvvd :";
	for(int i = a[0]; i > 0; i--)
		cout << a[i] << " ";
	delete a;
	a = 0;
	return 0;
}

inline int* digits(int n){
	int i;
	int *a = new int[100];
	for(i = 0; n > 0 ; i++, n /= 10)
		a[i+1] = n%10; 
	a[0] = i;
	return a;
}
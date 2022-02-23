#include <iostream>
using namespace std;
inline int* even(int *a, int N);
int main(){
	int N;
	cout << "Heden too oruulah ve? \n";
	cin >> N;
	cout << "Toonuudaa oruul : \n";
	
	int *a = new int[100];
	int *tegsh = new int[100];
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	tegsh = even(a, N);
	cout << "Niit " << tegsh[0] - 1 << " tegsh toonuud: \n";
	for(int i = 1; i <= tegsh[0] - 1; i++){
		cout << tegsh[i] << " ";
	}
	delete a, tegsh;
	a = 0;
	tegsh = 0;
	return 0;
}

inline int* even(int *a, int N){
	int j = 1;
	int *tegsh = new int[100];
	for(int i = 0; i < N; i++){
		if(a[i] % 2 == 0){
			tegsh[j] = a[i];
			j++;
		}
	}
	tegsh[0] = j;
	return tegsh;
}
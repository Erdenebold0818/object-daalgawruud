#include <iostream>
using namespace std;
int main(){
	int N, max, min;
	cout << "Heden too oruulah ve? \n";
	cin >> N;
	cout << "Toonuudaa oruul : \n";
	
	int *a = new int[100];
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	max = a[0];
	min = a[0];
	for(int i = 0; i < N; i++){
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}
	cout << "Hamgiin ih :" << max << "\n";
	cout << "Hamgiin baga :" << min << "\n";
	delete a;
	a = 0;
	return 0;
}
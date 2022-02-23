#include <iostream>
using namespace std;
inline float average(int *array, int n);
int main(){
	int N;
	cout << "Niit heden too oruulah ve? \n";
	cin >> N;
	int *a = new int[100];
	for(int i = 0; i < N; i++)	
		cin >> a[i];
	cout << "Dundaj: " << average(a, N);
	return 0;
	delete a;
	a = 0;
}

inline float average(int *array, int n){
	int s = 0, j = 0;
	for(int i = 0; i < n; i++){
		if(array[i] % 2 == 1){
			s += array[i];
			j++;
		}
	}
	return s/(float)j;
}
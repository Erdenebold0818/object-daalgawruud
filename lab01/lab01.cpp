#include <iostream>
using namespace std;
inline int max(int a, int b, int c);
int main(){
	int a, b, c;
	cout << "a ,b ,c toonuudiig oruul:" << "\n";
	cin >> a >> b >> c;
	cout << "Hamgiin ih: " << max(a, b, c);
	return 0;
}

inline int max(int a, int b, int c){
	if(a >= b && a >= c) return a;
	if(b >= a && b >= c) return b;
	if(c >= a && c >= b) return c;
	return 0;
}
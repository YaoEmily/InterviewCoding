#include <iostream>
using namespace std;

int Fibonacci(int n){
	int fib0 = 0;
	int fib1 = 1;
	for (int i = 0; i <= n; i++){
		int tmp = fib0 + fib1;
		fib0 = fib1;
		fib1 = tmp;
	}
	return fib1;
}

int main(void){
	int n;
	cin >> n;
	int res = Fibonacci(n);
	cout << res << endl;
	system("pause");
}
#include <iostream>
using namespace std;

double Power(double base, int exponent){
	double product;
	if (exponent == 0){
		return 1;
	}
	else{
		product = base;
		int exponent2 = exponent > 0 ? exponent : -exponent;
		for (int i = 1; i < exponent2; i++){
			product *= base;
		}
		
		if (exponent < 0)
		{
			product = 1 / product;
		}
		return product;
	}
}

int main(void){
	double m;
	int n;
	cin >> m >> n;
	double res = Power(m, n);
	cout << res << endl;
	system("pause");
}
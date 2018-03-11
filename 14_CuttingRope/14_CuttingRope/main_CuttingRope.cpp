#include <iostream>
using namespace std;

int maxProduct(int n){
	if (n < 2){
		return 0;
	}
	else if (n == 2){
		return 1;
	}
	else if (n == 3){
		return 2;
	}
	int* products = new int[n + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max;
	for (int i = 4; i <= n; i++){
		max = 0;
		for (int j = 1; j <= i / 2; j++){
			int product = products[j] * products[i - j];
			if (product > max){
				max = product;
			}
			products[i] = max;
		}
	}

	max = products[n];
	delete[] products;
	
	return max;
}

int main(void){
	int n;
	cin >> n;
	int tmp = maxProduct(n);
	cout << tmp << endl;
	system("pause");
}
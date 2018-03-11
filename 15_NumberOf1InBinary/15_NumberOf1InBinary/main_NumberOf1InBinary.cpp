#include <iostream>
#include <math.h>
using namespace std;

int getNumberOf1(int n){
	int tmp = n;
	int sum = 0;
	if (tmp == 0){
		return 0;
	}
	else if (tmp == 1){
		return 1;
	}
	while (tmp / 2 != 0){
		tmp /= 2;
		sum++;
	}
	int res = getNumberOf1(n - pow(2, sum));

	return res + 1;
}

int getNumberOf1_2(int n){
	int tmp = n;
	int flag = 1;
	int sum = 0;
	while (flag){
		if (tmp & flag){
			sum++;
		}
		flag = flag << 1;
	}
	return sum;
}

int main(void){
	int n;
	cin >> n;
	int tmp = getNumberOf1_2(n);
	cout << tmp << endl;
	system("pause");
}
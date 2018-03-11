#include <iostream>
using namespace std;

void printNDigit(int n){
	char* c = new char[n + 1];

	c[0] = '1';
	for (int i = 1; i < n; i++){
		c[i] = '0';
	}
	c[n] = '\0';

	cout << c << " ";
	
	int flag = 0;
	do{
		flag = 0;
		for (int i = 0; i < n; i++){
			if (c[i] != '9'){
				flag = 1;
				break;
			}
		}
		if (flag){
			/* 输出当前循环的结果 */
			if (c[n - 1] < '9'){
				c[n - 1]++;
			}
			else{
				for (int i = n - 2; i >= 0; i--){
					if (c[i] < '9'){
						c[i]++;
						for (int j = n - 1; j>i; j--){
							c[j] = '0';
						}
						break;
					}
				}
			}
			cout << c << " ";
		}
	} while (flag == 1);
}

void print1ToMaxOfNDigits(int n){
	for (int i = 1; i <= n; i++){
		printNDigit(i);
	}
}

int main(void){
	int n;
	cin >> n;
	print1ToMaxOfNDigits(n);
	system("pause");
}
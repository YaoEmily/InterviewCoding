#include <iostream>
using namespace std;

int main(void){
	char str[] = "We are happy.";
	int len = sizeof(str);
	int sum = 0;
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			sum++;
		}
	}
	int newlen = len + sum * 2;
	for (int j = newlen - 1, i = len - 1; i != j; i--){
		if (str[i] == ' '){
			str[j] = '0';
			str[j - 1] = '2';
			str[j - 2] = '%';
			j -= 3;
		}
		else{
			str[j] = str[i];
			j--;
		}
	}
	cout << str << endl;
	system("pause");
}
#include <iostream>
using namespace std;

bool IsNumericString(const char* str){
	if (str == nullptr){
		return false;
	}

	int len = strlen(str);
	int i = 0;

	/* �ж��Ƿ�A���� */
	if (str[i] == '+' || str[i] == '-'){
		i++;
		if (str[i] >= 48 && str[i] <= 57){
			i++;
			while (str[i] >= 48 && str[i] <= 57){
				i++;
			}
		}
		else{
			return false;
		}
	}
	else if (str[i] >= 48 && str[i] <= 57){
		i++;
		while (str[i] >= 48 && str[i] <= 57){
			i++;
		}
	}

	/* �ж�С������ */
	if (str[i] == '.'){
		i++;
		while (str[i] >= 48 && str[i] <= 57){
			i++;
		}
	}

	/* �ж�ָ������ */
	if (str[i] == 'e' || str[i] == 'E'){
		i++;
		if (str[i] == '+' || str[i] == '-'){
			i++;
		}
		if (str[i] >= 48 && str[i] <= 57){
			i++;
			while (str[i] >= 48 && str[i] <= 57){
				i++;
			}
		}
		else{
			return false;
		}
	}
	if (i == len){
		return true;
	}
	else{
		return false;
	}
}

int main(void){
	char* str = new char[];
	str[0] = '\0';
	while (cin >> str){
		bool res = IsNumericString(str);
		cout << res << endl;
	}
	system("pause");
}
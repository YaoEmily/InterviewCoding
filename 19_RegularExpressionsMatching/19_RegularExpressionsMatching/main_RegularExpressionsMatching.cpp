#include <iostream>
using namespace std;

bool matchRegExp(char* reg, char* str, int a, int b){
	bool res = false;
	if (reg[a] != '\0' && str[b] != '\0'){
		if (reg[a] == '.'){
			res = matchRegExp(reg, str, a + 1, b + 1);
		}
		else if (reg[a] == '*'){
			cout << "Their is something wrong." << endl;
			return false;
		}
		else if (reg[a + 1] == '*'){
			if (reg[a] != str[b]){
				res = matchRegExp(reg, str, a + 2, b);
			}
			else{
				int i = 1;
				do{
					res = matchRegExp(reg, str, a, b + i);
					if (res == true){
						break;
					}
					else{
						i++;
					}
				} while (reg[a] == str[b + i]);
			}
		}
		else{
			if (reg[a] == str[b]){
				res = matchRegExp(reg, str, a + 1, b + 1);
			}
			else{
				return false;
			}
		}
	}
	else if(reg[a] == '\0' && str[b] == '\0'){
		return true;
	}
	else if (reg[a + 1] == '*'&& str[b] == '\0'){
		return true;
	}
	else
	{	
		return false;
	}
	return res;
}

int main(void){
	char* reg = new char[];
	char* str = new char[];
	cin >> reg;
	cin >> str;
	bool res = false;

	if (strlen(reg) > 0 || reg[0] == '.' || reg[0] == '*'){
		res = matchRegExp(reg, str, 0, 0);
	}
	else{
		cout << "Thier is something wrong." << endl;
	}

	cout << res << endl;
	system("pause");
}
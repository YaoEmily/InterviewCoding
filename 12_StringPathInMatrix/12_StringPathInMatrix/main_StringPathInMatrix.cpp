#include <iostream>
using namespace std;

bool backTracking(char arr[][4], int height, int i, int j, char* str, int x){
	bool res = false;
	if (sizeof(str) == x + 1){
		if (arr[i][j] == str[x]){
			/*���һ����ĸƥ��ɹ� ����true*/
			return true;
		}
		else{
			/*���һ����ĸƥ��ʧ�� ����false*/
			return false;
		}
	}
	else{
		if (arr[i][j] == str[x]){
			/*��ĸƥ��ɹ� ����ƥ��*/
			if (i > 0){
				res = backTracking(arr, height, i - 1, j, str, x + 1);
			}
			if (res == false && i < height){
				res = backTracking(arr, height, i + 1, j, str, x + 1);
			}
			if (res == false && j > 0){
				res = backTracking(arr, height, i, j - 1, str, x + 1);
			}
			if (res == false && j < 4){
				res = backTracking(arr, height, i, j + 1, str, x + 1);
			}
			return res;
		}
		else{
			/*��ĸƥ��ʧ�� ����false*/
			return false;
		}
	}
}

bool getFirstChar(char arr[][4], int height, char* str){
	bool tmp = false;
	for (int i = 0; i < height; i++){
		for (int j = 0; j < 4; j++){
			if (arr[i][j] == str[0])
				tmp = backTracking(arr, height, i, j, str, 0);
		}
	}
	return tmp;
}

int main(void){
	char arr[][4] = { { 'a', 'b', 't', 'g' },
	{ 'c', 'f', 'c', 's' },
	{ 'j', 'd', 'e', 'h' } };
	char str[] = "bfcej";
	bool tmp = getFirstChar(arr, 3, str);
	cout << tmp << endl;
	system("pause");
}
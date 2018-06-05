#include <iostream>
using namespace std;

bool IsSquenceOfBST(int* arr, int beginning, int ending){
	if (beginning == ending || beginning + 1 == ending){
		// 只剩一根或一根一叶
		return true;
	}
	else{
		int a = beginning, b = ending - 1;
		int root = arr[ending];

		if (arr[beginning] > root){
			// 叶全都大于根
			int flag = 1;
			for (int i = beginning; i <= b; i++){
				if (arr[i] < root){
					flag = 0;
					break;
				}
			}
			if (flag == 0){
				return false;
			}
			else{
				return IsSquenceOfBST(arr, beginning, ending - 1);
			}
		}
		else if (arr[ending - 1] < root){
			// 叶全都小于根
			int flag = 1;
			for (int i = beginning; i <= b; i++){
				if (arr[i] > root){
					flag = 0;
					break;
				}
			}
			if (flag == 0){
				return false;
			}
			else{
				return IsSquenceOfBST(arr, beginning, ending - 1);
			}
		}
		else{
			while (arr[a + 1] < root){
				a++;
			}
			while (arr[b - 1]>root){
				b--;
			}
			if (a + 1 == b){
				return IsSquenceOfBST(arr, beginning, a) && IsSquenceOfBST(arr, b, ending);
			}
			else{
				return false;
			}
		}
	}
}

int main(void){
	int squ[100];
	int len;
	cin >> len;
	for (int i = 0; i < len; i++){
		cin >> squ[i];
	}
	bool res = IsSquenceOfBST(squ, 0, len-1);
	cout << res << endl;

	system("pause");
}
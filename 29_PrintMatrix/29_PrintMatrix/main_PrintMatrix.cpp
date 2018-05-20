#include <iostream>
using namespace std;

void clockwisePrintArr(int** arr, int len){
	int cycle = len / 2;
	int currentCycle = 0;
	int tmpLen = len - 1;
	while (currentCycle < cycle){
		int tmpI, tmpJ, i;
		for (i = 0; i < tmpLen; i++){
			cout << arr[currentCycle][currentCycle + i] << " ";
		}
		tmpI = currentCycle;
		tmpJ = currentCycle + i;
		for (int i = 0; i < tmpLen; i++){
			cout << arr[tmpI + i][tmpJ] << " ";
		}
		tmpI = tmpI + i;
		for (int i = 0; i < tmpLen; i++){
			cout << arr[tmpI][tmpJ - i] << " ";
		}
		tmpJ = tmpJ - i;
		for (int i = 0; i < tmpLen; i++){
			cout << arr[tmpI - i][tmpJ] << " ";
		}

		currentCycle++;
		tmpLen -= 2;
	}
	if (len % 2 == 1){
		cout << arr[len / 2][len / 2];
	}
	cout << endl;
}

int main(void){
	int len = 3;
	int** arr = new int*[len];
	for (int i = 0; i < len; i++){
		arr[i] = new int[len];
	}
	int tmp = 1;
	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			arr[i][j] = tmp++;
		}
	}

	clockwisePrintArr(arr, len);

	for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
}
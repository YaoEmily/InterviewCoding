#include <iostream>
using namespace std;

int getMinNum(int* arr, int i, int j){
	if (arr[i] < arr[j]){
		return arr[i];
	}
	else{
		if (j - i > 1){
			int mid = (i + j) / 2;
			if (arr[i] < arr[mid]){
				getMinNum(arr, mid + 1, j);
			}
			else{
				getMinNum(arr, i, mid);
			}
		}
		else if (j == i + 1){
			return arr[i] < arr[j] ? arr[i] : arr[j];
		}
		else if (j == i){
			return arr[i];
		}
	}
}

int main(void){
	int n = 5;
	int arr[] = { 3, 5, 6, 9, 2 };
	int tmp = getMinNum(arr, 0, n - 1);
	cout << tmp << endl;
	system("pause");
}
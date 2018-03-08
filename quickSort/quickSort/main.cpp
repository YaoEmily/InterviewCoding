#include <iostream>
using namespace std;

void printArr(int* arr, int a, int b){
	for (int i = a; i <= b; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void qSort(int *arr, int i, int j){
	int low = i, high = j;
	int x = arr[i];
	if (i < j){
		while (i < j){
			while (i < j && arr[j] > x){
				j--;
			}
			if (i < j){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				i++;
			}
			while (i < j && arr[i] < x){
				i++;
			}
			if (i < j){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				j--;
			}
			//printArr(arr, low, high);
		}
		printArr(arr, low, high);
		qSort(arr, low, i - 1);
		qSort(arr, i + 1, high);
	}
}

int main(void){
	int n = 10;
	int arr[] = { 21, 32, 43, 98, 54, 45, 23, 4, 66, 86 };
	qSort(arr, 0, n - 1);
	cout << "The result is ";
	printArr(arr, 0, n);
	system("pause");
}
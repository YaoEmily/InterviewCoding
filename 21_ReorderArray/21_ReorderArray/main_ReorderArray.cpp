#include <iostream>
using namespace std;

bool ReorderArray(int* arr, int n){
	if (arr == nullptr){
		return false;
	}
	int a = 0, b = n - 1;
	do{
		/* 找到位于前面的偶数 */
		while (arr[a] % 2 != 0){
			a++;
		}

		/* 找到位于前面的奇数 */
		while (arr[b] % 2 == 0){
			b--;
		}
		if (a < b){
			int tmp = arr[a];
			arr[a] = arr[b];
			arr[b] = tmp;
		}
	} while (a < b);

	return true;
}

int main(void){
	int n;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	bool res = ReorderArray(arr, n);
	cout << res << endl;

	for (int i = 0; i < n; i++){
		cout << arr[i] << " ";
	}
	system("pause");
}
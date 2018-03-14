#include <iostream>
using namespace std;

bool ReorderArray(int* arr, int n){
	if (arr == nullptr){
		return false;
	}
	int a = 0, b = n - 1;
	do{
		/* �ҵ�λ��ǰ���ż�� */
		while (arr[a] % 2 != 0){
			a++;
		}

		/* �ҵ�λ��ǰ������� */
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
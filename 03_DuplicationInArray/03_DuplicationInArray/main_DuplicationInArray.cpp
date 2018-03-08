#include <iostream>
using namespace std;

int main(void){
	int n;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++){
		while (arr[i] != i){
			if (arr[arr[i]] == arr[i]){
				cout << arr[i] << endl;
				return true;
			}
			int tmp = arr[i];
			arr[i] = arr[tmp];
			arr[tmp] = tmp;
		}
	}
	return false;
}
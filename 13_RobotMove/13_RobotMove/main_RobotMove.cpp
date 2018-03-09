#include <iostream>
using namespace std;

int arr[1000][1000];

void backTracking(int n, int a, int b){
	int i = a, j = b;
	int sum = 0;
	while (i != 0){
		sum += i % 10;
		i /= 10;
	}
	while (j != 0){
		sum += j % 10;
		j /= 10;
	}
	if (sum <= n){
		arr[a][b] = 1;
		if (a > 0 && arr[a - 1][b] == 0){
			backTracking(n, a - 1, b);
		}
		if (b > 0 && arr[a][b - 1] == 0){
			backTracking(n, a, b - 1);
		}
		if (arr[a + 1][b] == 0){
			backTracking(n, a + 1, b);
		}
		if (arr[a][b + 1] == 0){
			backTracking(n, a, b + 1);
		}
	}
}

void printArr(){
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (arr[i][j] == 1){
				cout << "*";
			}
			else{
				cout << ".";
			}
		}
		cout << endl;
	}
}

int main(void){
	memset(arr, 0, arr[0][0]);
	int n;
	cin >> n;
	backTracking(n, 0, 0);
	printArr();
	system("pause");
}
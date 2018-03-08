#include <iostream>
using namespace std;

int m, n;
int arr[100][100];
int x;

bool findNum(int i, int j){
	if (i + 1 >= m){
		return findNum(i, j + 1);
	}
	else if (j + 1 >= n){
		return findNum(i + 1, j);
	}
	else if (x == arr[i + 1][j] || x == arr[i][j + 1]){
		return true;
	}
	else if (x > arr[i + 1][j] || x > arr[i][j + 1]){
		int tmp = false;
		if (x > arr[i + 1][j]){
			tmp = findNum(i + 1, j);
		}
		if (tmp == false && x > arr[i][j + 1]){
			tmp = findNum(i, j + 1);
		}
		return tmp;
	}
	else{
		return false;
	}
	
}

int main(void){
	cin >> x;
	cin >> m >> n;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> arr[i][j];
		}
	}
	if (arr[0][0] == x){
		cout << "true" << endl;
	}
	else if (arr[0][0] > x){
		cout << "false" << endl;
	}
	else if (arr[m - 1][n - 1] < x){
		cout << "false" << endl;
	}
	else{
		int tmp = findNum(0, 0);
		if (tmp == true){
			cout << "true" << endl;
		}
		else{
			cout << "false" << endl;
		}
	}
	system("pause");
}
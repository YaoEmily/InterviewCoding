#include <iostream>
using namespace std;

int main(void){
	int n;
	int arr[100];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int a = 0, b = n - 2, c;
	do{
		int x = 0;
		int y = 0;
		c = a + (b - a) / 2;
		for (int i = 0; i < n; i++){
			if (arr[i] <= c && arr[i] >= a){
				x++;
			}
			else if (arr[i] > c && arr[i] <= b){
				y++;
			}
		}
		if (x > c - a + 1){
			b = c;
			c = a + (b - a) / 2;
		}
		else if (y > b - c){
			a = c + 1;
			c = a + (b - a) / 2;
		}
		else{
			cout << "Their is something wrong." << endl;
		}
	} while (c != b);
	cout << c << endl;
	system("pause");
}
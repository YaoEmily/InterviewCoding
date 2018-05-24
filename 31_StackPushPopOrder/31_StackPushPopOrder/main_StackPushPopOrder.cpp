#include <iostream>
#include <stack>
#define countof_arr(x) (sizeof((x)) / sizeof(x)[0])
using namespace std;

bool IsStackPushPopOrder(int arr[], int arr1[], int len, int len1){
	if (len != len1){
		return false;
	}

	stack<int> mStack;
	int point = 0;
	int point1 = 0;
	while (point1 < len){
		if (point >= len){
			return false;
		}
		mStack.push(arr[point]);
		point++;
		while (!mStack.empty() && mStack.top() == arr1[point1]){
			mStack.pop();
			point1++;
		}
	}
	return true;
}

int main(void){
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr1[] = { 4, 5, 3, 2, 1 };
	int arr2[] = { 4, 3, 5, 1, 2 };


	cout << IsStackPushPopOrder(arr, arr1, countof_arr(arr), countof_arr(arr1)) << endl;
	cout << IsStackPushPopOrder(arr, arr2, countof_arr(arr), countof_arr(arr2)) << endl;

	system("pause");
}
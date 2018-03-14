#include <iostream>
using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* AddListNode(ListNode* root, int value){
	if (root == nullptr){
		cout << "Their is something wrong." << endl;
		return root;
	}

	ListNode* nNode = new ListNode();
	nNode->m_nValue = value;
	nNode->m_pNext = nullptr;

	if (root->m_pNext == nullptr){
		root->m_pNext = nNode;
	}
	else{
		ListNode* tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		tmpNode->m_pNext = nNode;
	}
	return root;
}

void PrintList(ListNode* root){
	if (root == nullptr){
		cout << "Their is something wrong." << endl;
	}
	ListNode* tmpNode = root;
	while (tmpNode->m_pNext != nullptr){
		tmpNode = tmpNode->m_pNext;
		cout << tmpNode->m_nValue << " ";
	}
	cout << endl;
}

ListNode* PrintKthNodeFromEnd(ListNode* root, int k){
	if (k <= 0){
		cout << "Their is something wrong." << endl;
		return nullptr;
	}
	ListNode* tmpNode = root;
	for (int i = 0; i < k; i++){
		if (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		else{
			return nullptr;
		}
	}

	ListNode* kNode = root->m_pNext;
	while (tmpNode->m_pNext != nullptr){
		kNode = kNode->m_pNext;
		tmpNode = tmpNode->m_pNext;
	}
	return kNode;
}

int main(void){
	ListNode* root = new ListNode();
	for (int i = 10; i >= 0; i--){
		AddListNode(root, i);
	}
	PrintList(root);
	int k;
	cin >> k;
	ListNode* kNode = PrintKthNodeFromEnd(root, k);
	if (kNode == nullptr){
		cout << "Unable to find the Kth node from end." << endl;
	}
	else{
		cout << kNode->m_nValue << endl;
	}
	system("pause");
}
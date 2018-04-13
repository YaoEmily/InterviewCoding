#include <iostream>
using namespace std;

struct ListNode{
	int m_nKey;
	ListNode* m_pNext;
};

ListNode* addListNode(ListNode* root, int value){
	ListNode* newNode = new ListNode();
	newNode->m_nKey = value;
	newNode->m_pNext = nullptr;
	if (root->m_pNext == nullptr){
		root->m_pNext = newNode;
	}
	else{
		ListNode* tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		tmpNode->m_pNext = newNode;
	}
	return root;
}

void printList(ListNode* root){
	if (root->m_pNext == nullptr){
		cout << "The list is empty." << endl;
	}
	else{
		ListNode* tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			cout << tmpNode->m_pNext->m_nKey << " ";
			tmpNode = tmpNode->m_pNext;
		}
		cout << endl;
	}
}

ListNode* reverseList(ListNode* root){
	if (root->m_pNext == nullptr){
		return nullptr;
	}
	ListNode* newRoot = new ListNode();
	newRoot = root;
	ListNode* tmpNode = newRoot->m_pNext->m_pNext;
	ListNode* oldRoot = tmpNode->m_pNext;
	newRoot->m_pNext->m_pNext = nullptr;
	while (oldRoot != nullptr){
		tmpNode->m_pNext = newRoot->m_pNext;
		newRoot->m_pNext = tmpNode;
		tmpNode = oldRoot;
		oldRoot = oldRoot->m_pNext;
	}
	tmpNode->m_pNext = newRoot->m_pNext;
	newRoot->m_pNext = tmpNode;
	return newRoot;
}

int main(void){
	ListNode* root = new ListNode();
	root->m_pNext = nullptr;
	for (int i = 0; i < 10; i++){
		addListNode(root, i);
	}
	printList(root);
	ListNode* newRoot = reverseList(root);
	printList(newRoot);
	system("pause");
}
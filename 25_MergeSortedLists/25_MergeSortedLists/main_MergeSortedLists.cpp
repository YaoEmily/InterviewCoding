#include <iostream>
using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* addListNode(ListNode* root, int value){
	ListNode* newNode = new ListNode();
	newNode->m_nValue = value;
	newNode->m_pNext = nullptr;

	if (root->m_pNext == nullptr){
		root->m_pNext = newNode;
		return root;
	}
	ListNode* tmpNode = root->m_pNext;
	while (tmpNode->m_pNext != nullptr){
		tmpNode = tmpNode->m_pNext;
	}
	tmpNode->m_pNext = newNode;
	return root;
}

void printList(ListNode* root){
	if (root->m_pNext == nullptr){
		cout << "The list is empty." << endl;
	}
	else{
		cout << root->m_pNext->m_nValue;
		ListNode* tmpNode = root->m_pNext;
		while (tmpNode->m_pNext != nullptr){
			cout << tmpNode->m_pNext->m_nValue;
			tmpNode = tmpNode->m_pNext;
		}
	}
	cout << endl;
}

ListNode* mergeSortedLists(ListNode* root1, ListNode* root2){
	if (root1->m_pNext == nullptr&&root2->m_pNext == nullptr){
		cout << "The two lists are empty." << endl;
		return nullptr;
	}
	else if (root1->m_pNext == nullptr){
		return root2;
	}
	else if (root2->m_pNext == nullptr){
		return root1;
	}
	ListNode* tmpNode1 = root1->m_pNext;
	ListNode* tmpNode2 = root2->m_pNext;
	ListNode* root3 = new ListNode();
	ListNode* tmpNode3 = root3;
	ListNode* tmpNode = new ListNode();
	while (tmpNode1->m_pNext != nullptr && tmpNode2->m_pNext != nullptr){
		if (tmpNode1->m_nValue > tmpNode2->m_nValue){
			tmpNode = tmpNode2;
			tmpNode2 = tmpNode2->m_pNext;
			tmpNode3->m_pNext = tmpNode;
			tmpNode3 = tmpNode3->m_pNext;
		}
		else {
			tmpNode = tmpNode1;
			tmpNode1 = tmpNode1->m_pNext;
			tmpNode3->m_pNext = tmpNode;
			tmpNode3 = tmpNode3->m_pNext;
		}
		//cout << tmpNode3->m_nValue;
	}
	/* ±ß½ç±È½Ï */
	if (tmpNode1->m_nValue > tmpNode2->m_nValue){
		tmpNode = tmpNode2;
		tmpNode2 = tmpNode2->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;

		tmpNode = tmpNode1;
		tmpNode1 = tmpNode1->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;
	}
	else {
		tmpNode = tmpNode1;
		tmpNode1 = tmpNode1->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;

		tmpNode = tmpNode2;
		tmpNode2 = tmpNode2->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;
	}

	while (tmpNode1 != nullptr){
		ListNode* tmpNode = tmpNode1;
		tmpNode1 = tmpNode1->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;
	}
	while (tmpNode2 != nullptr){
		ListNode* tmpNode = tmpNode2;
		tmpNode2 = tmpNode2->m_pNext;
		tmpNode3->m_pNext = tmpNode;
		tmpNode3 = tmpNode3->m_pNext;
	}
	return root3;
}

int main(void){
	ListNode* root1 = new ListNode();
	root1->m_pNext = nullptr;
	for (int i = 1; i < 8; i = i + 2){
		addListNode(root1, i);
	}
	printList(root1);

	ListNode* root2 = new ListNode();
	root2->m_pNext = nullptr;
	for (int i = 2; i < 9; i = i + 2){
		addListNode(root2, i);
	}
	printList(root2);

	ListNode* root3 = mergeSortedLists(root1, root2);
	printList(root3);

	system("pause");
}
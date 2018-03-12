#include <iostream>
using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* addListNode(ListNode* root, int value){
	ListNode* node = new ListNode();
	node->m_nValue = value;
	node->m_pNext = nullptr;

	if (root->m_pNext == nullptr){
		root->m_pNext = node;
	}
	else{
		ListNode* tmpNode = new ListNode();
		tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		tmpNode->m_pNext = node;
	}
	return root;
}

void printList(ListNode* root){
	if (root == nullptr){
		cout << "The list is empty." << endl;
		return;
	}
	ListNode* tmpNode = new ListNode();
	tmpNode = root->m_pNext;
	while (tmpNode != nullptr){
		cout << tmpNode->m_nValue << " ";
		tmpNode = tmpNode->m_pNext;
	}
	cout << endl;
}

ListNode* deleteDuplicatedNode(ListNode* root){
	if (root == nullptr){
		cout << "The list is empty." << endl;
		return root;
	}
	ListNode* tmpNode = root;
	while (tmpNode->m_pNext != nullptr){
		if (tmpNode->m_nValue == tmpNode->m_pNext->m_nValue){
			/* 删除后面重复的节点 */
			ListNode* ttNode = new ListNode();
			ttNode = tmpNode->m_pNext;
			tmpNode->m_pNext = tmpNode->m_pNext->m_pNext;
			delete ttNode;
		}
		else{
			tmpNode = tmpNode->m_pNext;
		}
	}
	return root;
}

int main(void){
	ListNode* root = new ListNode();
	root->m_pNext = nullptr;
	for (int i = 1; i < 10; i++){
		addListNode(root, i);
		addListNode(root, i);
	}
	printList(root);
	
	deleteDuplicatedNode(root);
	printList(root);
	system("pause");
}
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
	if (root->m_pNext == nullptr){
		cout << "The list is empty." << endl;
	}
	ListNode* tmpNode = new ListNode();
	tmpNode = root->m_pNext;
	while (tmpNode->m_pNext != nullptr){
		cout << tmpNode->m_nValue << endl;
		tmpNode = tmpNode->m_pNext;
	}
}

ListNode* deleteListNode(ListNode* root, int value){
	if (root = nullptr){
		/* 链表为空 */
		cout << "The list is empty." << endl;
	}
	else if (root->m_nValue = value){
		/* 删除第一个节点 */
		ListNode* ttNode = root;
		root = root->m_pNext;
		delete ttNode;
	}
	/* 缺少删除最后一个节点 */
	ListNode* tmpNode = root->m_pNext;
	while (tmpNode->m_pNext->m_pNext != nullptr){
		/* 删除中间节点 */
		if (tmpNode->m_pNext->m_nValue == value){
			ListNode* ttNode = new ListNode();
			ttNode = tmpNode->m_pNext;
			tmpNode->m_pNext = tmpNode->m_pNext->m_pNext;
			delete ttNode;
			break;
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
	for (int i = 1; i < 20; i++){
		addListNode(root, i);
	}
	printList(root);
	deleteListNode(root, 3);
	printList(root);
	system("pause");
}
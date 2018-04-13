#include <iostream>
using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

ListNode* AddNode(ListNode* root, int value){

	ListNode* newNode = new ListNode();
	newNode->m_nValue = value;
	newNode->m_pNext = nullptr;

	if (root == nullptr){
		root = newNode;
	}
	else{
		ListNode* tmpNode = new ListNode();
		tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		tmpNode->m_pNext = newNode;
	}
	return root;
}

bool IsContainLoop(ListNode* root){
	if (root == nullptr){
		cout << "The list is empty." << endl;
		return false;
	}
	else{
		ListNode* tmpNode1 = root;
		ListNode* tmpNode2 = root->m_pNext;
		while (tmpNode2 != nullptr){
			tmpNode1 = tmpNode1->m_pNext;
			tmpNode2 = tmpNode2->m_pNext->m_pNext;
			if (tmpNode1 == tmpNode2){
				return true;
			}
		}
		return false;
	}
}

int GetLoopNode(ListNode* root){
	if (IsContainLoop(root) == true){
		ListNode* tmpNode1 = root;
		ListNode* tmpNode2 = root->m_pNext;
		while (tmpNode2 != nullptr){
			tmpNode1 = tmpNode1->m_pNext;
			tmpNode2 = tmpNode2->m_pNext->m_pNext;
			if (tmpNode1 == tmpNode2){
				tmpNode2 = tmpNode2->m_pNext;
				int sum = 1;
				while (tmpNode1 != tmpNode2){
					tmpNode2 = tmpNode2->m_pNext;
					sum++;
				}
				return sum;
			}
		}
	}
	else{
		return 0;
	}
}

ListNode* FindListTail(ListNode* root){
	if (root == nullptr){
		return nullptr;
	}
	else{
		ListNode* tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			tmpNode = tmpNode->m_pNext;
		}
		return tmpNode;
	}
}

ListNode* FindNode(ListNode* root, int value){
	if (root == nullptr){
		return nullptr;
	}
	else{
		ListNode* tmpNode = root;
		while (tmpNode->m_pNext != nullptr){
			if (tmpNode->m_nValue == value){
				return tmpNode;
			}
			tmpNode = tmpNode->m_pNext;
		}
		if (tmpNode->m_nValue == value){
			return tmpNode;
		}
		return nullptr;
	}
}

ListNode* FindEntryOfLoop(ListNode* root, int num){
	ListNode* tmpNode1 = root;
	ListNode* tmpNode2 = root;
	for (int i = 0; i < num; i++){
		tmpNode2 = tmpNode2->m_pNext;
	}
	while (tmpNode1 != tmpNode2){
		tmpNode1 = tmpNode1->m_pNext;
		tmpNode2 = tmpNode2->m_pNext;
	}
	return tmpNode1;
}

int main(void){
	ListNode* root = new ListNode();
	for (int i = 1; i <= 6; i++){
		AddNode(root, i);
	}
	if (IsContainLoop(root) == false){
		int n;
		cout << "�����ڻ�" << endl;
		cout << "���β�������ĸ��ڵ��ϣ�";
		cin >> n;
		cout << "������ing..." << endl;
		ListNode* tmpNode1 = FindListTail(root);
		ListNode* tmpNode2 = FindNode(root, n);
		tmpNode1->m_pNext = tmpNode2;
		cout << "�������" << endl;
		cout << "��黷ing..." << endl;
		if (IsContainLoop(root) == false){
			cout << "�����ڻ�������ʧ��" << endl;
		}
		else{
			cout << "�����ɹ�" << endl;
			cout << "���Ľڵ����Ϊ��";
			int num = GetLoopNode(root);
			cout << num << endl;
			cout << "������ڽڵ�Ϊ��";
			cout << FindEntryOfLoop(root, num)->m_nValue << endl;
		}
	}
	else{
		cout << "���ڻ�" << endl;
	}
	system("pause");
}
#include <iostream>
using namespace std;

struct ListNode{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode* pHead, int value){
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (pHead->m_pNext == nullptr){
		//pHead = pNew;
		pHead->m_pNext = pNew;
	}
	else{
		ListNode* pNode = pHead;
		while (pNode->m_pNext != nullptr){
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}
}

void PrintList(ListNode* pHead){
	if (pHead == nullptr){
		cout << "It's empty." << endl;
	}
	else{
		ListNode* pNode = pHead;
		cout << pNode->m_nValue << "--->";
		while (pNode->m_pNext != nullptr){
			pNode = pNode->m_pNext;
			cout << pNode->m_nValue << "--->";
		}
	}
}

//int main(void){
//	ListNode * pF = new ListNode();
//	//ListNode** pHead = &pF;
//	for (int i = 0; i < 10; i++){
//		//AddToTail(pHead, i);
//		AddToTail(pF, i);
//	}
//	PrintList(pF);
//	system("pause");
//}

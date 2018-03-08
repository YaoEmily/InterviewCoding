#include <iostream>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


BinaryTreeNode* ConstructNewNode(BinaryTreeNode* nNode, int value){
	nNode = new BinaryTreeNode();
	nNode->m_nValue = value;
	nNode->m_pLeft = nullptr;
	nNode->m_pRight = nullptr;

	return nNode;
}

BinaryTreeNode* Construct(
	BinaryTreeNode* root,
	int* a, int startA,
	int* b, int startB,
	int lenOfTree
	){
	// �ҳ����ڵ� ǰ���һ�� Ϊ���ڵ㸳ֵ
	root = ConstructNewNode(root, a[startA]);

	// �ҳ������еĸ��ڵ� ��Ϊ����������
	int leftStartB, leftLen, rightStartB, rightLen;
	for (int i = startB; i < startB + lenOfTree; i++){
		if (b[i] == a[startA]){
			leftStartB = startB;
			leftLen = i - leftStartB;
			rightStartB = i + 1;
			rightLen = startB + lenOfTree - rightStartB;
		}
	}

	// �ֳ�ǰ���е�����������
	int leftStartA, rightStartA;
	leftStartA = startA + 1;
	rightStartA = startA + leftLen + 1;

	// �ݹ�������������
	if (leftLen != 0){
		root->m_pLeft = Construct(root->m_pLeft, a, leftStartA, b, leftStartB, leftLen);
	}
	if (rightLen != 0){
		root->m_pRight = Construct(root->m_pRight, a, rightStartA, b, rightStartB, rightLen);
	}
	return root;
}

/*ǰ��������ṹ*/
void PrintBinaryTree(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << "--->";
		if (root->m_pLeft != nullptr){
			PrintBinaryTree(root->m_pLeft);
		}
		if (root->m_pRight != nullptr){
			PrintBinaryTree(root->m_pRight);
		}
	}
	else{
		cout << "The tree is empty." << endl;
	}
}

int main(void){
	int a[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
	int b[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
	int lenOfTree = sizeof(a) / sizeof(a[0]);
	BinaryTreeNode* root = nullptr;
	root = Construct(root, a, 0, b, 0, lenOfTree);
	PrintBinaryTree(root);
	system("pause");
}
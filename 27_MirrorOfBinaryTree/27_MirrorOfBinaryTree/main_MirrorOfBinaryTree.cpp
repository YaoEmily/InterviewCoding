#include <iostream>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* ReverseBinaryTree(BinaryTreeNode* root){
	if (root != nullptr){
		if (!(root->m_pLeft == nullptr && root->m_pRight == nullptr)){
			BinaryTreeNode* tmpNode = new BinaryTreeNode();
			tmpNode = root->m_pLeft;
			root->m_pLeft = root->m_pRight;
			root->m_pRight = tmpNode;
			/*ตÝน้*/
			root->m_pLeft = ReverseBinaryTree(root->m_pLeft);
			root->m_pRight = ReverseBinaryTree(root->m_pRight);
		}
	}
	return root;
}

BinaryTreeNode* addBinaryTreeNode(BinaryTreeNode* root, int value){
	BinaryTreeNode* newNode = new BinaryTreeNode();
	newNode->m_nValue = value;
	newNode->m_pLeft = nullptr;
	newNode->m_pRight = nullptr;
	root = newNode;
	return root;
}

void printBinaryTreeNode(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << " ";
		if (root->m_pLeft != nullptr){
			printBinaryTreeNode(root->m_pLeft);
		}
		if (root->m_pRight != nullptr){
			printBinaryTreeNode(root->m_pRight);
		}
	}
}

int main(void){
	BinaryTreeNode* root = new BinaryTreeNode();
	root = addBinaryTreeNode(root, 8);
	root->m_pLeft = addBinaryTreeNode(root->m_pLeft, 6);
	root->m_pRight = addBinaryTreeNode(root->m_pRight, 10);
	root->m_pLeft->m_pLeft = addBinaryTreeNode(root->m_pLeft->m_pLeft, 5);
	root->m_pLeft->m_pRight = addBinaryTreeNode(root->m_pLeft->m_pRight, 7);
	root->m_pRight->m_pLeft = addBinaryTreeNode(root->m_pRight->m_pLeft, 9);
	root->m_pRight->m_pRight = addBinaryTreeNode(root->m_pRight->m_pRight, 11);

	printBinaryTreeNode(root);
	cout << endl;

	BinaryTreeNode* newRoot = ReverseBinaryTree(root);
	printBinaryTreeNode(newRoot);
	cout << endl;
	
	system("pause");
}
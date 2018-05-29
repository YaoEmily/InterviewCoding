#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value){
	BinaryTreeNode* newNode = new BinaryTreeNode();
	newNode->m_nValue = value;
	newNode->m_pLeft = nullptr;
	newNode->m_pRight = nullptr;
	return newNode;
}

void ConnectBinaryTreeNodes(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTreeNode* node3){
	if (node1 != nullptr){
		if (node2 != nullptr){
			node1->m_pLeft = node2;
		}
		if (node3 != nullptr){
			node1->m_pRight = node3;
		}
	}
}

void PrintBinaryTree(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << " ";
		PrintBinaryTree(root->m_pLeft);
		PrintBinaryTree(root->m_pRight);
	}
}

void PirntBinaryTreeFromTopToBottom(BinaryTreeNode* root){
	if (root != nullptr){
		queue<BinaryTreeNode*> Q;
		Q.push(root);

		while (Q.empty() != true){
			BinaryTreeNode* tmpNode = Q.front();
			cout << tmpNode->m_nValue << " ";
			Q.pop();
			if (tmpNode->m_pLeft != nullptr){
				Q.push(tmpNode->m_pLeft);
			}
			if (tmpNode->m_pRight != nullptr){
				Q.push(tmpNode->m_pRight);
			}
		}
		cout << endl;
	}
}

int main(void){
	BinaryTreeNode* node1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* node2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* node3 = CreateBinaryTreeNode(5);
	BinaryTreeNode* node4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* node5 = CreateBinaryTreeNode(10);
	BinaryTreeNode* node6 = CreateBinaryTreeNode(9);
	BinaryTreeNode* node7 = CreateBinaryTreeNode(11);

	ConnectBinaryTreeNodes(node1, node2, node5);
	ConnectBinaryTreeNodes(node2, node3, node4);
	ConnectBinaryTreeNodes(node5, node6, node7);

	PrintBinaryTree(node1);
	cout << endl;

	PirntBinaryTreeFromTopToBottom(node1);

	system("pause");
}
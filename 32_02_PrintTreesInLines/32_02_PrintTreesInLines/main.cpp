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
	newNode->m_pLeft = newNode->m_pRight = nullptr;
	return newNode;
}

void ConnectBinaryTreeNodes(BinaryTreeNode* node1, BinaryTreeNode* node2, BinaryTreeNode* node3){
	if (node1 != nullptr){
		node1->m_pLeft = node2;
		node1->m_pRight = node3;
	}
}

void PrintBinaryTrees(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << " ";
		PrintBinaryTrees(root->m_pLeft);
		PrintBinaryTrees(root->m_pRight);
	}
}

void PrintBinaryTreesInLines(BinaryTreeNode* root){
	if (root != nullptr){
		queue<BinaryTreeNode*> Q;
		Q.push(root);
		int currentRemaining = 1;
		int nextRemaining = 0;
		while (Q.empty() != true){
			cout << Q.front()->m_nValue << " ";
			currentRemaining--;
			if (Q.front()->m_pLeft != nullptr){
				nextRemaining++;
				Q.push(Q.front()->m_pLeft);
			}
			if (Q.front()->m_pRight != nullptr){
				nextRemaining++;
				Q.push(Q.front()->m_pRight);
			}
			if (currentRemaining == 0){
				cout << endl;
				currentRemaining = nextRemaining;
				nextRemaining = 0;
			}
			Q.pop();
		}
		cout << endl;
	}
}

int main(void){
	BinaryTreeNode* node1 = CreateBinaryTreeNode(8);
	BinaryTreeNode* node2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* node3 = CreateBinaryTreeNode(10);
	BinaryTreeNode* node4 = CreateBinaryTreeNode(5);
	BinaryTreeNode* node5 = CreateBinaryTreeNode(7);
	BinaryTreeNode* node6 = CreateBinaryTreeNode(9);
	BinaryTreeNode* node7 = CreateBinaryTreeNode(11);

	ConnectBinaryTreeNodes(node1, node2, node3);
	ConnectBinaryTreeNodes(node2, node4, node5);
	ConnectBinaryTreeNodes(node3, node6, node7);

	PrintBinaryTrees(node1);
	cout << endl;

	PrintBinaryTreesInLines(node1);

	system("pause");
}
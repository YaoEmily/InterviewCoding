#include <iostream>
#include <map>
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

void PrintBinaryTree(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << " ";
		PrintBinaryTree(root->m_pLeft);
		PrintBinaryTree(root->m_pRight);
	}
}

void ConvertToDoubleLinkedList(BinaryTreeNode* root, map<BinaryTreeNode*, bool> isLeaf){
	if (root != nullptr){
		if (isLeaf[root] == false){
			if (root->m_pLeft != nullptr){
				//找左子树最大的
				BinaryTreeNode* tmpNode = root->m_pLeft;
				BinaryTreeNode* leftSubTree = root->m_pLeft;
				while (tmpNode->m_pRight != nullptr){
					tmpNode = tmpNode->m_pRight;
				}
				//连接
				tmpNode->m_pRight = root;
				root->m_pLeft = tmpNode;
				ConvertToDoubleLinkedList(leftSubTree, isLeaf);
			}
			if (root->m_pRight != nullptr){
				//找右子树最大的
				BinaryTreeNode* tmpNode = root->m_pRight;
				BinaryTreeNode* rightSubTree = root->m_pRight;
				while (tmpNode->m_pLeft != nullptr){
					tmpNode = tmpNode->m_pLeft;
				}
				//连接
				tmpNode->m_pLeft = root;
				root->m_pRight = tmpNode;
				ConvertToDoubleLinkedList(rightSubTree, isLeaf);
			}
		}
	}
}

void printDoubleLinkedList(BinaryTreeNode* root){
	BinaryTreeNode* tmpNode = root;
	if (root != nullptr){
		while (tmpNode->m_pLeft != nullptr){
			tmpNode = tmpNode->m_pLeft;
		}
		cout << tmpNode->m_nValue << " ";
		while (tmpNode->m_pRight != nullptr){
			tmpNode = tmpNode->m_pRight;
			cout << tmpNode->m_nValue << " ";
		}
		cout << endl;
	}
}

int main(void){
	BinaryTreeNode* nodes[7];
	nodes[0] = CreateBinaryTreeNode(10);
	nodes[1] = CreateBinaryTreeNode(6);
	nodes[2] = CreateBinaryTreeNode(4);
	nodes[3] = CreateBinaryTreeNode(8);
	nodes[4] = CreateBinaryTreeNode(14);
	nodes[5] = CreateBinaryTreeNode(12);
	nodes[6] = CreateBinaryTreeNode(16);
	ConnectBinaryTreeNodes(nodes[0], nodes[1], nodes[4]);
	ConnectBinaryTreeNodes(nodes[1], nodes[2], nodes[3]);
	ConnectBinaryTreeNodes(nodes[4], nodes[5], nodes[6]);
	PrintBinaryTree(nodes[0]);
	cout << endl;

	map<BinaryTreeNode*, bool> isLeaf;
	isLeaf[nodes[0]] = isLeaf[nodes[1]] = isLeaf[nodes[2]] = false;
	isLeaf[nodes[2]] = isLeaf[nodes[3]] = isLeaf[nodes[5]] = isLeaf[nodes[6]] = true;
	
	ConvertToDoubleLinkedList(nodes[0], isLeaf);
	printDoubleLinkedList(nodes[0]);
	system("pause");
}
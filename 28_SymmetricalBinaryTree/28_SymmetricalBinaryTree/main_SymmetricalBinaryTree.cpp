#include <iostream>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pSon[2];
};

bool IsSymmetricalNode(BinaryTreeNode* root1, BinaryTreeNode* root2);

BinaryTreeNode* addBinaryTreeNode(BinaryTreeNode* root, int value){
	BinaryTreeNode* newNode = new BinaryTreeNode();
	newNode->m_nValue = value;
	newNode->m_pSon[0] = nullptr;
	newNode->m_pSon[1] = nullptr;

	root = newNode;
	return root;
}

void printBinaryTree(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_nValue << " ";
		if (root->m_pSon[0] != nullptr){
			printBinaryTree(root->m_pSon[0]);
		}
		if (root->m_pSon[1] != nullptr){
			printBinaryTree(root->m_pSon[1]);
		}
	}
}

bool IsSymmetricalBinaryTree(BinaryTreeNode* root){
	if (root == nullptr){
		return false;
	}
	if (root->m_pSon[0] == nullptr&&root->m_pSon[1] == nullptr){
		return true;
	}
	if (root->m_pSon[0] == nullptr || root->m_pSon[1] == nullptr){
		return false;
	}
	BinaryTreeNode* leftSubTree = root->m_pSon[0];
	BinaryTreeNode* rightSubTree = root->m_pSon[1];
	return IsSymmetricalNode(leftSubTree, rightSubTree);
}

bool IsSymmetricalNode(BinaryTreeNode* root1, BinaryTreeNode* root2){
	if (root1 != nullptr && root2 != nullptr){
		if (root1->m_nValue == root2->m_nValue){
			return IsSymmetricalNode(root1->m_pSon[0], root2->m_pSon[1]) && IsSymmetricalNode(root1->m_pSon[1], root2->m_pSon[0]);
		}
		else{
			return false;
		}
	}
	else if (root1 == nullptr && root2 == nullptr){
		return true;
	}
	else{
		return false;
	}
}

int main(void){
	BinaryTreeNode* root = new BinaryTreeNode();
	root = addBinaryTreeNode(root, 8);
	root->m_pSon[0] = addBinaryTreeNode(root->m_pSon[0], 6);
	root->m_pSon[1] = addBinaryTreeNode(root->m_pSon[1], 6);
	root->m_pSon[0]->m_pSon[0] = addBinaryTreeNode(root->m_pSon[0]->m_pSon[0], 5);
	root->m_pSon[1]->m_pSon[1] = addBinaryTreeNode(root->m_pSon[1]->m_pSon[1], 5);
	root->m_pSon[0]->m_pSon[1] = addBinaryTreeNode(root->m_pSon[0]->m_pSon[1], 7);
	root->m_pSon[1]->m_pSon[0] = addBinaryTreeNode(root->m_pSon[1]->m_pSon[0], 7);

	printBinaryTree(root);
	cout << endl;
	cout << IsSymmetricalBinaryTree(root) << endl;

	system("pause");
}
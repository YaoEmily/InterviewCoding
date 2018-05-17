#include <iostream>
using namespace std;

struct BinaryTreeNode{
	double m_dbValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);

/*找根节点相同的入口*/
bool DoesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
	bool flag = false;
	if (pRoot1 != nullptr){
		if (pRoot1->m_dbValue == pRoot2->m_dbValue){
			flag = HasSubTree(pRoot1->m_pLeft, pRoot2->m_pLeft);
			if (flag == true){
				flag = HasSubTree(pRoot1->m_pRight, pRoot2->m_pRight);
			}
			if (flag == true){
				return true;
			}
		}
		if (flag == false){
			flag = DoesTree1HaveTree2(pRoot1->m_pLeft, pRoot2);
		}
		if (flag == false){
			flag = DoesTree1HaveTree2(pRoot1->m_pRight, pRoot2);
		}
		if (flag == true){
			return true;
		}
	}
	return false;
}

/*找子节点相同的*/
bool HasSubTree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
	bool flag = false;
	if (pRoot2 == nullptr){
		return true;
	}
	if (pRoot1 == nullptr){
		return false;
	}
	if (pRoot1->m_dbValue == pRoot2->m_dbValue){
		flag = HasSubTree(pRoot1->m_pLeft, pRoot2->m_pLeft);
		if (flag == true){
			flag = HasSubTree(pRoot1->m_pRight, pRoot2->m_pRight);
		}
		if (flag == true){
			return true;
		}
	}
	return false;
}

BinaryTreeNode* addBinaryTreeNode(BinaryTreeNode* root, int value){
	BinaryTreeNode* newNode = new BinaryTreeNode();
	newNode->m_dbValue = value;
	newNode->m_pLeft = nullptr;
	newNode->m_pRight = nullptr;
	root = newNode;
	return root;
}

void printBinaryTreeNode(BinaryTreeNode* root){
	if (root != nullptr){
		cout << root->m_dbValue;
		if (root->m_pLeft != nullptr){
			printBinaryTreeNode(root->m_pLeft);
		}
		if (root->m_pRight != nullptr){
			printBinaryTreeNode(root->m_pRight);
		}
	}
}

int main(void){
	/*初始化树*/
	BinaryTreeNode* root = new BinaryTreeNode();
	root = addBinaryTreeNode(root, 8);
	root->m_pLeft = addBinaryTreeNode(root->m_pLeft, 8);
	root->m_pRight = addBinaryTreeNode(root->m_pRight, 7);
	root->m_pLeft->m_pLeft = addBinaryTreeNode(root->m_pLeft->m_pLeft, 9);
	root->m_pLeft->m_pRight = addBinaryTreeNode(root->m_pLeft->m_pRight, 2);
	root->m_pLeft->m_pRight->m_pLeft = addBinaryTreeNode(root->m_pLeft->m_pRight->m_pLeft, 4);
	root->m_pLeft->m_pRight->m_pRight = addBinaryTreeNode(root->m_pLeft->m_pRight->m_pRight, 7);
	
	/*初始化子树*/
	BinaryTreeNode* kidRoot = new BinaryTreeNode();
	kidRoot = addBinaryTreeNode(kidRoot, 8);
	kidRoot->m_pLeft = addBinaryTreeNode(kidRoot->m_pLeft, 9);
	kidRoot->m_pRight = addBinaryTreeNode(kidRoot->m_pRight, 2);

	/*打印两个树*/
	printBinaryTreeNode(root);
	cout << endl;
	printBinaryTreeNode(kidRoot);
	cout << endl;

	bool res = DoesTree1HaveTree2(root, kidRoot);
	cout << res << endl;

	system("pause");
}
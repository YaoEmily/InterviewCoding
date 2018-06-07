#include <iostream>
#include <deque>
using namespace std;

struct BinaryTreeNode{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void PathInTreeInSameValue(BinaryTreeNode* node, deque<BinaryTreeNode*>& DQ, int const value, int& currentValue);
void __PathIsValue(deque<BinaryTreeNode*>& DQ);

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

void function(BinaryTreeNode* root, int value){
	deque<BinaryTreeNode*> DQ;
	int sum = 0;
	PathInTreeInSameValue(root, DQ, value, sum);
}

void PathInTreeInSameValue(BinaryTreeNode* node, deque<BinaryTreeNode*>& DQ, int const value, int& currentValue){
	//是否是叶节点
	bool isLeaf = (node->m_pLeft == nullptr && node->m_pRight == nullptr);
	currentValue += node->m_nValue;
	DQ.push_front(node);
	if (currentValue == value && isLeaf == true){
		//输出
		__PathIsValue(DQ);
	}
	else if (currentValue < value&&isLeaf == false){
		//遍历左右节点
		if (node->m_pLeft != nullptr){
			PathInTreeInSameValue(node->m_pLeft, DQ, value, currentValue);
		}
		if (node->m_pRight != nullptr){
			PathInTreeInSameValue(node->m_pRight, DQ, value, currentValue);
		}
	}
	
	currentValue -= node->m_nValue;
	DQ.pop_front();
}

void __PathIsValue(deque<BinaryTreeNode*>& DQ){
	deque<BinaryTreeNode*> DQ2;
	while (DQ.empty() == false){
		cout << DQ.back()->m_nValue << " ";
		DQ2.push_front(DQ.back());
		DQ.pop_back();
	}
	cout << endl;
	DQ = DQ2;
}

void PrintQueue(deque<BinaryTreeNode*> DQ){
	while (DQ.empty() == false){
		
	}
}

int main(void){
	BinaryTreeNode* node1 = CreateBinaryTreeNode(10);
	BinaryTreeNode* node2 = CreateBinaryTreeNode(5);
	BinaryTreeNode* node3 = CreateBinaryTreeNode(4);
	BinaryTreeNode* node4 = CreateBinaryTreeNode(7);
	BinaryTreeNode* node5 = CreateBinaryTreeNode(12);

	ConnectBinaryTreeNodes(node1, node2, node5);
	ConnectBinaryTreeNodes(node2, node3, node4);

	PrintBinaryTree(node1);
	cout << endl;

	function(node1, 22);

	system("pause");
}
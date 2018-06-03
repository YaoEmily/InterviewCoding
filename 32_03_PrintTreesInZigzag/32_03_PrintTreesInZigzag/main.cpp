#include <iostream>
#include <deque>
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

void PrintBinaryTreeInZigzag(BinaryTreeNode* root){
	if (root != nullptr){
		deque<BinaryTreeNode*> DQ;
		DQ.push_front(root);
		int currentNode = 1;
		int nextNode = 0;
		int flag = 1;
		while (DQ.empty() != true){
			BinaryTreeNode* tmpNode;
			if (flag){
				tmpNode = DQ.back();
				DQ.pop_back();
				cout << tmpNode->m_nValue << " ";
				currentNode--;
				if (tmpNode->m_pLeft != nullptr){
					DQ.push_front(tmpNode->m_pLeft);
					nextNode++;
				}
				if (tmpNode->m_pRight != nullptr){
					DQ.push_front(tmpNode->m_pRight);
					nextNode++;
				}
			}
			else{
				tmpNode = DQ.front();
				DQ.pop_front();
				cout << tmpNode->m_nValue << " ";
				currentNode--;
				if (tmpNode->m_pRight != nullptr){
					DQ.push_back(tmpNode->m_pRight);
					nextNode++;
				}
				if (tmpNode->m_pLeft != nullptr){
					DQ.push_back(tmpNode->m_pLeft);
					nextNode++;
				}
			}
			if (currentNode == 0){
				currentNode = nextNode;
				nextNode = 0;
				flag == 1 ? flag = 0 : flag = 1;
				cout << endl;
			}
		}
	}
}

int main(void){
	BinaryTreeNode* nodes[15];
	for (int i = 0; i < 15; i++){
		nodes[i] = CreateBinaryTreeNode(i + 1);
	}
	ConnectBinaryTreeNodes(nodes[0], nodes[1], nodes[2]);
	ConnectBinaryTreeNodes(nodes[1], nodes[3], nodes[4]);
	ConnectBinaryTreeNodes(nodes[2], nodes[5], nodes[6]);
	ConnectBinaryTreeNodes(nodes[3], nodes[7], nodes[8]);
	ConnectBinaryTreeNodes(nodes[4], nodes[9], nodes[10]);
	ConnectBinaryTreeNodes(nodes[5], nodes[11], nodes[12]);
	ConnectBinaryTreeNodes(nodes[6], nodes[13], nodes[14]);

	PrintBinaryTree(nodes[0]);
	cout << endl;

	PrintBinaryTreeInZigzag(nodes[0]);

	system("pause");
}
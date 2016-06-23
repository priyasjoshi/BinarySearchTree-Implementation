#pragma once

#include "Node.h"
#include<climits>

using namespace std;
class BSTImplementation
{
private:
	Node* m_pRoot = nullptr;

public:
	BSTImplementation();
	~BSTImplementation();
	void Insert(int nData);
	void InorderTraversal();
	void PreorderTraversal();
	void PostorderTraversal();
	Node* Search(int data);
	void deleteNode(int data);
	int InorderSuccessor(int data);
private:
	void Insert(int nData, Node* pNode);
	void InorderTraversal(Node* pNode);
	void PreorderTraversal(Node* pNode);
	void PostorderTraversal(Node* pNode);
	Node* Search(int data,Node* pNode);
	void Delete(Node* pNode);
	Node* deleteNode(int data, Node* pNode);
	Node* minValue(Node* pNode);
	Node* InorderSuccessor(Node* pNode, int data);
};


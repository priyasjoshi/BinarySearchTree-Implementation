#include<iostream>
#include "BSTImplementation.h"
using namespace std;

BSTImplementation::BSTImplementation()
{
	m_pRoot = NULL;
}


BSTImplementation::~BSTImplementation()
{
	Delete(m_pRoot);
}

void BSTImplementation::Insert(int nData)
{
	if (m_pRoot == NULL)
	{
		m_pRoot = new Node();
		m_pRoot->data = nData;
	}
	else
	{
		Insert(nData, m_pRoot);
	}
}

void BSTImplementation::InorderTraversal()
{
	cout << "Inorder Traversal" << endl;
	InorderTraversal(m_pRoot);
}

void BSTImplementation::PreorderTraversal()
{
	cout << "Preorder Traversal" << endl;
	PreorderTraversal(m_pRoot);
}

void BSTImplementation::PostorderTraversal()
{
	cout << "Postorder Traversal" << endl;
	PostorderTraversal(m_pRoot);
}

 void::BSTImplementation::Insert(int nData, Node* pNode)
	{
	if (nData <= pNode->data) 
	{
		if (pNode->LeftChild == NULL) 
		{
			pNode->LeftChild = new Node();
			pNode->LeftChild->data = nData;
		}
		else
		{
			Insert(nData, pNode->LeftChild);
		}
	}
	else
	{
		if (pNode->RightChild == NULL) 
		{
			pNode->RightChild = new Node();
			pNode->RightChild->data = nData;
		}
		else 
		{
			Insert(nData, pNode->RightChild);
		}
	}
}
void BSTImplementation::InorderTraversal(Node* pNode) 
{
	if (pNode ==NULL)
	{
		return;
	}
	else
	{
		InorderTraversal(pNode->LeftChild);
		std::cout << pNode->data << std::endl;
		InorderTraversal(pNode->RightChild); 
	}
}

void BSTImplementation::PreorderTraversal(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	else
	{
		std::cout << pNode->data << std::endl;
		PreorderTraversal(pNode->LeftChild);
		PreorderTraversal(pNode->RightChild);
	}
}

void BSTImplementation::PostorderTraversal(Node* pNode)
{
	if (pNode == NULL)
	{
		return;
	}
	else
	{
		PostorderTraversal(pNode->LeftChild);
		PostorderTraversal(pNode->RightChild);
		std::cout << pNode->data << std::endl;
	}
}
void BSTImplementation::Delete(Node* pNode)
{
	if (pNode != NULL)
	{
		Delete(pNode->LeftChild);
		Delete(pNode->RightChild);
		pNode = NULL;
	}
}
Node* BSTImplementation::Search(int data)
{
	Node* result = NULL;
	if (m_pRoot!=NULL)
	{
		result = Search(data, m_pRoot);
	}
	return result;
}
Node* BSTImplementation::Search(int data,Node* pNode)
{
	if (pNode != NULL)
	{
		if (data == pNode->data)
		{
			return pNode;
		}
		else if (data < pNode->data)
		{
			Search(data, pNode->LeftChild);
		}
		else
		{
			Search(data, pNode->RightChild);
		}
	}
	else
	{
		return NULL;
	}
} 
void BSTImplementation::deleteNode(int data)
{
	if (m_pRoot != NULL)
	{
		deleteNode(data, m_pRoot);
	}
}
int BSTImplementation::InorderSuccessor(int data)
{
	Node* result = NULL;
	if (m_pRoot!=NULL)
	{
		result = InorderSuccessor(m_pRoot, data);
	}
	return result->data;
}
Node* BSTImplementation::deleteNode(int data,  Node* pNode)
{
	if (data < pNode->data)
	{
		pNode->LeftChild = deleteNode(data,pNode->LeftChild);
	}
	else if (data> pNode->data)
	{
		pNode->RightChild = deleteNode(data, pNode->RightChild);
	}
	else
	{
		if (pNode->LeftChild==NULL && pNode->RightChild==NULL)
		{
			delete pNode;
			pNode = NULL;
		}
		else if (pNode->LeftChild == NULL)
		{
			Node *temp = pNode;
			pNode = pNode->RightChild;
			temp = NULL;
			delete temp;
			
		}
		else if (pNode->RightChild == NULL)
		{
			Node *temp = pNode;
			pNode = pNode->LeftChild;
			temp = NULL;
			delete temp;
		}
		else
		{
			Node *temp = minValue(pNode->RightChild);
			pNode->data = temp->data;
			temp = NULL;
			delete temp;
		}
	}
	return pNode;
}

Node* BSTImplementation::minValue(Node* pNode) 
{
	Node* current = pNode;
	while (current->LeftChild!=NULL)
	{
		current = current->LeftChild;
	}
	return current;
}

Node * BSTImplementation::InorderSuccessor(Node * pNode, int data)
{
	Node* Successor = NULL;
	Node* current = Search(data, pNode);
	Node* ancestor = pNode;
	if (current->RightChild!=NULL)
	{
		Successor = minValue(current->RightChild);
	}
	else
	{
		while (ancestor!= current)
		{
			if (current->data < ancestor->data)
			{
				Successor = ancestor;
				ancestor = ancestor->LeftChild;
			}
			else
			{
				ancestor = ancestor->RightChild;
			}
		}
	}
	return Successor;
}



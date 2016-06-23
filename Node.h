#ifndef NODE_H_
#define NODE_H_

class Node{
public:
	int data;
	Node* LeftChild;
	Node* RightChild;

	Node() {
		LeftChild = nullptr;
		RightChild = nullptr;
	}
};

#endif 
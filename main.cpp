#include "BSTImplementation.h"
#include<iostream>
int main()
{
	BSTImplementation tree;
	 tree.Insert(20);
	 tree.Insert(25);
	 tree.Insert(15);
	 tree.Insert(10);
	 tree.Insert(17);
	 tree.Insert(7);
	 tree.Insert(23);
	 tree.Insert(30);
	 tree.Insert(27);
	 tree.InorderTraversal();
	 tree.PreorderTraversal();
	 tree.PostorderTraversal();
	 Node* result = tree.Search(25);
	 if (result!=NULL) 
	 {
		 std::cout << "Found !" << std::endl;
	 }
	 else
	 {
		 std::cout << "Not Found !" << std::endl;
	 }
	 //tree.deleteNode(20);
	 //tree.InorderTraversal();

	 int sucessor = tree.InorderSuccessor(23);
	 std::cout << "Inorder Successor is : " << sucessor << std::endl;
	 system("pause");
	 return 0;
}
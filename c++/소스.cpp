#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	cout << "20192628 임지혁" << endl; 
	//typedef BinaryTree < char > charTree;
	//typedef charTree * charTreePtr;// Create tree from Figure 11-2// Create left subtree (rooted at B
	//charTreePtr bt1(new charTree);
	//bt1->insert('D');// Create B's right 
	//charTreePtr bt2(new charTree);
	//bt2->insert('E');
	//												// Create node containing B, and link// up to subtrees
	//charTreePtr bt3(new charTree);
	//bt3->insert('B');
	//bt3->makeLeft(bt1);
	//bt3->makeRight(bt2);// ** done creating left subtree

	//charTreePtr bt4(new charTree); //반복
	//bt4->insert('F');// Create node containing C, and link// up its right subtree
	//charTreePtr bt5(new charTree);
	//bt5->insert('C');
	//bt5->makeRight(bt4);
	//// ** done creating right subtree

	//charTreePtr bt6(new charTree); 
	//bt6->insert('A');
	//bt6->makeLeft(bt3);
	//bt6->makeRight(bt5);
	//// print out the root
	//cout << "Root contains: " << bt6->getData() << endl;
	//// print out root of left subtree
	//cout << "Left subtree root: " << bt6->left()->getData() << endl;
	//// print out root of right subtree
	//cout << "Right subtree root: " << bt6->right()->getData() << endl;

	//cout << "Leftmost child is: " << bt6->left()->left()->getData() << endl;
	//// print out rightmost child in tree
	//cout << "Rightmost child is: " <<bt6->right()->right()->getData() << endl;

	// top -down 방식으로도 해보기 

	typedef BinaryTree < char > charTree;
	typedef charTree* charTreePtr;

	charTreePtr bt1(new charTree);
	bt1->insert('A');

	charTreePtr bt2(new charTree);
	bt2->insert('B');

	charTreePtr bt3(new charTree);
	bt3->insert('C');

	bt1->makeLeft(bt2); //OR bt1->left()->insert('b');; 도 가능 
	bt1->makeRight(bt3);

	charTreePtr bt4(new charTree);
	bt4->insert('D');

	charTreePtr bt5(new charTree);
	bt5->insert('E');

	bt2->makeLeft(bt4);
	bt2->makeRight(bt5);

	charTreePtr bt6(new charTree);
	bt6->insert('F');

	bt3->makeRight(bt6);

	cout << "Root contains: " << bt1->getData() << endl;
	// print out root of left subtree
	cout << "Left subtree root: " << bt1->left()->getData() << endl;
	// print out root of right subtree
	cout << "Right subtree root: " << bt1->right()->getData() << endl;

	cout << "Leftmost child is: " << bt1->left()->left()->getData() << endl;
	// print out rightmost child in tree
	cout << "Rightmost child is: " << bt1->right()->right()->getData() << endl;



	return 0;
}
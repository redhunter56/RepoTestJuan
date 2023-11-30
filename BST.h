#pragma once
#include <vector>
#include<memory>
template<class ItemType>
class BST
{
private:
	ItemType m_value = -1;

	std::shared_ptr<BST<ItemType>> m_left;

	std::shared_ptr<BST<ItemType>> m_right;

	int treeSize = 0;
	
public:
	//copnstructor
	BST();
	//deconstructor
	virtual ~BST();

	//inserts a number into the tree
	bool insertNum(ItemType val);

	//takes a value and trys to find it in the tree returning true if found otherwise false
	bool findNum(ItemType val);

	//tries to remove a number from the tree returning true if completed otherwise false
	bool removeNum(ItemType val, std::shared_ptr<BST<ItemType>> &BSTnode = nullptr);

	//returns private data member treeSize
	int getTreeSize();

	//returns a vector of the nodes in a tree in Ascending INORDER order 
	std::vector<std::shared_ptr<BST<ItemType>>> getAscending(std::vector<std::shared_ptr<BST<ItemType>>> & bstVec);

	//sets m_value
	void setItem(const ItemType& val);

	//sets m_left
	void setLeft(std::shared_ptr<BST<ItemType>> nextNodePtr);

	//sets m_right
	void setRight(std::shared_ptr<BST<ItemType>> nextNodePtr);

	//returns m_value
	ItemType getItem() const;

	//deletes a node and all of its lower nodes
	void clear(std::shared_ptr<BST<ItemType>> root = nullptr);

	//returns m_left
	std::shared_ptr<BST<ItemType>> getLeft() const;

	//returns m_right
	std::shared_ptr<BST<ItemType>> getRight() const;

};

#include "BST.cpp"
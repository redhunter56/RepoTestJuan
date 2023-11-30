#include <iostream>
#include <vector>
#include "BST.h"









template<class ItemType>
BST<ItemType>::BST()
{

}


template<class ItemType>
BST<ItemType>::~BST()
{
     treeSize = 0;
}


template<class ItemType>
bool BST<ItemType>::insertNum(ItemType val)
{   
    BST<ItemType> temp;
    std::shared_ptr<BST<ItemType>> newBST = std::make_shared<BST<ItemType>>(temp);
    newBST->setItem(val);

//if no values on left or right put the valuse on the left side
    if(m_left == nullptr && m_right == nullptr){
        m_left = newBST;
        treeSize++;
        
        return true;
    }
    //if a value is on the left if the new value is greater than the left value put it on the right
    // otherwise swap the left to the right and set the left as the new value
    else if(m_right == nullptr && newBST->getItem() >= m_left->getItem()){
        m_right = newBST;
        treeSize++;
       
        return true;
    }
    else if(m_right == nullptr && newBST->getItem() < m_left->getItem()) {
        m_right = m_left;
        m_left = newBST;
        treeSize++;
        
        return true;
    } 

    //if the node is full, recursively go through the nodes to find a place to put the number
    else if(m_left->insertNum(val)){
        treeSize++;
        return true;
    }
     else if(m_right->insertNum(val)){
        treeSize++;
        return true;
    }
    

    return false;
}


template<class ItemType>
bool BST<ItemType>::findNum(ItemType val){
  
  //if the tree isnt empty
   if(treeSize != 0)
   {
    //check the current node, left node, and right node for the value
        if(m_value == val)
        {
            return true;
        }
        if(m_left != nullptr && m_left->m_value == val){
            return true;
        }
        else if(m_right != nullptr && m_right->m_value == val){
            return true;
        }
        //if not found recursively go through the tree looking for the number
        if  (m_left != nullptr && m_left->findNum(val)){
            return true;
        }
        if(m_right != nullptr && m_right->findNum(val)){
        return true;
        }

        return false;
        
   }
   return false;
}

template<class ItemType>
bool BST<ItemType>::removeNum(ItemType val, std::shared_ptr<BST<ItemType>> &BSTnode)
{
    //if at the root set the BSTnode to the root
    if(BSTnode->getItem() == -1){
        BSTnode = std::make_shared<BST<ItemType>>(*this);
    }
    
    
    std::shared_ptr<BST<ItemType>> temp;
    //check if the number is even in the tree
    if(findNum(val)){
       
       //if the position of the number is found there are 3 different routes to take
        if(m_value == val)
        {
            //if the right node is null simply move the left node up and delete the current node
            if(BSTnode->getRight() == nullptr){
                temp = BSTnode;
                BSTnode = BSTnode->getLeft();
                temp->clear();
            }
            //if the right node is not null we put the right node on the leftmost part
            // of the left node
            else{
                while(temp->getLeft() != nullptr){
                    temp = temp->getLeft();
                }
                temp->setLeft(m_right);
                temp = BSTnode;
                BSTnode = BSTnode->getLeft();
                temp->clear();

            }
            return true;
        }
        //if the right node is equal to the value and both it's left and right node are null delete it and set it null
        else if(m_right->getItem()== val && m_right->getRight() == nullptr && m_right->getLeft() == nullptr){
            m_right->clear();
            m_right = nullptr;
            return true;
        }
        //recursively go through the tree trying to remove the number
        else{
            if(m_left != nullptr && m_left->removeNum(val, m_left)){
                return true;
            }
            if(m_right != nullptr && m_right->removeNum(val, m_right)){
                return true;
            }
        }
    }
    return false;
}

template <class ItemType>
int BST<ItemType>::getTreeSize()
{
    return treeSize;
}



template <class ItemType>
std::vector<std::shared_ptr<BST<ItemType>>> BST<ItemType>::getAscending(std::vector<std::shared_ptr<BST<ItemType>>> & bstVec)
{   
    

std::shared_ptr<BST<ItemType>> temp = std::make_shared<BST<ItemType>>(*this);

//recursively gets to the leftmost node in the tree
    if(m_left != nullptr){  
        m_left->getAscending(bstVec);
    }
    //if root hasnt been set (value of -1 when not set) push back the root
    else if(this->getItem() != -1){
        bstVec.push_back(temp);
    }
    // if both left and right nodes arent null push back the node
    if(m_left != nullptr && m_right != nullptr && bstVec[bstVec.size()-1] != temp){
            bstVec.push_back(temp);   
    }
    //if the right node isnt null go through the right side to check for more values
    if(m_right != nullptr){
        m_right->getAscending(bstVec);   
    }
    
    return bstVec;
}


template<class ItemType>
void BST<ItemType>::setItem(const ItemType &val)
{
	m_value = val;
    treeSize++;
    
}

template<class ItemType>
void BST<ItemType>::setLeft(std::shared_ptr<BST<ItemType>> nextNodePtr)
{
	m_left = nextNodePtr;
}

template<class ItemType>
void BST<ItemType>::setRight(std::shared_ptr<BST<ItemType>> nextNodePtr)
{
	m_right = nextNodePtr;
}

template <class ItemType>
ItemType BST<ItemType>::getItem() const
{
	return m_value;
}

template <class ItemType>
void BST<ItemType>::clear(std::shared_ptr<BST<ItemType>> root)
{
    //effectively deletes the right and left node pointers and then deconstructs the node
    m_left.reset();
    m_right.reset();
    this->~BST();
}


template <class ItemType>
std::shared_ptr<BST<ItemType>> BST<ItemType>::getRight() const
{
    return m_right;
}



template<class ItemType>
std::shared_ptr<BST<ItemType>> BST<ItemType>::getLeft() const
{
	return m_left;
}




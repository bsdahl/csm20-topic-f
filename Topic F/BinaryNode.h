//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of nodes for a link-based binary tree.
 Listing 16-2.
 @file BinaryNode.h */
 
#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode
{   
private:
   int balance;
   ItemType              item;           // Data portion
   BinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
   BinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
   BinaryNode();
   BinaryNode(const ItemType& anItem);
   BinaryNode(const ItemType& anItem,
              BinaryNode<ItemType>* leftPtr,
              BinaryNode<ItemType>* rightPtr);

   void setItem(const ItemType& anItem);
   ItemType getItem() const;
   
   bool isLeaf() const;

   BinaryNode<ItemType>* getLeftChildPtr() const;
   BinaryNode<ItemType>* getRightChildPtr() const;
   
   void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
   void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
   int getBalance() { return balance; }
   void setBalance(const int& newBalance) { balance = newBalance; }
   const BinaryNode<ItemType> &operator = (const BinaryNode<ItemType> & right);
}; // end BinaryNode





// Implementation







template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem)
: item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr)
{
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,BinaryNode<ItemType>* leftPtr,BinaryNode<ItemType>* rightPtr)
: item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr)
{
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
    return ((leftChildPtr == nullptr) && (rightChildPtr == nullptr));
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(BinaryNode<ItemType>* leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(BinaryNode<ItemType>* rightPtr)
{
    rightChildPtr = rightPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

template<class ItemType>
BinaryNode<ItemType>* BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}
template<class ItemType>
const BinaryNode<ItemType> & BinaryNode<ItemType>::operator = (const BinaryNode<ItemType> & right)
{
    if (this == &right)
        return *this;
    item = right.item;
    leftChildPtr = right.leftChildPtr;
    rightChildPtr = right.rightChildPtr;
    return *this;
}

#endif 

#include "Tree.h"
#include <queue>
#include <iostream>
using namespace std;

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const
{
    return (root == NULL);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
    root = NULL;
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const
{
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const
{
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const
{
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const
{
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const
{
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const
{
    return leafCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::leafCount(binaryTreeNode<elemType> *p) const{
    if (p == NULL){ // Empty root (should only call if the entire tree is empty)
        return 0;
    }
    else if (p -> llink == NULL && p -> rlink == NULL){ // P is a Leaf
        return 1;
    }
    else{ // Reccursively search for leaves
        return leafCount(p -> llink) + leafCount(p -> rlink);
    }
}

template <class elemType>
int binaryTreeType<elemType>::nrleafCount(binaryTreeNode<elemType> *p) const{
    queue<binaryTreeNode<elemType>*> nodeQueue; //FIFO to store nodes
    nodeQueue.push(p);

    int count = 0;
    while(nodeQueue.empty() != true){
        binaryTreeNode<elemType> *temp = nodeQueue.front();
        nodeQueue.pop();
        if (temp -> llink == NULL && temp -> rlink == NULL){ // temp is a leaf
            count++;
        }
        if (temp -> llink != NULL){ // Node to the left of temp
            nodeQueue.push(temp -> llink);
        }
        if (temp -> rlink != NULL){
            nodeQueue.push(temp -> rlink);
        }
    }
    return count;
}

template <class elemType>
void binaryTreeType<elemType>::
    inorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        inorder(p->llink);
        cout << p->info << " ";
        inorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
    preorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        cout << p->info << " ";
        preorder(p->llink);
        preorder(p->rlink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::
    postorder(binaryTreeNode<elemType> *p) const
{
    if (p != NULL)
    {
        postorder(p->llink);
        postorder(p->rlink);
        cout << p->info << " ";
    }
}

template <class elemType>
int binaryTreeType<elemType>::
    height(binaryTreeNode<elemType> *p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}
template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(binaryTreeNode<elemType> *&copiedTreeRoot,
                                        binaryTreeNode<elemType> *otherTreeRoot)
{
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else
    {
        copiedTreeRoot = new binaryTreeNode<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
        copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
    }
} // end copyTree

template <class elemType>
void binaryTreeType<elemType>::destroy(binaryTreeNode<elemType> *&p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
    destroy(root);
}

// copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> &otherTree)
{
    if (otherTree.root == NULL) // otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

// destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
    destroy(root);
}

// overloading the assignment operator
template <class elemType>
const binaryTreeType<elemType> &binaryTreeType<elemType>::operator=(const binaryTreeType<elemType> &otherTree)
{
    if (this != &otherTree) // avoid self-copy
    {
        if (root != NULL) // if the binary tree is not empty,
            // destroy the binary tree
            destroy(root);
        if (otherTree.root == NULL) // otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    } // end else
    return *this;
}
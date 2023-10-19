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
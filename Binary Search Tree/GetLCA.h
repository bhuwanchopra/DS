#pragma once

#include "include/BinarySearchTree.h"
#include "FindBST.h"

template<class T>
TreeNode<T>* getLCA(BinarySearchTree<T>& tree, T val1, T val2) {
    if (!findNode(tree, val1) || !findNode(tree, val2)) {
        return nullptr;
    }
    
    TreeNode<T>* r = tree.getRoot();
    while ((val1 > r->getVal() && val2 > r->getVal()) ||
           (val1 < r->getVal() && val2 < r->getVal())) {
        if (val1 > r->getVal() && val2 > r->getVal()) {
            r = r->getRight();
        } else if (val1 < r->getVal() && val2 < r->getVal()) {
            r = r->getLeft();
        }
    }
    
    return r;
}

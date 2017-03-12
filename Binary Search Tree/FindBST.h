#pragma once

#include "include/BinarySearchTree.h"

template<class T>
bool findNode(BinarySearchTree<T>& tree, T val) {
    auto p = tree.getRoot();
    
    while (p) {
        if (val == p->getVal()) {
            return true;
        } else if (val > p->getVal()) {
            p = p->getRight();
        } else {
            p = p->getLeft();
        }
    }
    
    return false;
}
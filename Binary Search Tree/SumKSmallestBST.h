#pragma once

#include "include/BinarySearchTree.h"

#include <stack>

/*
Question: http://www.geeksforgeeks.org/sum-k-smallest-elements-bst/
I assume that the BST would have atleast K elements.
*/

int sumKSmallestBST(BinarySearchTree<int>& tree, int k) {
    int ret = 0;
    auto n = tree.getRoot();
    std::stack<TreeNode<int>*> S;
    while (n) {
        S.push(n);
        n = n->getLeft();
    }
    
    while (S.size() > 0 && k != 0) {
        n = S.top(); S.pop();
        --k; 
        ret += n->getVal();
        if (n->getRight()) {
            n = n->getRight();
            while (n) {
                S.push(n);
                n = n->getLeft();
            }
        }
    }
    return ret;
}
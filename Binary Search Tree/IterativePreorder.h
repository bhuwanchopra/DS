#pragma once

#include "include/BinarySearchTree.h"

#include <vector>
#include <stack>

template <class T>
void iterativePreorder(BinarySearchTree<T>& tree, std::vector<T>& retVector) {
    retVector.clear();
    auto n = tree.getRoot();
    if (n == nullptr) return;
    std::stack<TreeNode<T>*> S;
    S.push(n);
    while (S.size() > 0) {
        n = S.top();S.pop();
        retVector.push_back(n->getVal());
        if (n->getRight())
            S.push(n->getRight());
        if (n->getLeft())
            S.push(n->getLeft());
    }
}

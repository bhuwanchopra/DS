#pragma once

#include "include/BinarySearchTree.h"
#include "GetLCA.h"

#include <limits>

template<class T>
T getMaxInPath(TreeNode<T>* root, T val) {
    auto p = root;
    T retVal = std::numeric_limits<T>::min();
    while (p != nullptr) {
        retVal = std::max(retVal, p->getVal());
        if (val > p->getVal()) {
            p = p->getRight();
        } else {
            p = p->getLeft();
        }
    }
    return retVal;
}

template <class T>
T getMaxElementTwoNodes(BinarySearchTree<T>& tree, T val1, T val2) {
    auto lca = getLCA(tree, val1, val2);
    if (lca == nullptr) {
        throw "Error";
    }

    return std::max(getMaxInPath(lca, val1), getMaxInPath(lca, val2));
}

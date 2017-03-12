#include "include/BinarySearchTree.h"

#include <vector>
#include <stack>

template <class T>
void iterativeInorder(BinarySearchTree<T>& tree, std::vector<T>& retVector) {
    retVector.clear();
    
    auto n = tree.getRoot();
    
    std::stack<TreeNode<T>*> S;
    while (n != nullptr) {
        S.push(n);
        n = n->getLeft();
    }
    
    while (S.size() > 0) {
        auto t = S.top(); S.pop();
        retVector.push_back(t->getVal());
        if (t->getRight()) {
            t = t->getRight();
            while (t != nullptr) {
                S.push(t);
                t = t->getLeft();
            }
        }
    }
}
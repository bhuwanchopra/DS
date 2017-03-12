#include "include/BinarySearchTree.h"

#include <vector>
#include <stack>

template <class T>
void iterativePostorder(BinarySearchTree<T>& tree, std::vector<T>& retVector) {
    retVector.clear();
    auto n = tree.getRoot();
    if (n == nullptr) return;
    std::stack<TreeNode<T>*> S1;
    std::stack<TreeNode<T>*> S2;
    S1.push(n);
    while (S1.size() > 0) {
        n = S1.top();S1.pop();
        S2.push(n);
        if (n->getLeft())
            S1.push(n->getLeft());
        if (n->getRight())
            S1.push(n->getRight());
    }
    while (!S2.empty()) {
        retVector.push_back(S2.top()->getVal());
        S2.pop();
    }
}

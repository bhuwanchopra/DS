#include "include/BinarySearchTree.h"

#include <vector>
#include <stack>

/*
Expected Output

Test case::: 1
50, 17, 12, 9, 14, 23, 19, 72, 54, 67, 76, 
Test case::: 2
2, 1, 32, 12, 24, 21, 54, 

*/

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

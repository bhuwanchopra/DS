#include "include/BinarySearchTree.h"
#include <vector>
#include <iostream>

using namespace std;

/*
Expected Output

Test case::: 1
1, 2, 3, 4, 5, 6, 7, 8, 
Test case::: 2
1, 
Test case::: 3

*/

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({2,1,3,4,6,8,5,7});

        for (auto i: V) tree.addNode(i);

        tree.inorder(tree.getRoot());
    }

    cout<<"\nTest case::: 2\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({1});

        for (auto i: V) tree.addNode(i);

        tree.inorder(tree.getRoot());
    }

    cout<<"\nTest case::: 3\n";
    {
        BinarySearchTree<int> tree;
        tree.inorder(tree.getRoot());
    }

    cout<<"\n";
    return 0;
}

#include "FindBST.h"

#include <vector>
#include <iostream>

using namespace std;

/*
Expected Output

Test case::: 1
0
0
1
1
1
Test case::: 2
0

*/

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67});

        for (auto i: V) tree.addNode(i);

        cout<<find(tree, 0)<<endl;
        cout<<find(tree, 100)<<endl;
        cout<<find(tree, 50)<<endl;
        cout<<find(tree, 23)<<endl;
        cout<<find(tree, 67)<<endl;
    }
    
    cout<<"Test case::: 2\n";
    {
        BinarySearchTree<int> tree;
        cout<<find(tree, 0)<<endl;
    }

    return 0;
}
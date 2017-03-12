#include "GetLCA.h"

#include <vector>
#include <iostream>

using namespace std;

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67});

        for (auto i: V) tree.addNode(i);

        cout<<getLCA(tree, 14, 19)->getVal()<<endl;

        cout<<getLCA(tree, 9, 14)->getVal()<<endl;
        
        cout<<getLCA(tree, 67, 14)->getVal()<<endl;
        
        cout<<getLCA(tree, 67, 67)->getVal()<<endl;
        
        cout<<getLCA(tree, 1, 2)<<endl;
    }
    
    cout<<"Test case::: 2\n";
    {
        BinarySearchTree<int> tree;

        cout<<getLCA(tree, 1, 2)<<endl;
    }
    return 0;
}
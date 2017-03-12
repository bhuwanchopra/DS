#include "GetMaxElementTwoNodes.h"
#include <vector>

using namespace std;

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67});

        for (auto i: V) tree.addNode(i);
        
        cout<<getMaxElementTwoNodes(tree, 14, 19)<<endl;
        
        cout<<getMaxElementTwoNodes(tree, 14, 67)<<endl;
    }
    
    cout<<"Test case::: 2\n";
    {
        BinarySearchTree<int> tree;
        try {
            getMaxElementTwoNodes(tree, 1, 2);
            cout<<"Test Failed\n";
        } catch (...) {
            cout<<"Test Passed\n";
        }
    }
    return 0;
}
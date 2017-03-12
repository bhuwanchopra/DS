#include "SumKSmallestBST.h"

#include <vector>

using namespace std;

/*
Expected output

Test case::: 1
22
34
48
Test case::: 2
17
26
36

*/

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({20, 8, 4, 12, 10, 14, 22});
        for (auto i: V) tree.addNode(i);
        cout << sumKSmallestBST(tree, 3) << endl;
        cout << sumKSmallestBST(tree, 4) << endl;
        cout << sumKSmallestBST(tree, 5) << endl;
    }
    
    cout<<"Test case::: 2\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({8, 7, 10, 2, 9, 13});
        for (auto i: V) tree.addNode(i);
        cout << sumKSmallestBST(tree, 3) << endl;
        cout << sumKSmallestBST(tree, 4) << endl;
        cout << sumKSmallestBST(tree, 5) << endl;
    }
}
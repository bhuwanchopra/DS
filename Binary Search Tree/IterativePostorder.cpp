#include "IterativePostorder.h"
#include <vector>

using namespace std;

/*
Expected Output

Test case::: 1
9, 14, 12, 19, 23, 17, 67, 54, 76, 72, 50, 
Test case::: 2
1, 21, 24, 12, 54, 32, 2, 

*/

int main() {
    cout<<"Test case::: 1\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({50, 17, 72, 12, 23, 54, 76, 9, 14, 19, 67});
        vector<int> order;

        for (auto i: V) tree.addNode(i);
        
        iterativePostorder(tree, order);
        for (auto i: order) cout << i << ", ";
        cout << endl;
    }
    
    cout<<"Test case::: 2\n";
    {
        BinarySearchTree<int> tree;
        vector<int> V({2,1,32,54,12,24,21});
        vector<int> order;

        for (auto i: V) tree.addNode(i);
        
        iterativePostorder(tree, order);
        for (auto i: order) cout << i << ", ";
        cout << endl;
    }
    return 0;
}
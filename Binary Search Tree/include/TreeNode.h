
template<class T>
class TreeNode {
public:
    TreeNode(T v) :
        val(v),
        left(nullptr),
        right(nullptr) {}

    T getVal() {
        return val;
    }

    TreeNode* getLeft() { 
        return left;
    }

    TreeNode* getRight() { 
        return right;
    }
    
    void setLeft(TreeNode* p) {
        left = p;
    }
    
    void setRight(TreeNode* p) {
        right = p;
    }

private:
    T val;
    TreeNode* left;
    TreeNode* right;
};

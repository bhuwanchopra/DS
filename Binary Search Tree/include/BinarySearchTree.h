#pragma once

#include <memory>
#include <iostream>

#include <TreeNode.h>

template<class T>
class BinarySearchTree {
public:
    BinarySearchTree() :
        root(nullptr) {}

    ~BinarySearchTree() {
        clean(root);
    }
    
    void clean(TreeNode<T>* root) {
        if (root == nullptr) {
            return;
        }
        clean(root->getLeft());
        clean(root->getRight());
        delete root;
    }

    void addNode(const T& val) {
        if (root == nullptr) {
            root = new TreeNode<T>(val);
            return;
        }
        TreeNode<T>* pp = nullptr;
        TreeNode<T>* p = root;
        while (p) {
            pp = p;
            if (p->getVal() > val) {
                p = p->getLeft();
            } else {
                p = p->getRight();
            }
        }
        p = new TreeNode<T>(val);
        if (val > pp->getVal()) {
            pp->setRight(p);
        } else {
            pp->setLeft(p);
        }
    }
    
    void inorder(TreeNode<T>* root) const {
        if (root == nullptr) return;
        inorder(root->getLeft());
        std::cout<<root->getVal()<<", ";
        inorder(root->getRight());
    }
    
    TreeNode<T>* getRoot() {
        return root;
    }
    
private:
    TreeNode<T>* root;
};

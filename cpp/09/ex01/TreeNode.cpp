#include "TreeNode.hpp"

TreeNode::TreeNode(char data) {
    this->left = 0;
    this->right = 0;
    this->data = data;
}
TreeNode::~TreeNode() {
    delete this->left;
    delete this->right;
}

TreeNode::TreeNode(TreeNode& t) {
    if (t.left != 0)
        left = new TreeNode(*t.left);
    else
        left = 0;
    if (t.right != 0)
        right = new TreeNode(*t.right);
    else
        right = 0;
    data = t.data;
}
TreeNode& TreeNode::operator=(TreeNode t) {
    if (this != &t) {
        this->left = new TreeNode(*t.left);
        this->right = new TreeNode(*t.right);
        this->data = t.data;
    }
    return *this;
}
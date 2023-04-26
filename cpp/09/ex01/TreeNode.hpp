#ifndef TREE_NODE_H
#define TREE_NODE_H
class TreeNode {
   public:
    TreeNode* left;
    TreeNode* right;
    char data;
    TreeNode(char data);
    TreeNode(TreeNode& t);
    ~TreeNode();
    TreeNode& operator=(TreeNode t);
};

#endif /* TREE_NODE_H */

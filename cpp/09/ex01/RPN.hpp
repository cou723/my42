#ifndef RPN_H
#define RPN_H
#include <exception>
#include <stack>
#include <stdexcept>
#include <string>

#include "TreeNode.hpp"
class RPN {
   private:
    TreeNode* _formula_tree;
    TreeNode* parse(std::string formula) throw(std::runtime_error);
    TreeNode* popNode(std::stack<TreeNode*>& stack) throw(std::runtime_error);

   public:
    RPN(std::string formula);
    RPN(TreeNode* tn);
    RPN(RPN& rpn);
    int calc();
    ~RPN();
    RPN& operator=(RPN& rpn);
};

#endif /* RPN_H */

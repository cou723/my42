#include "RPN.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

#include "TreeNode.hpp"

RPN::RPN(std::string formula) : _formula_tree(parse(formula)){};
RPN::RPN(TreeNode* tn) : _formula_tree(tn){};
RPN::RPN(RPN& rpn) : _formula_tree(rpn._formula_tree){};

// void printTreeNodes(std::stack<TreeNode*>& s) {
//     while (!s.empty()) {
//         TreeNode* node = s.top();
//         s.pop();
//         std::cout << node->data << " ";
//         if (node->right != 0) {
//             s.push(node->right);
//         }
//         if (node->left != 0) {
//             s.push(node->left);
//         }
//     }
//     std::cout << std::endl;
// }

TreeNode* RPN::parse(std::string formula) throw(std::runtime_error) {
    std::stack<TreeNode*> stack;
    for (std::basic_string<char>::size_type i = 0; i < formula.length(); i++) {
        const char c = formula[i];
        // std::cout << "'" << c << "'" << std::endl;
        if (c >= '0' && c <= '9') {
            stack.push(new TreeNode(c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            TreeNode* new_node = new TreeNode(c);
            new_node->right = popNode(stack);
            new_node->left = popNode(stack);
            stack.push(new_node);
        } else if (c == ' ')
            continue;
        else
            throw std::runtime_error("invalid character");
    }
    if (stack.size() != 1) throw std::runtime_error("invalid formula");

    return stack.top();
}

TreeNode* RPN::popNode(std::stack<TreeNode*>& stack) throw(std::runtime_error) {
    TreeNode* popped_node;
    if (stack.empty()) throw std::runtime_error("invalid formula");
    popped_node = stack.top();
    stack.pop();
    return popped_node;
}

int RPN::calc() {
    int total = 0;
    if (_formula_tree->left == NULL || _formula_tree->right == NULL) {
        return _formula_tree->data - '0';
    } else {
        RPN* left = (new RPN(new TreeNode(*_formula_tree->left)));
        RPN* right = (new RPN(new TreeNode(*_formula_tree->right)));
        if (_formula_tree->data == '+') {
            total = left->calc() + right->calc();
        } else if (_formula_tree->data == '-') {
            total = left->calc() - right->calc();
        } else if (_formula_tree->data == '*') {
            total = left->calc() * right->calc();
        } else if (_formula_tree->data == '/') {
            if (right->calc() == 0)
                throw std::runtime_error("division by zero");
            total = left->calc() / right->calc();
        }
        delete left;
        delete right;
    }
    return (long)total;
}

RPN::~RPN() { delete _formula_tree; }

RPN& RPN::operator=(RPN& rpn) {
    if (this != &rpn) {
        this->_formula_tree = rpn._formula_tree;
    }
    return *this;
}
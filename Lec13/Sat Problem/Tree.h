#ifndef TREE_H
#define TREE_H

#include <stack>

class  SatTree;

class Expression
{
    friend class SatTree;
    public:
        void setExpression();
        void setPreorder();
        bool isVariable(char a);

    private:
        char expression[0x100];
        std::stack<char> s_output;
};

class SatNode
{
    friend class SatTree;
    private:
        char data;
        bool value;
        SatNode *LeftChild;
        SatNode *RightChild;
};

class SatTree
{
    public:
        SatTree();
        ~SatTree();

        void levelorder();
        void setExpressionTree(Expression& Exp_obj, SatTree& tree_obj);
        void PostOrderEval();
        void PostOrderEval(SatNode *s);
        void Clear();

    private:
        SatNode *root;
};

#endif // TREE_H

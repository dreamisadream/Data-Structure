#ifndef TREE_H
#define TREE_H


class TreeNode{
    friend class Tree;
    private:
        char data;
        TreeNode *LeftChild;
        TreeNode *RightChild;
};

class Tree
{
    public:
        Tree();
        ~Tree();

        void InsertNode();
        void DeleteNode();
        void preorder();
        void preorder(TreeNode *CurrentNode);
        void inorder();
        void inorder(TreeNode *CurrentNode);
        void postorder();
        void postorder(TreeNode *CurrentNode);
        void NonrecPreorder();
        void NonrecInorder();
        void NonrecPostorder();
        void levelorder();


    private:
        TreeNode *root;
};

#endif // TREE_H

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
        Tree(const Tree&s){root=COPY(s.root)};
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
    
        TreeNode* COPY(TreeNode *orignode);
        
        int operator==(const Tree& s, const Tree& t){
            return Equal(s.root, t.root);
        }

    private:
        TreeNode *root;
};

#endif // TREE_H

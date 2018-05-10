#include "Tree.h"

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

Tree::Tree()
{
    root = NULL;
}

Tree::~Tree()
{
    queue<TreeNode*> q_node;
    TreeNode *CurrentNode = root;

    while(CurrentNode){
        if(CurrentNode->LeftChild)
            q_node.push(CurrentNode->LeftChild);
        if(CurrentNode->RightChild)
            q_node.push(CurrentNode->RightChild);
        CurrentNode = q_node.front();
        q_node.pop();
        delete CurrentNode;
    }
}

void Tree::InsertNode()
{
    char data;
    cout << "value: ";
    cin >> data;

    TreeNode *new_node = new TreeNode;
    new_node->data = data;
    new_node->LeftChild = NULL;
    new_node->RightChild = NULL;

    if(!root){
        root = new_node;
        return;
    };

    TreeNode *CurrentNode = root;
    TreeNode *parent;
    while(CurrentNode){
        parent = CurrentNode;
        if(data > CurrentNode->data)
            CurrentNode = CurrentNode->RightChild;
        else if(data < CurrentNode->data)
            CurrentNode = CurrentNode->LeftChild;
        else{
            cout << "It's already in the tree.\n";
            return;
        }
    }

    if(data > parent->data)
        parent->RightChild = new_node;
    else
        parent->LeftChild = new_node;
}


void Tree::DeleteNode()
{
    char data;
    cout << "value: ";
    cin >> data;

    TreeNode *CurrentNode = root;
    TreeNode *parent = root;
    while(CurrentNode){
        if(data > CurrentNode->data){
            parent = CurrentNode;
            CurrentNode = CurrentNode->RightChild;
        }
        else if(data < CurrentNode->data){
            parent = CurrentNode;
            CurrentNode = CurrentNode->LeftChild;
        }
        else {
            if(CurrentNode == root){
                if(CurrentNode->LeftChild){
                    CurrentNode = CurrentNode->LeftChild;

                    while(CurrentNode->RightChild){
                        parent = CurrentNode;
                        CurrentNode = CurrentNode->RightChild;
                    }

                    if(parent == root)
                        parent->LeftChild = NULL;
                    else
                        parent->RightChild = NULL;
                }
                else if(CurrentNode->RightChild){
                    CurrentNode = CurrentNode->RightChild;

                    while(CurrentNode->LeftChild){
                        parent = CurrentNode;
                        CurrentNode = CurrentNode->LeftChild;
                    }

                    if(parent == root)
                        parent->RightChild = NULL;
                    else
                        parent->LeftChild = NULL;
                }
                else{
                    root = NULL;
                    return;
                }

                CurrentNode->LeftChild = root->LeftChild;
                CurrentNode->RightChild = root->RightChild;
                delete root;
                root = CurrentNode;
                cout << "done\n";
                return;
            }

            if(CurrentNode->LeftChild && CurrentNode->RightChild){
                if(CurrentNode->data > parent->data)
                    parent->RightChild = CurrentNode->LeftChild;
                else
                    parent->LeftChild = CurrentNode->LeftChild;

                CurrentNode->RightChild = CurrentNode->LeftChild->RightChild;
            }
            else if(CurrentNode->LeftChild){
                if(CurrentNode->data > parent->data)
                    parent->RightChild = CurrentNode->LeftChild;
                else
                    parent->LeftChild = CurrentNode->LeftChild;
            }
            else if(CurrentNode->RightChild){
                if(CurrentNode->data > parent->data)
                    parent->RightChild = CurrentNode->RightChild;
                else
                    parent->LeftChild = CurrentNode->RightChild;
            }
            else{
                if(CurrentNode->data > parent->data)
                    parent->RightChild = NULL;
                else
                    parent->LeftChild = NULL;
            }

            delete CurrentNode;
            cout << "Done!" << endl;
            return;
        }
    }

    cout << "This value is not in the tree!\n";
}


void Tree::preorder()
{
    cout << "recursive" << endl;
    preorder(root);
    cout << endl;
    cout << "Non-recursive" << endl;
    NonrecPreorder();
    cout << endl;
}


void Tree::preorder(TreeNode *CurrentNode){
    if(CurrentNode){
        cout << CurrentNode->data << " ";
        preorder(CurrentNode->LeftChild);
        preorder(CurrentNode->RightChild);
    }
}

void Tree::inorder()
{
    cout << "recursive" << endl;
    inorder(root);
    cout << endl;
    cout << "Non-recursive" << endl;
    NonrecInorder();
    cout << endl;

}


void Tree::inorder(TreeNode *CurrentNode){
    if(CurrentNode){
        inorder(CurrentNode->LeftChild);
        cout << CurrentNode->data << " ";
        inorder(CurrentNode->RightChild);
    }
}

void Tree::postorder()
{
    cout << "recursive" << endl;
    postorder(root);
    cout << endl;
    cout << "Non-recursive" << endl;
    NonrecPostorder();
    cout << endl;
}


void Tree::postorder(TreeNode *CurrentNode){
    if(CurrentNode){
        postorder(CurrentNode->LeftChild);
        postorder(CurrentNode->RightChild);
        cout << CurrentNode->data << " ";
    }
}


void Tree::NonrecPreorder()
{
    TreeNode *CurrentNode = root;
    stack<TreeNode *> s_node;
    while(1){
        while(CurrentNode){
            cout << CurrentNode->data << " ";
            s_node.push(CurrentNode);
            CurrentNode = CurrentNode->LeftChild;
        }

        if(!s_node.empty()){
            CurrentNode = s_node.top();
            s_node.pop();
            CurrentNode = CurrentNode->RightChild;
        }else break;
    }
}


void Tree::NonrecInorder()
{
    TreeNode *CurrentNode = root;
    stack<TreeNode *> s_node;
    while(1){
        while(CurrentNode){
            s_node.push(CurrentNode);
            CurrentNode = CurrentNode->LeftChild;
        }

        if(!s_node.empty()){
            CurrentNode = s_node.top();
            s_node.pop();
            cout << CurrentNode->data << " ";
            CurrentNode = CurrentNode->RightChild;
        }else break;
    }
}


void Tree::NonrecPostorder()
{
    if(!root)
        return;

    TreeNode *CurrentNode = root;
    stack<TreeNode *> s_node;
    do{
        while(CurrentNode){
            if(CurrentNode->RightChild)
                s_node.push(CurrentNode->RightChild);

            s_node.push(CurrentNode);
            CurrentNode = CurrentNode->LeftChild;
        }

        CurrentNode = s_node.top();
        s_node.pop();

        if(!s_node.empty() && CurrentNode->RightChild && s_node.top() == CurrentNode->RightChild){
            s_node.pop();
            s_node.push(CurrentNode);
            CurrentNode = CurrentNode->RightChild;
        }
        else  {
            cout << CurrentNode->data << " ";
            CurrentNode = NULL;
        }
    }while(!s_node.empty());
}

void Tree::levelorder()
{
    if(!root)
        return;

    queue <TreeNode *> q_node;
    TreeNode *CurrentNode = root;
    while(CurrentNode){
        cout << CurrentNode->data << " ";
        if(CurrentNode->LeftChild)
            q_node.push(CurrentNode->LeftChild);
        if(CurrentNode->RightChild)
            q_node.push(CurrentNode->RightChild);
        CurrentNode = q_node.front();
        q_node.pop();
    }

    cout << endl;
}

TreeNode* Tree::COPY(TreeNode* orignode)
{
    if(orignode){
        TreeNode *temp = new TreeNode;
        temp->data = orignode->data;
        temp->LeftChild = COPY(orignode->LeftChild);
        temp->RightChild = COPY(orignode->RightChild);
        return temp;
    }
    else return 0;
}

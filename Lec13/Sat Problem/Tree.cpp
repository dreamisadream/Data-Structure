#include "Tree.h"

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

SatTree::SatTree()
{
    root = NULL;
}

SatTree::~SatTree()
{
    queue<SatNode*> q_node;
    SatNode *CurrentNode = root;

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

void SatTree::Clear()
{
    queue<SatNode*> q_node;
    SatNode *CurrentNode = root;

    while(CurrentNode){
        if(CurrentNode->LeftChild)
            q_node.push(CurrentNode->LeftChild);
        if(CurrentNode->RightChild)
            q_node.push(CurrentNode->RightChild);
        CurrentNode = q_node.front();
        q_node.pop();
        delete CurrentNode;
    }
    root = NULL;
}

void SatTree::levelorder()
{
    if(!root)
        return;

    queue <SatNode *> q_node;
    SatNode *CurrentNode = root;
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


void Expression::setExpression()
{
   cout << "Expression:";
   cin >> expression;
   setPreorder();
}

bool Expression::isVariable(char a)
{
    if(a == 'v' || a == '^' || a == '(' || a == ')')
        return false;
    return true;
}

void Expression::setPreorder()
{
     stack<char> s_operator;
     for(int i = 0; expression[i]; i++){
          if(isVariable(expression[i]))
                s_output.push(expression[i]);
          else
                switch(expression[i]){
                    case 'v':
                    case '^':
                        while(!s_operator.empty() && s_operator.top() != '('){
                            s_output.push(s_operator.top());
                            s_operator.pop();
                        }
                        s_operator.push(expression[i]);
                        break;

                    case '(':
                        s_operator.push(expression[i]);
                        break;

                    case ')':
                        while(s_operator.top() != '('){
                            s_output.push(s_operator.top());
                            s_operator.pop();
                        }
                        s_operator.pop();
                        break;
                }
        }
        while(!s_operator.empty()){
            s_output.push(s_operator.top());
            s_operator.pop();
        }
}

void SatTree::setExpressionTree(Expression& Exp_obj, SatTree& Tree_obj)
{

    if(Exp_obj.s_output.empty())
        return;
    /*while(!Exp_obj.s_output.empty()){
        cout << Exp_obj.s_output.top() << " ";
        Exp_obj.s_output.pop();
    }
    cout << endl;*/

    stack<SatNode *> s_parent;
    SatNode *CurrentNode;

    bool NOT;
    while(!Exp_obj.s_output.empty()){
        SatNode *new_node = new SatNode;
        new_node->data = Exp_obj.s_output.top();
        Exp_obj.s_output.pop();
        new_node->LeftChild = NULL;
        new_node->RightChild = NULL;

        if(!Tree_obj.root){
            Tree_obj.root = new_node;
            CurrentNode = Tree_obj.root;
            continue;
        }

        if(!Exp_obj.s_output.empty() && Exp_obj.s_output.top() == '~'){
            NOT = true;
            Exp_obj.s_output.pop();
        }
        else
            NOT = false;

        if( !Exp_obj.isVariable(CurrentNode->data) ){
            if(!CurrentNode->LeftChild){
                s_parent.push(CurrentNode);

                if(NOT){
                    SatNode *NOT_node = new SatNode;
                    NOT_node->data = '~';
                    NOT_node->RightChild = new_node;
                    NOT_node->LeftChild = NULL;
                    CurrentNode->RightChild = NOT_node;
                    CurrentNode = NOT_node;
                }
                else{
                    CurrentNode->RightChild = new_node;
                    CurrentNode = new_node;
                }
            }
            else cout << "exception occured!\n";
        }
        else{
            CurrentNode = s_parent.top();
            s_parent.pop();

            if(NOT){
                SatNode *NOT_node = new SatNode;
                NOT_node->data = '~';
                NOT_node->RightChild = new_node;
                NOT_node->LeftChild = NULL;
                CurrentNode->LeftChild = NOT_node;
                CurrentNode = NOT_node;
            }
            else{
                CurrentNode->LeftChild = new_node;
                s_parent.push(CurrentNode);
                CurrentNode = new_node;
            }
        }
    }
}

void SatTree::PostOrderEval()
{
    PostOrderEval(root);
    cout << root->value << endl;
}

void SatTree::PostOrderEval(SatNode *node)
{
    if(node){
        PostOrderEval(node->LeftChild);
        PostOrderEval(node->RightChild);
        switch(node->data){
            case '~':
                node->value = !node->RightChild->value;
                break;
            case '^':
                node->value = node->LeftChild->value && node->RightChild->value;
                break;
            case 'v':
                node->value = node->LeftChild->value || node->RightChild->value;
                break;
            case '1':
                node->value = true;
                break;
            case '0':
                node->value = false;
                break;
        }
    }
}

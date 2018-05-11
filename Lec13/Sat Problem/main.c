#include <Tree.h>

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    Expression Exp1;
    SatTree binaryExpressionTree;

    while(1){
        Exp1.setExpression();
        binaryExpressionTree.setExpressionTree(Exp1, binaryExpressionTree);
        binaryExpressionTree.levelorder();
        binaryExpressionTree.PostOrderEval();
        binaryExpressionTree.Clear();
    }

    return 0;
}

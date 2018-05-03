#include <iostream>
#include <fstream>

using namespace std;

void equivalence();

enum Boolean{FALSE, TRUE};
class ListNode{
    friend void equivalence();
    private:
        int data;
        ListNode*link;
        ListNode(int);
};

typedef ListNode* ListNodePtr;
ListNode::ListNode(int d){
    data = d;
    link = 0;
}

void equivalence()
{
    ifstream inFile("equiv.in", ios::in);
    if(!inFile){
        cerr << "Cannot open input file" << endl;
        return;
    }
    int i, j, n;
    inFile >> n;

    ListNodePtr *seq = new ListNodePtr[n];
    Boolean *out = new Boolean[n];



    for(i = 0; i<n; i++){
        seq[i] = 0;
        out[i] = FALSE;
    }

    inFile >> i >> j;
    while(inFile.good()){
      ListNode *x = new ListNode(j);
      x->link = seq[i];
      seq[i] = x;
      ListNode *y = new ListNode(i);
      y->link = seq[j];
      seq[j] = y;
      inFile >> i >> j;
    }


    for(i = 0; i<n; i++)
        if(out[i] == FALSE){
            cout << endl << "A new class: " << i;
            out[i] = TRUE;
            ListNode *x = seq[i];
            ListNode *top = 0;
            while(1){
                while(x){
                    j = x->data;
                    if(out[j] == FALSE){
                        cout << "," << j;
                        out[j] = TRUE;
                        ListNode *y = x->link;
                        x->link = top;
                        top = x;
                        x = y;
                    }
                    else x = x->link;
                }
                if(!top) break;
                else{
                    x = seq[top->data];
                    top = top->link;
                }
            }
        }

    for(i = 0; i<n; i++)
        while(seq[i]){
            ListNode *delnode = seq[i];
            seq[i] = delnode->link;
            delete delnode;
        }

    delete[] seq;
    delete[] out;
}

int main()
{
    equivalence();
    return 0;
}

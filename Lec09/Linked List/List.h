#ifndef LIST_H
#define LIST_H

#include <iostream>

/* False = 0, TRUE = 1 */
enum Boolean {FALSE, TRUE};

/* prototype */
template <class Type> class List;
template <class Type> class ListIterator;

template <class Type> class ListNode{
    friend class List<Type>;
    friend class ListIterator<Type>;

    ListNode(int element){data=element; link = 0;}
    private:
        Type data;
        ListNode *link;
};


template <class Type> class List{
    friend class ListIterator<Type>;
    public:
        List(){first = 0;}
        ~List();
        void Attach(Type k);
        void Invert();
        void Concatenate(List<Type> b);
        void showList();

    private:
        ListNode<Type> *first, *last;
};


template <class Type>
void List<Type>::Attach(Type k)
{
    ListNode<Type> *newnode = new ListNode<Type>(k);
    if(first == 0) first = last = newnode;
    else{
        last->link = newnode;
        last = newnode;
    }
}

template <class Type>
void List<Type>::Invert()
{
    ListNode<Type> *p = first, *q = 0, *r;
    while(p){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    first = q;
}

template <class Type>
void List<Type>::Concatenate(List<Type> b)
{
    if(!first){ first = b.first; return;}
    if(b.first){
        ListNode<Type> *p;
        for(p = first; p->link; p=p->link);
        p->link = b.first;
    }
}

template<class Type>
void List<Type>::showList()
{
    ListNode<Type> *p = first;
    while(p){
        std::cout << p->data << " ";
        p = p->link;
    }
    std::cout << std::endl;
}

template<class Type>
List<Type>::~List()
{
    ListNode<Type> *next;
    for(; first; first=next){
        next = first->link;
        delete first;
    }
}



template <class Type> class ListIterator{
    public:
        ListIterator(const List<Type> &l): list(l), current(l.first){}
        Boolean NotNull();
        Boolean NextNotNull();
        Type *First();
        Type *Next();

    private:
        const List<Type> &list;
        ListNode<Type> *current;
};


#endif // LIST_H

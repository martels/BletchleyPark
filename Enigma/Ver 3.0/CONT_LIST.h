#ifndef CONT_LIST_H
#define CONT_LIST_H

using namespace std;

struct node
{
    int index;
    int link;
    node* next;
    node* prev;
};

class Cont_List
{
    private:
    node *zero;
    node *initial;
    node *pointer;
    node *position;
    int NumNode;
    

    public:
    Cont_List(); 
    void addNode(int ind, int lin);
    void addNode(node *temp);
    void iterate();
    void click();
    void setInitial(int start);
    void returnPointer();
    int getIndex();
    int getLink();
    int getNumNode();

};

Cont_List::Cont_List()
{
    initial = NULL;
    pointer = NULL;
    position = NULL;
    zero = NULL;    
    NumNode = 0;
}

void Cont_List::addNode(int ind, int lin)
{
    node *temp = new node;
    temp->index = ind;
    temp->link = lin;
    
    if(NumNode == 0)
    {
        zero = temp;
        zero->next = zero;
        zero->prev = zero;
        pointer = zero;
        position = zero;
        initial = zero;
    }
    
    else if(NumNode == 1)
    {
        temp->next = zero;
        temp->prev = zero;
        zero->prev = temp;
        zero->next = temp;
    }

    else
    {
        pointer = zero->prev;
        pointer->next = temp;
        temp->prev = pointer;
        temp->next = zero;
        zero->prev = temp;
    }
    
    NumNode++;

    return;
}

void Cont_List::addNode(node *temp)
{
        if(NumNode == 0)
    {
        zero = temp;
        zero->next = zero;
        zero->prev = zero;
        pointer = zero;
        position = zero;
        initial = zero;
    }
    
    else if(NumNode == 1)
    {
        temp->next = zero;
        temp->prev = zero;
        zero->prev = temp;
        zero->next = temp;
    }

    else
    {
        pointer = zero->prev;
        pointer->next = temp;
        temp->prev = pointer;
        temp->next = zero;
        zero->prev = temp;
    }

    NumNode++;

    return;
}

void Cont_List::iterate()
{
    pointer = pointer->next;
}

void Cont_List::click()
{
    position = position->next;
}

void Cont_List::returnPointer()
{
    pointer = position;
}

void Cont_List::setInitial(int start)
{
    initial = zero;
    while(initial->index != start)
    {
        initial = initial->next;
    }
    pointer = initial;
    position = initial;
}

int Cont_List::getIndex()
{
    int temp;
    temp = pointer->index;
    return temp;
}

int Cont_List::getLink()
{
    int temp;
    temp = pointer->link;
    return temp;
}

int Cont_List::getNumNode()
{
    return NumNode;
}

#endif
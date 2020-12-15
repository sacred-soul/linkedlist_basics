#include<iostream>
using namespace std;

//Structure for Node of Linkedlist
typedef struct node
{
    int data;
    struct node *next;
}node_t;

node_t *head=NULL;

//Function for inserting a node to end of list
void insert(int n)
{
    node_t *p=new node_t;
    p->data=n;
    p->next=NULL;
    if(head==NULL)
        head=p;
    else
    {
        node_t *t=head;
        while(t->next!=NULL)
            t=t->next;
        t->next=p;
    }
}

int length()
{
    if (head==NULL)
        return 0;
    node_t *t=head;
    int count=0;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}
void arr_linkedlist(int arr[], int n)
{
    for(int i=0;i<n;i++)
        insert(arr[i]);
}

void insertpos(int n, int pos)
{
    int count=length();
    if(pos>count)
    {
        cout<<"Invalid Posistion\n";
        return;
    }
    node_t *t=head;
    node_t *p=new node_t;
    p->data=n;
    int i=0;
    if(pos==0)
    {
        head=p;
        head->next=t;
    }
    else
    {
        while(i<pos-1)
        {
            t=t->next;
            i++;
        }
        p->next=t->next;
        t->next=p;
    }
}
int iscircular()
{
    node_t *t1=head->next;
    while(t1!=NULL && t1!=head)
        t1=t1->next;
    if(t1==head)
    {   cout<<"\nCircular\n";
        return 1;
    }
    else
    {
        cout<<"\nNot Circular\n";
        return 0;
    }
}
void makecircular()
{
    node_t *t=head;
    while(t->next!=NULL)
        t=t->next;
    t->next=head;
}

void removenode(int pos)
{
    int count=length();
    if(pos>count)
    {
        cout<<"Invalid Posistion\n";
        return;
    }
    node_t *t=head;
    if(pos==0)
    {
        head=t->next;
        delete(t);
    }
    else
    {
        int i=0;
        node_t *p=NULL;
        while(i<pos)
        {
            p=t;
            t=t->next;
            i++;
        }

        p->next=t->next;
        delete(t);
    }
}
void disp()
{
    node_t *t;
    t=head;
    if(t==NULL)
        cout<<"Empty list\n";
    cout<<t->data<<" ";
    t=t->next;
    while(t!=NULL && t!=head)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}
void reverse()
{
    node_t *t=head;
    node_t *prevnode=NULL;
    node_t *nextnode=NULL;
    while(t!=NULL)
    {
        head=t;
        nextnode=t->next;
        t->next=prevnode;
        prevnode=t;
        t=nextnode;
    }
}
void freemem()
{
    node_t *t1=head->next,*t=head;
    while(t1!=NULL && t1!=head)
    {   
        t=t1;
        t1=t1->next;
        delete(t);
    }
    delete(head);
}
int main()
{
    int arr[]={1,0,2,4};
    arr_linkedlist(arr,4);
    insertpos(3,3);
    removenode(1);
    insert(5);
    insert(6);
    reverse();
    makecircular();
    iscircular();
    disp();
    freemem();
    return 0;
    
}

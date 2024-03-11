#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printLinkedList(Node* head)
{
    if(head==NULL)return ;
    if(head->next==NULL)
    {
        cout<<head->data;
        return ;
    }
    cout<<head->data<<"->";
    printLinkedList(head->next);

}
Node* create_linked_list();
void insertIntoSinglyLL(Node* head,int el,int pos)
{
    Node* temp=new Node(el);
    if(pos==1)
    {
        temp->next=head->next;
        head->next=temp;
        swap(temp->data,head->data);
    }
    Node* curr=head;
    int pointer=1;
    while(curr!=NULL)
    {
        if(pointer==(pos-1))
        {
            temp->next=curr->next;
            curr->next=temp;
            return;
        }
        curr=curr->next;
        pointer++;
    }
}

int main()
{
    int t;
    cout<<"Enter the no of test cases:";
    cin>>t;
    while(t--)
    {
        Node *head=create_linked_list();
        int el,pos;
        cout<<"enter the el want to insert and the pos of el in singly linked list:";
        cin>>el;
        cin>>pos;
        insertIntoSinglyLL(head,el,pos);
        printLinkedList(head);
        cout<<"\n";
    }
    return 0;
}

Node* create_linked_list()
{
    int n;
    cout<<"Enter the el in Linked list:";
    cin>>n;
    if(n==0)return NULL;
    int head_el;
    cout<<"Enter the el at the head:";
    cin>>head_el;
    Node *head=new Node(head_el);
    Node *curr=head;
    n=n-1;
    while(n--)
    {
        int el;
        cin>>el;
        curr->next=new Node(el);
        curr=curr->next;

    }
    return head;

}

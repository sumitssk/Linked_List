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

int printNthNode(Node* head,int n)
{
    int temp=n;
    if(head==NULL)return -1;
    Node* second=head;
    Node* first=head;
    while(first!=NULL && temp--)
    {
        first=first->next;

    }
    if(first==NULL && temp!=0)return -1;
    while(first!=NULL)
    {
        second=second->next;
        first=first->next;

    }
    return second->data;

    
}

int main()
{
    int t;
    cout<<"Enter the no of test cases:";
    cin>>t;
    while(t--)
    {
        Node *head=create_linked_list();
        printLinkedList(head);
        cout<<"\n";
        cout<<"Enter the nth node u want to print:";
        int n;
        cin>>n;
        cout<<printNthNode(head,n);
        
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

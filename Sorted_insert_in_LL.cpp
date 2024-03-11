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

Node* insertIntoList(Node* head,int el)
{
    Node* temp=new Node(el);
    if(head==NULL)return temp;
    Node* curr=head;
    while(curr->next!=NULL)
    {
        if(el>=curr->data)curr=curr->next;
        if(curr->data>el)
        {
            Node* temp=new Node(el);
            temp->next=curr->next;
            curr->next=temp;
            swap(curr->data,temp->data);
            return head;
        }

    }
    temp=new Node(el);
    curr->next=temp;
    return head;
}

int main()
{
    int t;
    cout<<"Enter the no of test cases:";
    cin>>t;
    while(t--)
    {
        Node *head=create_linked_list();
        int el;
        cout<<"Enter the el u want to insert:";
        cin>>el;
        head=insertIntoList(head,el);
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

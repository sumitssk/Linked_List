#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

void printLinkedList(Node* head)
{
    if(head==NULL)return;
    while(head!=NULL)
    {
       if(head->next==NULL)
       {
           cout<<head->data;
           break;
       }
       else
       {
            cout<<head->data<<"<=>";
            head=head->next;
       }
    }


}
Node* create_linked_list();

Node* delete_head_node(Node* head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
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
        head=delete_head_node(head);
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
        Node* temp=new Node(el);
        curr->next=temp;
        temp->prev=curr;
        curr=curr->next;

    }
    return head;

}

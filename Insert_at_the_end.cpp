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
    Node* curr=head;

    while(curr!=NULL)
    {
        if(curr->next==NULL)
        {
            cout<<curr->data;
            break;
        }
        cout<<curr->data<<"->";
        curr=curr->next;
    }

}

Node* insert_at_end(Node* head,int el);
int main()
{
    Node *head=NULL;
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head=insert_at_end(head,50);
    printLinkedList(head);
    return 0;
}


Node* insert_at_end(Node* head,int el)
{

    if(head==NULL)return new Node(el);
    Node *curr=head;
    while(curr->next!=NULL)curr=curr->next;
    curr->next=new Node(el);
    return head;
}


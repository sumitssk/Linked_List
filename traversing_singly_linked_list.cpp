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


int main()
{
    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    printLinkedList(head);
    return 0;
}


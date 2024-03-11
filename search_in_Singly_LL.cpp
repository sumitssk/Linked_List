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
int searchLL(Node* head,int el)
{
    if(head==NULL)return -1;
    Node* curr=head;
    int pointer=1;
    while(curr!=NULL)
    {
        if(curr->data==el)return pointer;
        curr=curr->next;
        pointer++;
    }
    return -1;
}
int recursiveSearchLL(Node* head,int el)
{
    if(head==NULL)return -1;
    if(head->data==el)return 1;
    else
    {
        int res=recursiveSearchLL(head->next,el);
        if(res==-1)return -1;
        else return res+1;
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
        int el;
        cout<<"enter the el u want to search:";
        cin>>el;
        cout<<recursiveSearchLL(head,el);
      //  printLinkedList(head);
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

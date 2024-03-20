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

Node* reverse_in_k_grps(Node* head,int k)
{
    if(head==NULL || !head->next)return head;
    Node* curr=head;
    Node* prev=NULL;
    bool first=true;
    Node* prev_head=NULL;
    Node* next_head=NULL;
    while(curr!=NULL)
    {
        int temp=k;
        while(temp-- && curr!=NULL)
        {
            
            Node* temp1=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp1;
            temp++;

        }
        if(first)
        {
            cout<<"\n";
            prev_head=head;
            head=prev;
            first=false;
            next_head=curr;
        }
        else
        {
            prev_head->next=prev;
            prev_head=next_head;
            next_head=curr;
        }
    }
    prev_head->next=NULL;
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
        int k;
        cout<<"Enter the k(group):";
        cin>>k;
        printLinkedList(head);
        head=reverse_in_k_grps(head,k);
        cout<<"\n";
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

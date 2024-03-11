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


vector<int> Middle_of_LL_2_for_even(Node* head)
{
    if(head==NULL)return {-1};
    if(head->next==NULL)return {head->data};
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;
    }
    if(fast==NULL)
    {
        return {prev->data,slow->data};
    }
    else 
    {
        return {slow->data};
    }

}

Node* Middle_of_LL(Node* head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)return head;
    Node* curr=head;
    Node* curr1=head;
    while(curr1!=NULL && curr1->next!=NULL)
    {
        curr=curr->next;
        curr1=curr1->next->next;
    }
    return curr;
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
        Node* middle=Middle_of_LL(head);
        if(middle==NULL)cout<<"NULL";
        else cout<<middle->data;
        cout<<"\n";
        vector<int> ans=Middle_of_LL_2_for_even(head);
        for(auto x:ans)cout<<x<<" ";
    //    cout<<middle_el->data;
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

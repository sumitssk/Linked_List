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
Node* create_looped_linked_list(int start,int end);

bool detect_loop(Node* head)
{
    if(!head)return false;

    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)return true;

    }
    return false;
}
void looped_at_given_pos_from_end(Node* head,int pos)
{
    if(pos==-1)return ;
    int count=0;
    Node* curr=head;
    Node* temp;
    while(curr->next!=NULL)
    {
        count++;
        if(count==pos)temp=curr;
        curr=curr->next;
    }
    curr->next=temp;

}
void remove_loop(Node* head)
{
    if(head==NULL || head->next==NULL)return;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)break;
    }
    slow=head;
    while(fast->next!=slow->next)
    {
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=NULL;
    return ;
}
int main()
{
    int t;
    cout<<"Enter the no of test cases:";
    cin>>t;
    while(t--)
    {
         int pos;
         cout<<"enter the pos of loop:";
         cin>>pos;
         Node *head=create_linked_list();
         looped_at_given_pos_from_end(head,pos);
         if(detect_loop(head))
         {
            cout<<"loop_detected"<<"\n";
            remove_loop(head);
            if(!detect_loop(head))cout<<"loop removed successfully";
         }
         else cout<<"loop not detected";
         
        
          cout<<"\n";
    }
    return 0;
}
Node* create_looped_linked_list(int start,int end)
{
    int n;
    cout<<"Enter the el in Linked list:";
    cin>>n;
    if(n==0)return NULL;
    int head_el;
    cout<<"Enter the el at the head:";
    cin>>head_el;
    Node *head=new Node(head_el);
    int count=1;
    Node* loop_end=NULL;
    if(end==count)loop_end=head;
    Node *curr=head;
    n=n-1;
    while(n--)
    {
        int el;
        cin>>el;
        count++;
        if(start==count)
        {
            curr->next=loop_end;
            return head;
        }
        if(end==count)loop_end=curr;
        curr->next=new Node(el);
        curr=curr->next;


    }
    return head;


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

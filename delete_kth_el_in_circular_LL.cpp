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
    Node* curr=head;
    cout<<curr->data<<"->";
    curr=curr->next;
    while(curr->next!=NULL)
    {
        if(curr==head)
        {
            cout<<curr->data;
            break;
        }
        cout<<curr->data<<"->";
        curr=curr->next;
    }
    

}
Node* create_linked_list();
Node* deleteKthEl(Node* head,int k)
{
    if(head==NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    int pointer=1;
    Node* curr=head;
    while(curr!=NULL)
    {

        if(pointer==k)
        {
            Node* temp=curr->next;
            swap(curr->data,curr->next->data);
            curr->next=curr->next->next;
             
            if(head!=temp)
            {
                delete temp;
                return head;
            }
            else
            {
                delete temp;
                return curr;
            }
            
        }
       curr=curr->next;
       pointer++;
    }
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
        cout<<"Enter the pos u want to delete:";
        cin>>k;
        head=deleteKthEl(head,k);
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
    head->next=head;
    Node *curr=head;
    n=n-1;
    while(n--)
    {
        int el;
        cin>>el;
        Node* temp=new Node(el);
        curr->next=temp;
        temp->next=head;
        curr=curr->next;

    }
    return head;

}

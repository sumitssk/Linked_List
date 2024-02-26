# Linked_List

<br>
<h1>Basic Linked list template</h1>
<br>
#include<iostream>
<br>
#include<bits/stdc++.h>
<br>
using namespace std;
<br>

struct Node
<br>
{
    <br>
    int data;
    <br>
    Node* next;
    <br>
    Node(int x)
    <br>
    {
        <br>
        data=x;
        <br>
        next=NULL;
        <br>
    }
    <br>
};


int main()
<br>
{
    <br>
    Node head=new Node(10);
    <br>
    head->next=new Node(20);
    <br>
    head->next->next=new Node(30);
    <br>
    head->next->next->next=new Node(40);
    <br>
    return 0;
    <br>
}
<br>


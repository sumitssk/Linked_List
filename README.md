# Linked_List

<br>
<h1>Basic Linked list template</h1>

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


int main()
{
    Node head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    return 0;
}


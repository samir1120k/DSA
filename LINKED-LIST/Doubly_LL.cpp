#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // creating constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory free for node with data :" << val << endl;
    }
};
// traversing linked list
void print(Node *Head)
{
    Node *temp = Head;
    cout << "Elements are :";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// give the length of linked list
int getlength(Node *Head)
{
    Node *temp = Head;
    int len = 0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
// insert at beginning
void InsertAtHead(Node *&Head, Node *&Tail, int d)
{
    if (Head == NULL)
    {
        Node *temp = new Node(d);
        Head = temp;
        Tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = Head;
        Head->prev = temp;
        Head = temp;
    }
}
// insert at end
void InsertAtTail(Node *&Head, Node *&Tail, int d)
{
    if (Tail == NULL)
    {
        Node *temp = new Node(d);
        Tail = temp;
        Head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        Tail->next = temp;
        temp->prev = Tail;
        Tail = temp;
    }
}
// insert element at any position;
void InsertAtPosition(Node *Head, Node *Tail, int position, int d)
{
    if (position == 1)
    {
        InsertAtHead(Head, Tail, d);
        return;
    }
    Node *temp = Head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        InsertAtTail(Head, Tail, d);
        return;
    }

    Node *nodeinsert = new Node(d);
    nodeinsert->next = temp->next;
    temp->next->prev = nodeinsert;
    temp->next = nodeinsert;
    nodeinsert->prev = temp;
}
void DeleteNode(int position, Node *&Head)
{
    if (position == 1)
    {
        Node *temp = Head;
        temp->next->prev = NULL;
        Head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = Head;
        Node *perv = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            perv = curr;
            curr = curr->next;
            cnt++;
        }
        curr->prev = NULL;
        perv->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    // craeating the first node
    Node *node1 = new Node(10);
    Node *Head = NULL;
    Node *Tail = NULL;

    // insert a new element at beginning
    InsertAtHead(Head, Tail, 29);
    InsertAtHead(Head, Tail, 49);
    InsertAtHead(Head, Tail, 32);

    // insert a new element at end
    InsertAtTail(Head, Tail, 23);
    InsertAtTail(Head, Tail, 32);
    InsertAtTail(Head, Tail, 28);

    // insert element at any position
    InsertAtPosition(Head, Tail, 3, 78);
    InsertAtPosition(Head, Tail, 4, 84);

    // delete Node at any position
    DeleteNode(3, Head);
    DeleteNode(7, Head);
    // print the node element
    print(Head);
    // print the length of linked list
    cout << "lenght is :" << getlength(Head);
    return 0;
}
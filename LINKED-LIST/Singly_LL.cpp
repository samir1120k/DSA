#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};
void InsertAtHead(Node *&Head, int d)
{
    Node *temp = new Node(d);
    temp->next = Head;
    Head = temp;
}
void print(Node *&Head)
{
    Node *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void InsertAtTail(Node *&Tail, int d)
{
    Node *temp = new Node(d);
    Tail->next = temp;
    Tail = Tail->next;
}
void InsertAtPosition(Node *&Tail, Node *&Head, int position, int d)
{
    // inserting at begaining
    if (position == 1)
    {
        InsertAtHead(Head, d);
        return;
    }
    Node *temp = Head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // Insereting at last node
    if (temp->next == NULL)
    {
        InsertAtTail(Tail, d);
        return;
    }
    Node *Insert = new Node(d);
    Insert->next = temp->next;
    temp->next = Insert;
}
void DeleteNode(int position, Node *&Head)
{
    // deleting first Node
    if (position == 1)
    {
        Node *temp = Head;
        Head = Head->next;
        // memory free
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle or last node
        Node *curr = Head;
        Node *pre = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            pre = curr;
            curr = curr->next;
            cnt++;
        }
        pre->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *node1 = new Node(10);

    // cout << node1->data << endl;
    // cout << node1->next << endl;
    // print the head element

    Node *Head = node1;
    Node *Tail = node1;
    //  print(Head);

    //  inserting new node

    InsertAtHead(Head, 12);
    InsertAtHead(Head, 15);
    InsertAtTail(Tail, 20);
    InsertAtTail(Tail, 30);
    InsertAtPosition(Tail, Head, 2, 13);
    InsertAtPosition(Tail, Head, 4, 40);
    InsertAtPosition(Tail, Head, 1, 23);
    print(Head);

    DeleteNode(1, Head);
    print(Head);
    DeleteNode(3, Head);
    print(Head);

    cout << "Head " << Head->data << endl;
    cout << "Tail " << Tail->data << endl;
    return 0;
}
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
void InsertAtPosition(Node *&Head, int position, int d)
{
    Node *temp = Head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *Insert = new Node(d);
    Insert->next = temp->next;
    temp->next = Insert;
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
    InsertAtPosition(Head, 2, 13);
    InsertAtPosition(Head, 4, 40);
    print(Head);

    return 0;
}
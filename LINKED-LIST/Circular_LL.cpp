#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data :" << val << endl;
    }
};
void insertNode(Node *&Head, int element, int d)
{
    //  if list is empty
    if (Head == NULL)
    {
        Node *temp = new Node(d);
        Head = temp;
        temp->next = temp;
    }
    else
    {
        // list is not empty
        Node *temp = Head;
        while (temp->data != element)
        {
            temp = temp->next;
        }

        // element found
        Node *node1 = new Node(d);
        node1->next = temp->next;
        temp->next = node1;
    }
}
// print the list
void print(Node *Head)
{
    Node *temp = Head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != Head);
}
void deletenode(Node *&Head, int value)
{
    // if list is empty
    if (Head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }
    else
    {
        // non empty list
        Node *prev = Head;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        if (prev == curr)
        {
            Head = NULL;
        }
        else if (Head == curr)
        {
            Head = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}
int main()
{
    Node *Head = NULL;
    // insert a new node
    insertNode(Head, 5, 3);
    insertNode(Head, 3, 6);
    insertNode(Head, 6, 9);
    insertNode(Head, 6, 3);

    // delete node
    deletenode(Head, 6);
    deletenode(Head, 9);
    deletenode(Head, 3);
    deletenode(Head, 3);

    // print the list
    print(Head);
    return 0;
}
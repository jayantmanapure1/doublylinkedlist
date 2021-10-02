#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *previous;

    Node(int data)
    {
        this->next = NULL;
        this->previous = NULL;
        this->data = data;
    }
};

void traverseLinkedList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ,";
        head = head->next;
    }
}

void traverseBackward(Node *back)
{
    while (back != NULL)
    {
        cout << back->data << " ,";
        back = back->previous;
    }
}

void deleteHead(Node *&head)
{
    if (head != NULL)
    {
        Node *node = head;
        head = node->next;
        head->previous = NULL;
        free(node);
    }else{
        cout<<"No Node to delete !!";
    }
}

void deleteLast(Node *last)
{
    last->previous->next = NULL;
    free(last);
}

void deleteAfterMid(Node *head)
{
    Node *fast = head;
    Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node *node = slow->next;
    node->next->previous  = slow;
    slow->next = node->next;
    free(node);
}

void deletionAfterNode(Node *node){
    node->previous->next = node->next;
    node->next->previous = node->previous;
    free(node);
}

Node *lastNode(Node *head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

int main()
{

    Node *head = new Node(10);
    Node *first = new Node(20);
    Node *second = new Node(45);
    Node *third = new Node(65);

    head->next = first;
    first->next = second;
    first->previous = head;

    second->next = third;
    second->previous = first;

    third->previous = second;

    traverseLinkedList(head);
    // cout<<"Back Wards=> " << endl;
    // traverseBackward(third);

    cout << "\nAfter Deletion => " << endl;

    // deleteHead(head);
    //deleteLast(lastNode(head));
    deletionAfterNode(first);
    traverseLinkedList(head);
    return 0;
}

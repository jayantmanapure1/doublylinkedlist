#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};
void traverForward(Node*node){
    while(node!=NULL){
        cout<<node->data<< " ";
        node=node->next;
    }
    cout<<"\n";
}
void traverBackward(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->prev;
    }
    cout<<"\n";
}

void insertAtBegin(Node *&head,int data){
    Node *newNode=new Node(data);
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
int main(){
    Node *head=new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);

    head->next=a;
    a->prev=head;

    a->next=b;
    b->prev=a;

    cout<<"Before Insertion : ";
    traverForward(head);
    cout<<"\n";
    traverBackward(head);

    insertAtBegin(head,5);
    cout<<"After Insertion : ";
    traverForward(head);
    cout<<"\n";
    traverBackward(head);

}

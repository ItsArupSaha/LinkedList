#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* previous;
    Node* next;

    Node(int data){
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }
};

int listCount = 0;

// Insertion at Doubly Linked List 
void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    
    if(head == NULL){
        head = n;
        listCount++;
        return;
    }

    n->next = head;
    head->previous = n;
    head = n;
    listCount++;
}

void insertAtTail(Node* &head, int data){
    Node* n = new Node(data);
    Node* temp = head;

    while(head == NULL){
        insertAtHead(head, data);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
    n->previous = temp;
    listCount++;
}

void insertAtNPosition(Node* &head, int data, int position){
    Node* n= new Node(data);
    Node* temp = head;
    int cnt=1;

    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    if(position > listCount+1){
        cout << "invalid position" << endl;
        return;
    }

    if(position == listCount+1){
        insertAtTail(head, data);
        return;
    }

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    Node* forward = temp->next;
    n->next = forward;
    forward->previous = n;
    temp->next = n;
    n->previous = temp;
    listCount++;
}

// Deletion in Doubly Linked List 
void deleteAtHead(Node* &head){

    if(head == NULL){
        cout << "There is nothing to delete" << endl;
        return;
    }

    Node* todel = head;
    head = head->next;
    head->previous = NULL;
    todel->next = NULL;
    delete todel;
    listCount--;
}

void deleteAtTail(Node* &head){

    if(head == NULL){
        cout << "There is nothing to delete" << endl;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* todel = temp->next;
    temp->next = NULL;
    todel->previous = NULL;
    delete todel;
    listCount--;
}

void deleteAtNPosition(Node* &head, int position){
    Node* temp = head;
    int cnt=1;

    if(position == 1){
        deleteAtHead(head);
        listCount--;
        return;
    }

    if(position == listCount){
        deleteAtTail(head);
        listCount--;
        return;
    }

    if(position > listCount){
        cout << "Invalid positon" << endl;
        return;
    }


    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }

    Node* todel = temp->next;
    temp->next = todel->next;
    todel->next->previous = todel->previous;
    todel->next = NULL;
    todel->previous = NULL;
    delete todel;
    listCount--;
}


// Displaying the doubly linked list data 
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){
    Node* head = NULL;
    display(head);

    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtNPosition(head, 4, 4);
    display(head);
    deleteAtHead(head);
    deleteAtTail(head);
    display(head);
    deleteAtNPosition(head, 2);
    display(head);

    return 0;
}
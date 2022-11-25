#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int listCounts = 0;

// Linked List insertion 
void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
    listCounts++;
}

void insertAtN(Node* head, int data, int position){
    Node* n= new Node(data);
    Node* temp = head;
    int cnt=1;

    if(position == 1){
        insertAtHead(temp, data);
        listCounts++;
        return;
    }

    if(position > listCounts+1){
        cout << "invalid position" << endl;
        return;
    }

    while(cnt < position-1){
        temp = temp->next;
    }

    n->next = temp->next;
    temp->next = n;
    listCounts++;
}

void insertAtTail(Node* head, int data){
    Node* n = new Node(data);
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}

// Linked list Deletion 
void deleteAtHead(Node* &head){
    Node* temp = head;

    if(temp == NULL){
        cout << "No elements in the list to delete" << endl;
        return;
    }

    head = temp->next;
    temp->next = NULL;
    delete temp;
    listCounts--;

}

void deleteAtTail(Node* head){
    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* todel = temp->next;
    temp->next = NULL;
    delete todel;
    listCounts--;
}

void deleteAtNPosition(Node* &head, int position){
    Node* temp = head;
    int cnt=1;

    if(position == 1){
        deleteAtHead(head);
        listCounts--;
        return;
    }

    if(position > listCounts){
        cout << "Invalid positon" << endl;
        return;
    }


    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }

    Node* todel = temp->next;
    temp->next = todel->next;
    todel->next = NULL;
    delete todel;
    listCounts--;
}

void deleteByData(Node* &head, int data){
    Node* temp = head;

    if(temp->data == data){
        deleteAtHead(head);
        listCounts--;
        return;
    }

    while(temp->next->data != data){
        temp = temp->next;
    }

    Node* todel = temp->next;
    temp->next = todel->next;
    todel->next = NULL;
    delete todel;
    listCounts--;
}

// Display Linked List Data 
void display(Node* head){
    Node* temp = head;

    if(temp == NULL){
        cout << "Nothing is there" << endl;
        return;
    }

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main(){

    Node* head = NULL;

    display(head);
    insertAtHead(head, 1);
    display(head);
    insertAtN(head, 2, 2);
    insertAtTail(head, 3);
    display(head);
    deleteAtHead(head);
    display(head);
    deleteAtTail(head);
    display(head);
    insertAtTail(head, 4);
    insertAtTail(head, 6);
    insertAtTail(head, 8);
    display(head);
    deleteAtNPosition(head, 1);
    display(head);
    deleteByData(head, 4);
    display(head);

    return 0;
}
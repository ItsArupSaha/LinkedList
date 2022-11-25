#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data) {
        this->data= data;
        next= NULL;
    }
};

void insertAtHead(Node* &head, int data) {
    Node* n= new Node(data);
    n->next= head;
    head= n;
}

void insertAtN(Node* head, int pos, int data) {
    Node* n= new Node(data);
    Node* temp= head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }

    n->next= temp->next;
    temp->next= n;
 
}

void insertAtTail(Node* &head, int data) {
    Node* n= new Node(data);

    if(head == NULL) {
        head=n;
        return;
    }
    Node* temp= head;

    while(temp->next!=NULL) {
        temp= temp->next;
    }
    temp->next= n;

}

void delHead(Node* &head) {
    if(head == NULL){
        return;
    }

    Node* todel = head;
    head= head->next;
    delete todel;
}

void delTail(Node* head) {
    Node* temp= head;

    while(temp->next->next!=NULL) {
        temp= temp->next;
    }

    Node* todel= temp->next;
    temp->next= NULL;
    delete todel;
}

void delAtN(Node* head, int pos) {
    Node* temp= head;
    int cnt = 1;

    while(cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    
    Node* todel= temp->next;
    temp->next= temp->next->next;
    delete todel;

}


void printAll(Node* head) {
    Node *temp = head;

    if(temp == NULL){
        cout << "nothing is there";
        return;
    }

    while(temp!=NULL) {
        cout<< temp->data << " ";
        temp= temp->next;
    }
    cout<<endl;
}


int main() {
    
    Node* head = NULL;

    int ch, data, pos, choice;

    while(1) {
        cout<<"\n\nnexted List Manageer" << endl;

        cout<<"1. Display All Nodes" << endl;
        cout<<"2. Insert at Tail" << endl;
        cout<<"3. Insert at Head" << endl;
        cout<<"4. Insert at N position" << endl;
        cout<<"5. Delete Head" << endl;
        cout<<"6. Delete Tail" << endl;
        cout<<"7. Delete at N Position" << endl;
        cout<<"0. Exit" << endl;
        cout<<"\nEnter your choice:" << endl;

        cin>> choice;

        switch(choice) {
            case 1:
                printAll(head);
                break;
            case 2:
                cout<<"Enter a data to add at Tail: " << endl;
                cin>> data;
                insertAtTail(head,data);
                break;
            case 3:
                cout<<"Enter a data to add at Head:" << endl;
                cin>> data;
                insertAtTail(head, data);
                break;
            case 4:
                cout<<"Enter a data to add:" << endl;
                cin>> data;
                cout<<"Enter the position for the dataue:" << endl;
                cin>> pos;
                insertAtN(head, pos, data);
                break;
            case 5:
                delHead(head);
                cout<<"Head Deleted.\nEnter anything to continue" << endl;
                cin>> choice;
                break;
            case 6:
                delTail(head);
                cout<<"Tail deleted. \nEnter anything to continue:" << endl;
                cin>> choice;
                break;
            case 7: 
                cout<<"Enter the position  you want to delete:" << endl;
                cin>> pos;
                delAtN(head, pos);
                break;
            case 0:
                return 0;
            default: 
                exit(0);

        }
    }

    return 0;
}
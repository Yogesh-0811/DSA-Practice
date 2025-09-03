#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev = nullptr;
    }
};

Node* reverseList(Node* head){

    if(!head) return head;

    Node* curr = head;
    Node* temp = NULL;

    while(curr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr=curr->prev;
    }

    if(temp){
        head = temp->prev;
    }

    return head;
}

void printList(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" <-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    Node *head = NULL;
    Node *tail = NULL;

    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);
        if(head == NULL){
            head=newNode;
            tail=newNode;
        }else{
            tail->next=newNode;
            newNode->prev = tail;
            tail=newNode;
        }
    }

    cout<<"Original List: ";
    printList(head);

    head = reverseList(head);

    cout<<"Reversed List: ";
    printList(head);

    return 0;
}
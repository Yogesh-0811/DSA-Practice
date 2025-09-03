#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* reverseList(Node* head){
    Node*prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head=head->next;
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
#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* rotateRight(Node* head,int k){
    if(!head || !head->next || k==0) return head;

    int size=1;
    Node* tail = head;
    while(tail->next){
        size++;
        tail=tail->next;
    }
    tail->next=head;
    k=k%size;
    int steps = size-k;
    Node* newTail = head;
    for(int i=1;i<steps;i++){
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    int n,k;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter list elements: ";
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }

    cout<<"Enter k: ";
    cin>>k;

    cout<<"Original List: ";
    printList(head);

    head = rotateRight(head, k);
    cout<<"Rotated List: ";
    printList(head);

    return 0;
}
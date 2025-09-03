#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

Node* vectorToLinkedList(const vector<int>& arr){
    if(arr.empty()) return NULL;
    Node *head = new Node(arr[0]);
    Node* tail = head;

    for(size_t i=1;i<arr.size();i++){
        tail->next = new Node(arr[i]);
        tail=tail->next;
    }
    return head;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    vector<int> vec = {1,2,3,4,5};

    Node* head = vectorToLinkedList(vec);
    cout<<"Linked List: ";
    printList(head);

    return 0;
}
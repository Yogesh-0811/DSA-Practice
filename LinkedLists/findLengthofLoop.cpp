#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};

int findLengthLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            int count = 1;
            Node* temp = slow->next;
            while(temp!=slow){
                count++;
                temp=temp->next;
            }
            return count;
        }
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    Node* head = nullptr;
    Node* tail = nullptr;

    cout<<"Enter node values: ";
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        Node* newNode = new Node(val);
        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    int pos;
    cout<<"Enter position to create loop (0 for no loop): ";
    cin>>pos;

    if(pos>0){
        Node* temp = head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        tail->next = temp;
    }

    int loopLength = findLengthLoop(head);
    if(loopLength == 0){
        cout<<"No loop detected"<<endl;
    }else{
        cout<<"Length of loop: "<<loopLength<<endl;
    }

    return 0;
}
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

vector<int> linkedListToVector(Node* head){
    vector<int>result;
    Node* temp = head;
    while(temp){
        result.push_back(temp->data);
        temp = temp->next;
    }
    return result;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout<<"Linked List: ";
    printList(head);

    vector<int>vec = linkedListToVector(head);

    cout<<"Vector: ";
    for(int x:vec){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
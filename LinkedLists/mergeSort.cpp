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

void printList(Node* head){
    while(head){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

Node* merge(Node* l1, Node* l2){
    if(!l1) return l2;
    if(!l2) return l1;

    Node dummy(0);
    Node* tail = &dummy;

    cout<<"Merging: ";
    printList(l1);
    cout<<" with ";
    printList(l2);

    while(l1 && l2){
        if(l1->data<=l2->data){
            tail->next = l1;
            l1 = l1->next;
        }else{
            tail->next  = l2;
            l2 = l2->next;
        }
        tail=tail->next;
    }
    tail->next = (l1?l1:l2);

    cout<<"Result of merge: ";
    printList(dummy.next);
    cout<<"---------"<<endl;

    return dummy.next;

}

Node* getMiddle(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* head){
    if(!head || !head->next){
        cout<<"base case reached with: "<<(head ? head->data:-1)<<endl;
        return head;
    }
    Node* mid = getMiddle(head);
    Node* right = mid->next; 
    mid->next = NULL;

    cout<<"Splitting List: ";
    printList(head);
    cout<<" and ";
    printList(right);

    Node* leftSorted  = mergeSort(head);
    Node* rightSorted = mergeSort(right);
    return merge(leftSorted,rightSorted);
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements: ";
    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);
        if(!head){
            head  = tail = newNode;
        }else{
            tail->next = newNode;
            tail = tail->next;
        }
    }
    cout<<"Original List: ";
    printList(head);
    head = mergeSort(head);

    cout<<"Sorted List: ";
    printList(head);

    return 0;
}
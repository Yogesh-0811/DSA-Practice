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

Node* swapKthNode(Node* head,int k){
    if(!head) return head;

    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp=temp->next;
    }
    if(k>len) return head;
    if(2*k-1==len) return head;

    Node* first = head;
    for(int i=1;i<k;i++){
        first=first->next;
    }

    Node* second = head;
    for(int i=1;i<len-k+1;i++){
        second=second->next;
    }

    swap(first->data,second->data);
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
    int n;
    cout<<"Enter number of nodes: ";
    cin>>n;

    Node* head = NULL;
    Node* tail = NULL;

    cout<<"Enter "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    cout<<"Original List: ";
    printList(head);

    int k;
    cout<<"Enter k: ";
    cin>>k;

    head = swapKthNode(head,k);

    cout<<"After Swapping: ";
    printList(head);

    return 0;
}
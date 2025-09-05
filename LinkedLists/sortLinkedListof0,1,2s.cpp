#include <iostream>
// #include <vector>
// #include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

class Solution{
    public:
    
    // Node* segregate(Node* head) {
    //     // code here
    //     vector<int>result;
    //     Node* temp = head;
    //     while(head){
    //         result.push_back(head->data);
    //         head=head->next;
    //     }
    //     sort(result.begin(),result.end());
    //     Node* res = new Node(result[0]);
    //     Node* tail = res;
    //     for(int i=1;i<result.size();i++){
    //         tail->next = new Node(result[i]);
    //         tail=tail->next;
    //     }
    //     return res;
    // }

    Node * segregate(Node* head){
        if(!head || !head->next) return head;
        Node* zerohead = new Node(0);
        Node* onehead = new Node(0);
        Node* twohead = new Node(0);

        Node* zero = zerohead;
        Node* one = onehead;
        Node* two = twohead;

        Node* current = head;
        while(current){
            if(current->data == 0){
                zero->next = current;
                zero = zero->next;
            }else if (current->data == 1){
                one->next = current;
                one = one->next;
            }else{
                two->next = current;
                two = two->next;
            }
            current = current->next;
        }

        zero->next = (onehead->next) ? (onehead->next) : (twohead->next);
        one->next = twohead->next;
        two->next = NULL;

        head = zerohead->next;

        delete zerohead;
        delete onehead;
        delete twohead;

        return head;
    }
};

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

    Node* head= NULL;
    Node* tail= NULL;

    cout<<"Enter "<<n<<" elements (0,1,2 only): ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Node* newNode = new Node(x);
        if(!head){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail=newNode;
        }
    }
    cout<<"Original List: ";
    printList(head);

    Solution obj;
    head  = obj.segregate(head);

    cout<<"Sortedd List: ";
    printList(head);

    return 0;
}
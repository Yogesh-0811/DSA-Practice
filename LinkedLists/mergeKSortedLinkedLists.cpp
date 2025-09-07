#include <iostream>
#include <vector>
#include <queue>
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

class Solution{
    public:
    Node* mergeKLists(vector<Node*>& arr){
        auto cmp = [](Node* a,Node* b){
            return a->data>b->data;
        };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);

        for(auto list:arr){
            if(list) pq.push(list);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while(!pq.empty()){
            Node* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if(node->next){
                pq.push(node->next);
            }
        }
        return dummy->next;
    }
};

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    Node* l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node*> arr = {l1, l2, l3};

    Solution s;
    Node* merged = s.mergeKLists(arr);

    printList(merged);

    return 0;

}
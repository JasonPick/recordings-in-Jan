#include <iostream>
#include <map>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// O(N) O(N)
// hash map from original node to clone node
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> dict;
        Node* tail = head;
        while (tail != nullptr) {
            Node* clone = new Node(tail->val);
            dict[tail] = clone;
            tail = tail->next;

        }
        tail = head;
        Node* prev = dict[head];
        Node* curr = nullptr;
       
        while(tail != nullptr){
            curr = dict[tail];
            curr->next = dict[tail->next];
            curr->random = dict[tail->random];
            tail = tail->next;
        
        }
        return prev;
        
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node * next = nullptr;
        
        // 1st round: make a copy of each node
        while(iter!=nullptr){
            next = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = next;
            iter = next;
        }

        // 2nd round: assign random pointers for copy node
        iter = head;
        while(iter!=nullptr){
            if(iter->random != nullptr){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }

        // 3rd round: assign next pointers for copy node
        iter = head;
        Node* pHead = new Node(0);
        Node* copy = pHead;
        Node* copyIter = pHead;

        while(iter!=nullptr){
            next = iter->next->next;
            copy = iter->next;
            copyIter->next = copy;
            copyIter = copy;

            iter->next = next;
            iter = next;
            
        }
        return pHead->next;
    }
};
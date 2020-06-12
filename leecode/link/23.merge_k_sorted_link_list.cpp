#include <iostream>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
struct compare
{
    bool operator() (const ListNode* o1, const ListNode* o2) { 
        return o1->val > o2->val; 
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty()) return nullptr;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        priority_queue<ListNode*,vector<ListNode*>,compare> q;
        for(auto node :lists) {
            if(node) q.push(node);
        }
        while(!q.empty()) {
            curr->next= q.top();
            q.pop();
            curr= curr->next;
            if(curr->next != nullptr){
                q.push(curr->next);   
            }
                    
        }
        return head->next;
        
        
    }
};
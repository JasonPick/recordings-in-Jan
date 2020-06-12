#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr || n<=0) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        while(n--){
            fast = fast->next;
        }
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};

int main(){
    Solution* sol = new Solution();
    ListNode* head  = new ListNode(1);
    ListNode* nxt  = new ListNode(2);
    //head->next = nxt;
   
    int n = 1; 

    ListNode* newHead = new ListNode();
    newHead = sol->removeNthFromEnd(head,n);
    
    while(newHead!= nullptr){
        cout << "content  "<<newHead->val;
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}
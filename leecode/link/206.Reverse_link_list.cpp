struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
 //iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr||head->next == nullptr) return head;
       
        ListNode* prev = nullptr;
        
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;

        
    }
};

//recurssive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        return helper(head,nullptr);
        
    }
    ListNode* helper(ListNode* head, ListNode* newHead) {
       if(head == nullptr) return newHead;
       ListNode* nxt = head->next;
       head->next = newHead;
       return helper(nxt,head);

    }
};
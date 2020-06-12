struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
// v1
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* curr = head;
        while(curr->next != nullptr){
            if(curr->next->val == curr->val){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
        
    }
};
//v2

class Solution {

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr||head->next == nullptr) return head;
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr != nullptr){
            if(prev->val == curr->val){
                prev->next = curr->next;
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

    }

};
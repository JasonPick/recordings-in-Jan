 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        while(head->next != nullptr){
            if(head->next->val == val){
                head->next = head->next->next;
            }else{
                head = head->next;
            }
           
        }
        return dummy->next;
        
        
    }
};
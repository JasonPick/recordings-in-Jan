struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
  
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr||head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        while(head->next != nullptr&& head->next->next != nullptr){
            if(head->next->val == head->next->next->val){
                int duplicate = head->next->val;
                while(head->next!=nullptr && head->next->val == duplicate){
                    head->next = head->next->next;
                }
            }else{
                head = head->next;
            }
        }  
        return dummy->next; 
    
    }
};
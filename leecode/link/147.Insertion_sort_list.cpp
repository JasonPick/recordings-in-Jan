struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next =head;
        ListNode* curr = head;
        ListNode* temp, *prev;
        while(curr != nullptr&&curr->next!=nullptr) {
            if(curr->val <= curr->next->val){
                curr = curr->next;
            }else{
                //deletion
                temp = curr->next;
                curr->next = temp->next;
                
                //insertion
                prev = dummy;
                while(prev->next->val <= temp->val){
                    prev = prev->next;
                }
                temp->next =prev->next;
                prev->next =temp;
            }
            
        }
        return dummy->next;
    }

};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:

    ListNode* detectCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        bool has_c = false;
        while(fast!=nullptr && fast->next!= nullptr&&slow!= nullptr){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                has_c = true;
            }
        }
        if(!has_c) return nullptr;
        ListNode* temp = head;
        while(temp!=slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
    
};
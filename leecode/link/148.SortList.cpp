struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;
        while(fast!=nullptr && fast->next!=nullptr){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        ListNode* left_side = sortList(head);
        ListNode* right_side = sortList(slow);
        
        return merge(left_side, right_side);
        
    }

    ListNode* merge(ListNode* l,ListNode* r){
        ListNode* sortTemp = new ListNode(0);
        ListNode* currNode = sortTemp;
        while(l!=nullptr && r!=nullptr){
            if(l->val<r->val){
                currNode->next = l;
                l = l->next;
            }else{
                currNode->next = r;
                r = r->next;
            }
            currNode = currNode->next;
        }

        if(l!=nullptr){
            currNode->next = l;
            l = l->next;
        }
        if(r != nullptr){
            currNode->next = r;
            r = r->next;
        }
        return sortTemp->next;

    }
};
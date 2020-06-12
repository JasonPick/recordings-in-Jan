struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

        
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return ;
        
        ListNode* l1 = head;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while(fast!=nullptr && fast->next!=nullptr) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        prev->next =nullptr;

        ListNode* l2 = reverse(slow);

        merge(l1,l2);


    }
    ListNode* reverse(ListNode* head){
        ListNode* dummy = nullptr;
        ListNode* currNode = head;
        while(currNode!=nullptr){
            ListNode* nxt = currNode->next;
            currNode->next = dummy;
            dummy = currNode;
            currNode = nxt;

        }
        return dummy;
    }
    void merge(ListNode* l1, ListNode* l2){
        while(l1!=nullptr){
            ListNode* l1_nxt = l1->next;
            ListNode* l2_nxt = l2->next;
           
            l1->next = l2;

            if(l1_nxt == nullptr) break;

            l2->next = l1_nxt;
            
            l1 = l1_nxt;
            l2 = l2_nxt;
        }
    }
};
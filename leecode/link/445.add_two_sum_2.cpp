struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0,n2 = 0;
        ListNode* tail1 = l1;
        ListNode* tail2 = l2;
        int carry = 0;
        while(tail1 != nullptr){
            tail1 = tail1->next;
            n1++;
        }
        while(tail2 != nullptr){
            tail2 = tail2->next;
            n2++;
        }
        tail1 = l1; tail2 = l2;
        ListNode* res = nullptr;
        while(n1>0 && n2>0){
            int sum = 0;
            if(n1>=n2){
                sum += tail1->val;
                tail1 = tail1->next;
                n1--;
            }
            if(n1<n2){
                sum += tail2->val;
                tail2 = tail2->next;
                n2--;
            }
            res = addToFront(sum,res);

        }
        tail1 = res;
        res = nullptr;
        while(tail1){
            tail1->val += carry;
            carry = tail1->val/10;
            res = addToFront(tail1->val%10,res);
            tail2 = tail1;
            tail1 = tail1->next;
            delete tail2;

        }
        if(carry){
            res = addToFront(1,res);
        }
        return res;
        

        
    }
    ListNode* addToFront(int x,ListNode* head){
        ListNode* tmp = new ListNode(x);
        tmp->next = head;
        return tmp;
    }
};
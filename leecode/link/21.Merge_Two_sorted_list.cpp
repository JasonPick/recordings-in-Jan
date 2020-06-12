#include <iostream>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        
        while(l1!=nullptr && l2!=nullptr) {
            if(l1->val < l2->val){
                prev->next = l1;
                l1 = l2->next;
            }else{
                prev ->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 ? l1 : l2;
        return dummy.next;
        
    }
};
// recursive

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        if(l1->val<l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;

        }

    }
    

};

int main(){
    Solution* sol = new Solution();

    ListNode* l1 = new ListNode(1);
    ListNode* l1_2 = new ListNode(2);
    l1->next = l1_2;
    ListNode* l2 = new ListNode(1);
    ListNode* l2_2 = new ListNode(3);
    l2->next = l2_2;
    
    ListNode* res = sol ->mergeTwoLists(l1,l2);
    while(res != nullptr){
        cout<<" : "<<res->val;
        res = res->next;
    }
    cout<<endl;
    return 0;
}
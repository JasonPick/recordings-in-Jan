#include<iostream>
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return false;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tmp = nullptr;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }
        while(slow!=nullptr){
            ListNode* nxt = slow->next;
            slow->next = tmp;
            tmp = slow;
            slow = nxt;
        }
        while(head!=nullptr && pre!= nullptr){ 
            if(head->cal != pre->val) return false;
            head = head->next;
            pre = pre->next;

        }
        return true;

    }
  };
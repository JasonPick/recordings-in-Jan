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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* end = dummy;

        while(end->next != nullptr){
          for(int i = 0; i<k ; i++){
               if(end == nullptr)
                   break;
                end = end->next;
            }
            ListNode* start = prev->next;
            ListNode* nxt = end->next;

            end->next = nullptr;
            prev ->next = reverse(start);
            start ->next = nxt;
            prev = start;
            end = start;

        

        }
        return dummy->next;
        
    }
    ListNode* reverse(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
};
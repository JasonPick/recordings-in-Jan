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
    ListNode * swapPairs(ListNode * head){
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        ListNode * pre = dummy;
        while(head && head->next){
            ListNode * A = head;
            ListNode * B = head->next;
            //swapPairs
            pre->next = B;
            A->next = B->next;
            B->next = A;

            pre = A;
            head = A->next;
        }
        return dummy->next;

    }


};
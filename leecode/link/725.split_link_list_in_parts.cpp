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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        ListNode* curr = root;
        int N = 0;
        while(curr != nullptr){
            curr = curr->next;
            N++;
        }

        int width = N/k;
        int rem = N%k;

        vector<ListNode*> res(k);
        curr = root;
        for(int i = 0;i<k;i++){
            ListNode* head = curr;
            for(int j = 0;j<width+(i<rem?1:0)-1;j++){
                if(curr!=nullptr) curr = curr->next;
            }
            if(curr!= nullptr){
                ListNode* prev = curr;
                curr = curr->next;
                prev->next = nullptr;
            }
            res[i] = head;
        }
        return res;
    }
};
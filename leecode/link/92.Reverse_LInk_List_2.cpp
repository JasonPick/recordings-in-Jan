#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int m, int n) {
//         if(head == nullptr ) return head;
//         ListNode* prev = nullptr;
//         ListNode* curr = head;
        
//         while(m > 1){
//             prev = curr;
//             curr = curr->next;
//             m--;
//             n--;
//         }
//         ListNode* start = prev;
//         ListNode* end = curr;
//         while(n>0){
//             ListNode* nxt = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nxt;
//             n--;
//         }
//         if(start!=nullptr){
//             start->next = prev;
//         }else{
//             head = prev;
//         }
//         end->next = curr;
        
//     return head;    
//     }
// };
 
//  int main(){
//      Solution* sol = new Solution();
//      ListNode* one = new ListNode(3);
//      ListNode* two = new ListNode(5);
//      one->next = two;
//      ListNode* node = sol->reverseBetween(one,1,2);
//      while(node != nullptr){
//          cout<<": "<<node->val;
//          node = node->next;
//      }
//      cout<<endl;
//      return 0;

//  }
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* index = head;
        int count = 1;
        while(index->next != nullptr){
            count++;
            index = index->next;
        }
        k = k % count;
        //make a circle
        index->next = head;
        int m = count-k-1;

        while(m--){
            head = head->next;
        }
        ListNode* res = head->next;
        head->next = nullptr;
        return res;
    
    }
};


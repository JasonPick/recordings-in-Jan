struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

        
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr||head->next == nullptr) return head;
        
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        
        k = k % count;

        if(k == 0){ return head;}
        reverse(head);
        reverseBetweens(head,1,k);
        reverseBetweens(head,k+1,count);

        
    }
    void reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* nxt = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    void reverseBetweens(ListNode* head,int m, int n){
       
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(m>1){
            prev = curr;
            curr = curr -> next;
            m--;
            n--;

        }
        ListNode* start = prev;
        ListNode* end = curr;
        //reverse
        while(n>0){
            ListNode* nxt = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            n--;

        }

        //connect
        if(start!=nullptr){
            start->next = prev;
        }else{
            head = prev;
        }
        
        end->next = curr;

    }

};
// sol 2
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
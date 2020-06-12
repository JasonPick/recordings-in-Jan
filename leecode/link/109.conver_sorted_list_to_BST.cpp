struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return head;
        if(head->next == nullptr) return new TreeNode(head->val);

        return build(ListNode* head,nullptr);


    }
    TreeNode* build(ListNode* start,ListNode* end) {
        if(start == end) return nullptr;

        ListNode* fast = start;
        ListNode* slow = start;

        while(fast!=end && fast->next!=end ){
            slow = slow->next;
            fast = fast->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = build(start,slow);
        root->right = build(slow->next,fast);
        return root;


    }
};
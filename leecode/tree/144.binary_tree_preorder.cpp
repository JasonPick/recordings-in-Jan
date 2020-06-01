#include <iostream>;
#include <vector>;
#include <stack>;
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

//Recursive 
class Solution{
public:
    vector<int>preorderTraversal(TreeNode* root){
        vector<int> res;
        if (!root) return res;
        helper(res,root);
        return res;

    }
private:
    void helper(vector<int> &res, TreeNode* root){
        if (!root) return;
        res.push_back(root->val);
        helper(res,root->left);
        helper(res,root->right);
    }

};

//Iterative
class Solution{
public:
    vector<int>preorderTraversal(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            if (node){
                res.push_back(node->val);
                stack.push(node->right);
                stack.push(node->left);
            }
        }
        return res;
        
        
    }
};

#include <iostream>;
#include <vector>;
#include <stack>;
#include<algorithm>;
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
        helper(res,root->left);
        helper(res,root->right);
        res.push_back(root->val);
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
            TreeNode* cur = stack.top();
            stack.pop();
            if (cur){
                res.push_back(cur->val);    
                stack.push(cur->left);
                stack.push(cur->right);

            }      
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
        
        
};
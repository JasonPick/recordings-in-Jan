#include <iostream>;
#include <vector>;
#include <queue>;
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x), left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x),left(left),right(right){}
};

class Solution{
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root,0,res);
        return res;
        
    }
private:
    void helper(TreeNode* root, int level, vector<int> &res){
        if (!root) return;
        if(level >= res.size()){
            res.push_back(root->val);
        }else{
            res.at(level) = max(res.at(level),root->val);
        }
        helper(root->left,level+1,res);

        helper(root->right,level+1,res);
    }
};
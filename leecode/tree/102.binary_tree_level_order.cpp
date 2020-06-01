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

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        dfs_level(root,0,res);
        return res;
        
    }
private:
    void dfs_level(TreeNode* node,int level, vector<vector<int>> &res){
        //edge
        if(!node) return;
        if(level >= res.size()){
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(node->val);
        dfs_level(node->left,level+1,res);
        dfs_level(node->right,level+1,res);

    }


};
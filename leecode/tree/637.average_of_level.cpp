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
//level traversal
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root) return res;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            double sum = 0;
            int count = 0;
            int size = queue.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = queue.front();
                queue.pop();
                sum += node->val;
                count += 1;
                if(node->left != nullptr) queue.push(node->left);
                if(node->right != nullptr) queue.push(node->right);


            }
            res.push_back(sum/count);
            
        }
        return res;
        
    }
};


//dfs
class Solution{
public:
    vector<double> averageOfLevels(TreeNode* root){
        vector<double> res;
        vector<int> count;
        if(!root) return res;
        helper(root,0,res,count);
        for(int i = 0; i< res.size();i++){
            res.at(i) = res.at(i)/count[i];
        }
        return res;
    }
    void helper(TreeNode* root, int level, vector<double> &res, vector<int> &count){
       if(!root) return;
        if(level >= res.size()){
            res.push_back(root->val);
            count.push_back(1);
        }else{
            res.at(level) = res.at(level)+root->val;
            count.at(level)+= 1;
        }
        helper(root->left,level+1,res,count);
        helper(root->right,level+1,res,count);
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int level = 0;
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            vector<int> tmp;
            int size = queue.size();
            for(int i = 0; i< size;i++){
                TreeNode* node = queue.front();
                queue.pop();
                if(node){
                    if(level%2 == 0) tmp.push_back(node->val);
                    else tmp.insert(tmp.begin(),node->val);
                    if(node->left) queue.push(node->left);
                    if(node->right) queue.push(node->right);
                }
            }
            res.push_back(tmp);
            level++;
        }
        
        return res;
        
    }

    
    
};
        
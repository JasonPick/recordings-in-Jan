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
// iterative
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(!root) return root;
        
        if(d == 1){
            TreeNode* node =  new TreeNode(v);
            node->left = root;
            return node;

        }
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            if(--d == 0) return root;
            int size = queue.size();
            for(int i = 0; i<size; i++){
                TreeNode* node = queue.front();
                queue.pop();
                if(d == 1){
                    TreeNode* left = new TreeNode(v);
                    left->left = node->left;
                    node->left = left;
                    TreeNode* right = new TreeNode(v);
                    right->right = node->right;
                    node->right = right;

                }else{
                    if(node->left != nullptr){
                        queue.push(node->left);
                    }
                    if(node->right != nullptr){
                        queue.push(node->right);
                    }
                }
            }
        }
        return root;


        
    }
};
//recursive
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* node = new TreeNode(v);
            node->left = root;
            return node;
        }
        helper(root,1,v,d);
        return root;

    }
    void helper(TreeNode* root, int level, int v, int d){
        if(!root) return;
        if(level < d-1){
            helper(root->left,level+1,v,d);
            helper(root->right,level+1,v,d);
            
        }else{
            TreeNode* left = new TreeNode(v);
            left->left = root->left;
            root->left = left;
            TreeNode* right = new TreeNode(v);
            right->right = root->right;
            root->right = right;

        }

    }
};
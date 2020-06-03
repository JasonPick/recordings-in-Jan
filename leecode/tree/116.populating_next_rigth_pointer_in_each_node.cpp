class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

//Recursive
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left != nullptr) root->left->next = root->right;
        if(root->next != nullptr && root->right != nullptr) root->right->next = root->next->left;

        connect(root->left);
        connect(root->right);
        return root;
        
    }
};
//Iterative
class Solution {
public:
    Node* connect(Node* root) {
        // two loops
        Node* start = root;
        while(start!= nullptr){
            Node* cur = start;
            while(cur!= nullptr){
                if(cur->left != nullptr  && cur->right!=nullptr){
                    cur->left->next = cur->right;
                }
                if (cur->next != nullptr){
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            start = start->left;
        }
        return root;

    }
};
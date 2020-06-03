#include <iostream>;
#include <vector>;
#include <stack>;
#include <algorithm>;
using namespace std;

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
        Node* start = nullptr;
        Node* prev = nullptr;
        Node* cur = root;
        while( cur!= nullptr){
            while(cur!= nullptr){
                if(cur->left != nullptr){
                    if(prev!=nullptr){
                        prev->next = cur->left;
                    } 
                    else{
                        start = cur->left;
                    }
                    prev = cur->left;
                    }
               
                if(cur->right !=nullptr){
                    if(prev!=nullptr){
                        prev->next = cur->right;
                    }
                    else{
                        start = cur->right;
                    }
                    prev = cur->right;
                }
             cur = cur->next;
            }
            cur = start;
            prev = nullptr;
            start = nullptr;
        }
         return root;

     
        
    }
};
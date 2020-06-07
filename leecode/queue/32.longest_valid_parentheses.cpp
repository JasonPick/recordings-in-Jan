#include<iostream>
#include<stack>
#include<string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> myStack;
        myStack.push(-1);
        int Max = 0;
        for(int i = 0; i< s.size();i++){
            int top = myStack.top();

            if(top!=-1 && s[top] == '(' && s[i] == ')'){
                myStack.pop();
                top = myStack.top();
                Max = max(Max,i-top);
            }else{
                myStack.push(i);
            }

        }
        return Max;
        
    }
};
#include<iostream>
#include<stack>
#include<string>

class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;
        for(char c: s){
            if(c == '(')
               myStack.push(')');
            else if(c == '[')
               myStack.push(']');
            else if(c == '{')
               myStack.push('}');
            else if(myStack.empty() || myStack.top()!=c )
               return false;
            else 
                myStack.pop();
        

        }
        return myStack.empty();
    }
};
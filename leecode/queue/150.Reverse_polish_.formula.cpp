#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        string operators = "+-*/";
        for(string token : tokens){
            if(operators.find(token)!=string::npos){
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                if(token.compare("+") == 0)
                    s.push(x+y);
                if(token.compare("-") == 0)
                    s.push(x-y);
                if(token.compare("*") == 0)
                    s.push(x*y);
                if(token.compare("/") == 0)
                    s.push(x/y); 
                // is an operator
            }else{
                // token is a number
                s.push(stoi(token));
            }
        }
        return s.top();
        
    }
};
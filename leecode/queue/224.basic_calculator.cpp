#include<stack>
#include<string>
#include<queue>
#include<iostream>

using namespace std;
//iterative
// class Solution{
// public:
//     int calculate(string s){
//         stack<int> stack;
//         int res = 0;
//         int num = 0;
//         int sign = 1;
        
//         for(int i = 0; i<s.size();i++){
//             char c = s[i];
//             if(c>='0' && c<='9'){
//                 num = num*10 + (int)(c-'0');
//             }else if(c == '+'){
//                 res = res + sign * num;
//                 num = 0;
//                 sign  = 1;
//             }else if(c =='-'){
//                 res = res + sign * num;
//                 num = 0;
//                 sign = -1;
//             }else if(c == '('){
//                 stack.push(res);
//                 stack.push(sign);
//                 res = 0;
//                 sign = 1;
//             }else if(c == ')'){
//                 res += sign * num;
//                 num = 0;
//                 res *= stack.top();
//                 stack.pop();
//                 res += stack.top();
//                 stack.pop();
//             }
//         }
//         if(num != '0')
//             res += num*sign;
//         return res;



//     }
// };

//dfs
class Solution{
public:
    int calculate(string s){
        queue<char> q;
        for(char c: s){
            if(c!=' '){
                q.push(c);
            }
        }
        q.push(' ');
        return helper(q);
    }
private: 
    int helper(queue<char> &q){
        int num = 0, prev = 0, sum = 0;
        char prev_operator = '+';
        while(!q.empty()){
            char c = q.front();
            q.pop();
            if(c>='0'&&c<='9'){
                num = num*10+(int)(c -'0');
            }else if(c == '('){
                num = helper(q);
            }else{
                switch(prev_operator){
                    case '+':
                        sum += prev;
                        prev = num;
                        break;
                    case '-':
                        sum += prev;
                        prev = -num;
                        break;
                    case '*':
                        prev *= num;
                        break;
                    case '/':
                        prev /= num;
                        break;
                }
                if(c == ')') break;

                prev_operator = c;
                num = 0;
            }
        }
        return prev+sum;
    }
};
int main(){
    Solution* s = new Solution();
    string str ="1+1";
    int res = s->calculate(str);
    cout<<"out put"<<res<<endl;
    
}
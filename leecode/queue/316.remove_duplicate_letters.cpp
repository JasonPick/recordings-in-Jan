#include <stack>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int res[26] = {0};
        bool visited[26] = {false};
        for(char c:s){
            res[c-'a']++;
        }
        stack<char> st;
        int i = 0;
        for (char c: s){
            i = c -'a';
            res[i]--;
            if(visited[i])
                continue;
            // current character c < character in stack, and 
            // character in stack will appear later
            // remove the character from stack
            // add current character to stack
            while(!st.empty() && c < st.top() && res[st.top()-'a'] != 0){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(c);
            visited[i] = true;

        } 
        string sb;
        while(!st.empty()){
            sb = st.top()+sb;
            st.pop();
        }
        return sb;
    }
};
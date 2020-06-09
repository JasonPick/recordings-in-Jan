#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> s;
        stringstream ss(path);
        while(getline(ss,tmp,'/')){
            if(tmp == "." || tmp == "" ) continue;
            if(tmp == ".." ){
                if (s.size() != 0)
                    s.pop_back();
            }     
                
            else s.push_back(tmp);
            
        }
        if(s.empty()) return "/";
        for(int i = 0; i<s.size(); i++){
            res = res + "/" + s[i];
        }
        return res;


    }




};
int main(){
    Solution* sol = new Solution();
    string in = "/../";
    string out = sol->simplifyPath(in);
    cout << out<<endl;
    
}
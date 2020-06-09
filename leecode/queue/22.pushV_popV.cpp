#include<iostream>
#include<vector>

class Solution{
public:

    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        //bool res = false;
        if(!pushV.size() || !popV.size()) return true;
        
        vector<int> stack;
        int j = 0;
        
        for(int item: pushV ){
            stack.push_back(item);
            while(stack.size() && stack.back() == popV[j]){
                stack.pop_back();
                j++;
            }
        }
        
        return stack.empty();
        
    }
};



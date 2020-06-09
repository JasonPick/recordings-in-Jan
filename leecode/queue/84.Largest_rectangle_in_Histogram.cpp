#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution {

public:
    int largestRectangleArea(vector<int>& heights) {
        int sz = heights.size();
        stack<int> pos;
        int res = 0;

        for (int i = 0; i <= sz;i++){

            int h = (i == sz? 0: heights[i]);

            if(pos.empty()||h >= heights[pos.top()]){
                
                pos.push(i);
                
            }else{
                int p = pos.top();
                pos.pop();
                res = max(res,heights[p]*(pos.empty()?i:i-1-pos.top()));
                i--;

            }
            

        }
        
        return res;
        
    }
};

int main(){
    Solution* sol = new Solution();
    int a[] = {2,1,5,6,2,3};
    vector<int> x(a,a+6);
    //cout << x[0];
    int s = sol->largestRectangleArea(x);
    cout<<" result: " << s <<  endl;
    return 0;
}
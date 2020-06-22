#include<iostream>
#include<vector>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int low = prices[0];
        int high = prices[0];
        int profit = 0;

        while(i<prices.size()-1) {
            while(i<prices.size()-1 && prices[i] >= prices[i+1]) {
                i++;
            }
            low = prices[i];
            while(i<prices.size()-1 && prices[i]<=prices[i+1]){
                i++;
            }
            high = prices[i];
            profit += high - low;
        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] > prices[i-1]){
                profit+= prices[i]-prices[i-1];
            }

        }
        return profit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
    }
};
// best time to buy and sell stock (leetcode 121) 
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// ----------------------------------------------------------------
// Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// ----------------------------------------------------------------

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=0; i<prices.size(); i++){
            for(int j=i; j<prices.size(); j++){
                if((prices[j]- prices[i])>ans) ans= (prices[j]- prices[i]) ;
            }
        }
        return ans;
    }
};


// ----------------------------------------------------------------
// Two Pointer Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// ----------------------------------------------------------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int maxP = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxP = max(maxP, profit);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
    }
};
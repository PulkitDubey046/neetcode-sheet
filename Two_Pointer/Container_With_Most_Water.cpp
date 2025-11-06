// Container with most water (LeetCode Problem 11)
// https://leetcode.com/problems/container-with-most-water/
// ----------------------------------------------------------------
// Approach: Two Pointer Technique
// Time Complexity: O(n)
// Space Complexity: O(1)
// ----------------------------------------------------------------

#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};


// Brute Force

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                res = max(res, min(heights[i], heights[j]) * (j - i));
            }
        }
        return res;
    }
};
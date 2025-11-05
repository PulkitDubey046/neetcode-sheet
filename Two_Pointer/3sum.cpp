// 3Sum Problem (leetCode 15)
// 📎 Link: https://leetcode.com/problems/3sum/
// ------------------------------------------------------------
// 🧠 Approach: Two Pointers
// Sort the array and use two pointers to find triplets that sum to zero.
// Time Complexity: O(n^2)
// Space Complexity: O(1) (ignoring output space)
// ------------------------------------------------------------
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return res;
    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Using Hash Set
// Sort the array and use a hash set to find pairs that sum to the negative of the current element.
// Time Complexity: O(n^2)
// Space Complexity: O(n) (for the hash set)
// ------------------------------------------------------------

#include <unordered_set>
class SolutionWithHashSet {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            unordered_set<int> seen;
            for (int j = i + 1; j < nums.size(); j++) {
                int complement = -nums[i] - nums[j];
                if (seen.count(complement)) {
                    res.push_back({nums[i], nums[j], complement});
                    while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                        j++;
                    }
                }
                seen.insert(nums[j]);
            }
        }
        return res;
    }
};
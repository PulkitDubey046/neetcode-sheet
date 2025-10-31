// 🔢 Problem: Contains Duplicate (LeetCode 217)
// 📎 Link: https://leetcode.com/problems/contains-duplicate/
//
// ------------------------------------------------------------
// 🧠 Approach 1: Sorting
// Sort the array, then check if any adjacent elements are equal.
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// ------------------------------------------------------------

#include <algorithm>
#include <vector>
#include <set>
using namespace std;

class SolutionSort {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Hash Set
// Use a set to track seen numbers.
// If a number appears twice, return true.
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------

class SolutionSet {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        for (int num : nums) {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }
};

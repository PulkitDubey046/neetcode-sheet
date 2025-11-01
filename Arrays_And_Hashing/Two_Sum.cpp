// 🔢 Problem: Two Sum (LeetCode 1)
// 📎 Link: https://leetcode.com/problems/two-sum/
//
// ------------------------------------------------------------
// 🧠 Approach 1: Brute Force
// Check every pair (i, j) to see if nums[i] + nums[j] == target.
// Time Complexity: O(n²)
// Space Complexity: O(1)
// ------------------------------------------------------------

#include <vector>
using namespace std;

class SolutionBruteForce {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Hash Map
// Use a hash map to store each number and its index.
// For each element, check if target - nums[i] exists in the map.
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------

#include <unordered_map>

class SolutionHashMap {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // number -> index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.find(complement) != seen.end()) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

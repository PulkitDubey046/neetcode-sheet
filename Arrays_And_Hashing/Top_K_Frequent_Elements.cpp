// 🔢 Problem: Top K Frequent Elements (LeetCode 347)
// 📎 Link: https://leetcode.com/problems/top-k-frequent-elements/
//
// ------------------------------------------------------------
// 🧠 Approach 1: Sorting + Counting
// Sort array, count frequency of each number, then sort by frequency.
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// ------------------------------------------------------------

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class SolutionSort {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> freq; // {num, count}

        int count = 1;
        for (int i = 1; i <= nums.size(); i++) {
            if (i < (int)nums.size() && nums[i] == nums[i - 1])
                count++;
            else {
                freq.push_back(make_pair(nums[i - 1], count));
                count = 1;
            }
        }

        sort(freq.begin(), freq.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });

        vector<int> ans;
        for (int i = 0; i < k && i < (int)freq.size(); i++)
            ans.push_back(freq[i].first);

        return ans;
    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Hash Map + Max Heap
// Count frequencies using a hash map, then use a max heap to extract top K.
// Time Complexity: O(n log k)
// Space Complexity: O(n)
// ------------------------------------------------------------

class SolutionHeap {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums)
            freq[n]++;

        priority_queue<pair<int, int>> maxHeap;
        for (unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
            maxHeap.push(make_pair(it->second, it->first));
        }

        vector<int> ans;
        while (k-- > 0 && !maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return ans;
    }
};

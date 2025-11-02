// Group Anagrams - LeetCode 49 
// 📎 Link: https://leetcode.com/problems/group-anagrams/
// ------------------------------------------------------------
// 🧠 Approach: Hash Map with Sorted Strings
// Use a hash map where the key is the sorted version of the string.
// Group all strings that share the same sorted key.
// Time Complexity: O(n * k log k) where n is number of strings and k is max length of a string
// Space Complexity: O(n * k) for storing the grouped anagrams
//------------------------------------------------------------

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (auto s : strs) {
        string key = s;           // copy the string
        sort(key.begin(), key.end()); // sort to get canonical form
        mp[key].push_back(s);     // group by sorted key
    }

    vector<vector<string>> ans;
    for (auto &pair : mp) {
        ans.push_back(pair.second);
    }

    return ans;
    }
};

// 🔢 Problem: Valid Anagram (LeetCode 242)
// 📎 Link: https://leetcode.com/problems/valid-anagram/
//
// ------------------------------------------------------------
// 🧠 Approach 1: Sorting
// Sort both strings and compare them directly.
// Time Complexity: O(n log n)
// Space Complexity: O(1)
// ------------------------------------------------------------

#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Frequency Count
// Count the frequency of each character in both strings and compare.
// Time Complexity: O(n)
// Space Complexity: O(1) (since the character set is fixed)
// ------------------------------------------------------------
#include <string>
#include <vector>
using namespace std;
class SolutionFreq {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        for (char c : t) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) return false;
        }
        return true;
    }
};
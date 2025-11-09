// Longest Substring Without Repeating Characters (LeetCode Problem 3)
// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// ----------------------------------------------------------------
// Given a string s, find the length of the longest substring without repeating characters.
// Approach: Brute Force
// Time Complexity: O(n*n)
// Space Complexity: O(1)
// ----------------------------------------------------------------

#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            unordered_set<char> charSet;
            for (int j = i; j < s.size(); j++) {
                if (charSet.find(s[j]) != charSet.end()) {
                    break;
                }
                charSet.insert(s[j]);
            }
            res = max(res, (int)charSet.size());
        }
        return res;
    }
};


// ----------------------------------------------------------------
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(min(m, n)) where m is the size of the character set
// ----------------------------------------------------------------

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            res = max(res, r - l + 1);
        }
        return res;
    }
};
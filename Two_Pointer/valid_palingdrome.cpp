// Problem: Valid Palindrome (LeetCode 125)
// 📎 Link: https://leetcode.com/problems/valid-palindrome/
//
// ------------------------------------------------------------
// 🧠 Approach 1: Two Pointers
// Use two pointers to compare characters from both ends of the string.
// Ignore non-alphanumeric characters and case.
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        
        // Build a filtered lowercase string with only letters and digits
        for (char ch : s) {
            if (isalnum(ch)) {
                temp += tolower(ch);
            }
        }

        int left = 0, right = temp.size() - 1;
        while (left < right) {
            if (temp[left] != temp[right])
                return false;
            left++;
            right--;
        }

        return true;

    }
};

// ------------------------------------------------------------
// 🧠 Approach 2: Two Pointers with In-Place Check
// Use two pointers to compare characters from both ends of the string.
// Ignore non-alphanumeric characters and case, checking in-place.
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
class SolutionInPlace {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while (left < right) {
            // Move left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) left++;
            // Move right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) right--;

            // Compare characters in lowercase
            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
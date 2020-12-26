#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
// 
// Example 1:
// 
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example 2:
// 
// Input: "cbbd"
// Output: "bb"

class DPSolution {
public:
    // 思路：动态规划，https://blog.csdn.net/shineboyxxb/article/details/52079360
    // 设dp[i][j]表示子串s[i]~s[j]是否为回文串，则状态转移方程有
    // dp[i][j] = true if i == j
    // dp[i][j] = (s[i] == s[j]) if j - i == 1
    // dp[i][j] = (dp[i + 1][j - 1]) && (s[i] == s[j])
    // 根据状态转移方程，我们知道可以利用已有的回文串检测新的子串
    string longestPalindrome(string s) {
        const int sLength = s.length();
        if (sLength == 0) {
            return s;
        }
        int start = 0;
        int maxLength = 0;
        bool dp[sLength][sLength] = {false};
        int i, j;
        for (j = 0; j < sLength; ++j) {
            for (i = 0; i <= j; ++i) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (j - i == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (dp[i + 1][j - 1]) && (s[i] == s[j]);
                }
                // update the status of start and maxLength
                if (dp[i][j] == true && (j - i + 1) > maxLength) {
                    start = i;
                    maxLength = j - i + 1;
                }
            }
        }
        return s.substr(start, maxLength);
    }
};

class MySolution {
public:
    // 找到s中最长的回文串
    // Note: this is a brute-force solution
    // TODO: find a faster solution, for example, reuse the palindrome to check new substring
    // TODO: find why heap overflow in leetcode playground with testcase "vommleztyrbrnoij"
    // Note: it's time to review preparing the exam of computer architecture
    string longestPalindrome(string s) {
        int sLength = s.length();
        if (sLength <= 0) {
            return s;
        }
        string ans_str(1, s[0]);
        int i, j, k, q;
        for (i = 0; i < sLength; ++i) {
            j = sLength - 1;
            while (s[i] != s[j] && j >= i) {
                // printf("i = %d\tj = %d\n", i, j);
                --j;
            }
            if (j < i) {
                continue;
            }
            k = i + 1;
            q = j - 1;
            while (s[k] == s[q] && k <= q) {
                // printf("k = %d\tq = %d\n", k, q);
                ++k;
                --q;
            }
            // printf("i = %d\tj = %d\tk = %d\tq = %d\n", i, j, k, q);
            if (k > q && (j - i + 1) > ans_str.length()) {
                ans_str.assign(s.substr(i, j - i + 1));
            }
        }
        return ans_str;
    }
};

class Solution {
public:
    // brute-force -- MySolution
    // dynamic programming -- DpSolution
    // TODO: manacher algorithm for O(n) time complexity
    string longestPalindrome(string s) {
        DPSolution dpSln;
        MySolution mySln;
        return dpSln.longestPalindrome(s);
    }
};

int main(void) {
    Solution sln;
    std::string s1 = "babad";
    std::string s2 = "cbbd";
    std::string s3 = "vommleztyrbrnoij";
    std::cout << sln.longestPalindrome(s1) << std::endl;
    std::cout << sln.longestPalindrome(s2) << std::endl;
    std::cout << sln.longestPalindrome(s3) << std::endl;
    return 0;
}
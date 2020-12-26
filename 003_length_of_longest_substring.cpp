#include <iostream>
#include <vector>
#include <string>
#include <string.h> // for memset
#include <assert.h>
using namespace std;

// Given a string, find the length of the longest substring without repeating characters.
// 
// Example 1:
// 
// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:
// 
// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:
// 
// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution {
public:
    // TODO: find a faster solution
    // 思路：
    // 滑动窗口，
    // 最右边扫描到的字符如果在窗口中出现过，
    // 则窗口左端直接跳转到该字符最后出现的地方即可,
    // 因此需要记录每一个字符最后出现的位置location和窗口最左端left.
    int lengthOfLongestSubstring_sliding_window(string s) {
        int ans = 0;
        int i = 0;
        int left = -1;
        vector<int> location(512, -1);
        int strLength = s.length();
        for (i = 0; i < strLength; ++i) {
            left = std::max(left, location[s[i]]);
            location[s[i]] = i; // location数组记录字符最后出现的位置i
            ans = std::max(ans, i - left);  // 滑动窗口长度i - left即为当前子串大小
        }
        return ans;
    }
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int ans = 0;
        const unsigned int num = 512;
        int isRepeated[num];
        int strLength = s.length();
        for (i = 0; i < strLength; ++i) {   // 遍历以每一个元素开头的字符串
            memset(isRepeated, 0, sizeof(isRepeated));
            assert(isRepeated[20] == 0);
            int partLength = 0;
            for (j = i; j < strLength; ++j) {
                if (isRepeated[s[j]] == 0) {
                    partLength++;
                    isRepeated[s[j]]++;
                } else {    // 出现重复的character，退出本轮扫描
                    break;
                }
                ans = std::max(ans, partLength);
            }
        }
        return ans;
    }
};

int main(void) {
    Solution sln;
    std::string s1 = "abcabcbb";
    std::string s2 = "bbbbb";
    std::string s3 = "pwwkew";
    assert(sln.lengthOfLongestSubstring(s1) == 3);
    assert(sln.lengthOfLongestSubstring(s2) == 1);
    assert(sln.lengthOfLongestSubstring(s3) == 3);
    return 0;
}
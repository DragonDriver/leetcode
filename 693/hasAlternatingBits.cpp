#include <iostream>
#include <cstdlib>
#include <assert.h>
using namespace std;

// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
// 
// Example 1:
// Input: 5
// Output: True
// Explanation:
// The binary representation of 5 is: 101
// Example 2:
// Input: 7
// Output: False
// Explanation:
// The binary representation of 7 is: 111.
// Example 3:
// Input: 11
// Output: False
// Explanation:
// The binary representation of 11 is: 1011.
// Example 4:
// Input: 10
// Output: True
// Explanation:
// The binary representation of 10 is: 1010.


class Solution {
public:
    // 思路：简单位运算即可
    bool hasAlternatingBits(int n) {
        if (n < 0) { // 负数先取反，避免出现算数右移
            n = ~n;
        }
        int prev_bit = n & 1;
        int cur_bit;
        while (n > 0) {
            cur_bit = (n >> 1) & 1;
            if (cur_bit == prev_bit) {
                return false;
            }
            prev_bit = cur_bit;
            n = n >> 1;
        }
        return true;
    }
};

int main(void) {
    Solution sln;
    assert(sln.hasAlternatingBits(5) == true);
    assert(sln.hasAlternatingBits(7) == false);
    assert(sln.hasAlternatingBits(10) == true);
    assert(sln.hasAlternatingBits(11) == false);
    return 0;
}
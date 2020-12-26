#include <iostream>
#include <vector>
#include <cassert>
#include <cstdint>  // for int32_t

class Solution {
public:
    // 本质：进制转换问题，C程序员的基本功，base改为16和2应该也能应对，可以参考itoa实现
    // 但是LeetCode上面要求处理overflow，给出的答案很愚蠢，个人觉得也没有意义
    int32_t reverse(int32_t x) {
        bool sign = (x > 0);
        if (!sign) x = -x;
        int32_t res = 0;
        while (x != 0) {
            res = res * 10 + (x % 10);
            x /= 10;
        }
        if (!sign) res = -res;
        return res;
    }
};

int
main(int argc, char* argv[]) {
    Solution sln;
    int32_t example1 = 123;
    int32_t example2 = -123;
    assert(sln.reverse(example1) == 321);
    assert(sln.reverse(example2) == -321);
    return 0;
}
#include <iostream>
#include <vector>
#include <assert.h>

using std::vector;

class Solution {
public:
    // 双指针法，两个指针分别指向两端，指针只有从短板移动才能更新最大面积
    int double_pointer(vector<int>& height) {
        int begin = 0;
        int end = height.size() - 1;
        int res = 0;
        while (begin != end) {
            int h_begin = height[begin];
            int h_end = height[end];
            int h_min = std::min(h_begin, h_end);
            int area = h_min * (end - begin);
            res = std::max(area, res);
            if (h_end < h_begin) {
                end--;
            } else {
                begin++;
            }
        }
        return res;
    }
    // https://leetcode-cn.com/problems/container-with-most-water/
    int maxArea(vector<int>& height) {
        return double_pointer(height);
    }
};

int
main(void) {
    Solution sln;

    vector<int> case1{1,8,6,2,5,4,8,3,7};
    vector<int> case2{1,1};
    vector<int> case3{4,3,2,1,4};
    vector<int> case4{1,2,1};

    assert(sln.maxArea(case1) == 49);
    assert(sln.maxArea(case2) == 1);
    assert(sln.maxArea(case3) == 16);
    assert(sln.maxArea(case4) == 2);
}

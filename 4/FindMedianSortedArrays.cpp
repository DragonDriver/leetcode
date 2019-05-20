#include <iostream>
#include <algorithm>    // for sort
#include <stdlib.h> // for rand() % 100()
#include <time.h>
#include <assert.h>
#include <vector>
using namespace std;

// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// 
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// 
// You may assume nums1 and nums2 cannot be both empty.
// 
// Example 1:
// 
// nums1 = [1, 3]
// nums2 = [2]
// 
// The median is 2.0
// Example 2:
// 
// nums1 = [1, 2]
// nums2 = [3, 4]
// 
// The median is (2 + 3)/2 = 2.5

class Solution {
public:
    // 找到两个排序数组的中位数
    // 时间复杂度：O(size(nums1) + size(nums2))
    // 思路：归并排序
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int allSize = size1 + size2;
        double ans;
        std::vector<int> allnum(allSize);
        int i, j, k = 0;
        for (i = 0, j = 0; i < size1 && j < size2; ++k) {
            if (nums1[i] < nums2[j]) {
                allnum[k] = nums1[i];
                ++i;
            } else {
                allnum[k] = nums2[j];
                ++j;
            }
        }
        for (; i < size1; ++i) {
            allnum[k] = nums1[i];
            ++k;
        }
        for (; j < size2; ++j) {
            allnum[k] = nums2[j];
            ++k;
        }
        if (allSize % 2 == 0) {
            ans = (double)(allnum[allSize / 2 - 1] + allnum[allSize / 2]) / (2.0);
        } else {
            ans = (double)(allnum[allSize / 2]);
        }
        return ans;
    }
};

void printVector(const vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if ((i + 1) % 10 == 0) {
            printf("%d\n", nums[i]);
        } else {
            printf("%d\t", nums[i]);
        }
        i++;
    }
    printf("\n");
}

int main(void) {
    srand(time(NULL));
    Solution sln;
    std::vector<int> nums1;
    std::vector<int> nums2(1, 1);
    printf("%lf\n", sln.findMedianSortedArrays(nums1, nums2));
    return 0;
}

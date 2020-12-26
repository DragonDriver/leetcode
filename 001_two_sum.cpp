#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ivec_rtn(2);

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    ivec_rtn[0] = i;
                    ivec_rtn[1] = j;
                }
            }
        }
        return ivec_rtn;
    }
};

int main(void) {
    Solution sln;
    int myints[] = {2, 7, 11, 15};
    vector<int> ivec1(myints, myints + sizeof(myints) / sizeof(int));
    vector<int> ans = sln.twoSum(ivec1, 9);
    assert((ans[0] == 0) && (ans[1] == 1));
    return 0;
}
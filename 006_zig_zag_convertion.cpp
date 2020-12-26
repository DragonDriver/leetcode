#include <cassert>
#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    // PAYPALISHIRING   (numRows = 3)
    // 01210121012101
    // DragonDriver     (numRows = 4)
    // 012321012321
    std::string convert(std::string s, int numRows) {
        if (numRows <= 1) return s;
        std::string res;
        int s_len = s.size();
        int* row_location = new int[s_len];
        int cur_row_loc = 0;
        int direction = 1;  // 1 means down which row location increases
        for (int i = 0; i < s_len; ++i) {
            row_location[i] = cur_row_loc;
            cur_row_loc += direction;
            if (cur_row_loc >= numRows - 1) direction = -1;
            if (cur_row_loc <= 0) direction = 1;
        }
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < s_len; ++j) {
                if (row_location[j] == i) {
                    res += s[j];
                }
            }
        }
        assert(res.size() == s.size());
        return res;
    }

    std::string vector_store_convert(std::string s, int numRows) {
        if (numRows <= 1) return s;
        int s_len = s.size();
        std::string res;
        std::vector<std::string> rows_str(numRows, std::string(""));
        int cur_row_loc = 0;
        int direction = 1;  // 1 means down which row location increases
        for (int i = 0; i < s_len; ++i) {
            rows_str[cur_row_loc] += s[i];
            cur_row_loc += direction;
            if (cur_row_loc >= numRows - 1) direction = -1;
            if (cur_row_loc <= 0) direction = 1;
        }
        for (int i = 0; i < numRows; ++i) {
            res += rows_str[i];
        }
        assert(res.size() == s.size());
        return res;
    }
};

int
main(int argc, char* argv[]) {
    Solution sln;
    std::string example = std::string("PAYPALISHIRING");
    std::string zig_str = sln.convert(example, 3);
    std::string another_zig_str = sln.vector_store_convert(example, 3);
    assert(zig_str == std::string("PAHNAPLSIIGYIR"));
    assert(zig_str == another_zig_str);
    return 0;
}
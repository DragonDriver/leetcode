#include <cassert>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::vector<int> reminders;
        while (x != 0) {
            reminders.push_back(x % 10);
            x /= 10;
        }
        int i, j;
        for (i = 0, j = reminders.size() - 1; i < j; ++i, --j) {
            if (reminders[i] != reminders[j]) return false;
        }
        return true;
    }

    // 标准答案：原地翻转
    bool isPalindrome_standard(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reverse_x = 0;
        while (reverse_x < x) {
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }

        return (reverse_x == x) || (reverse_x / 10 == x);
    }
};

int
main(int argc, char* argv[]) {
    Solution sln;
    assert(sln.isPalindrome(121));
    assert(sln.isPalindrome(121) == sln.isPalindrome_standard(121));
    assert(!sln.isPalindrome(-121));
    assert(sln.isPalindrome(-121) == sln.isPalindrome_standard(-121));
    assert(!sln.isPalindrome(10));
    assert(sln.isPalindrome(10) == sln.isPalindrome_standard(10));
    return 0;
}
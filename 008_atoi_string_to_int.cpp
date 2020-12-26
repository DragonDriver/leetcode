#include <string>
#include <iostream>

class Solution
{
public:
    int
    myAtoi(std::string str) {
        int s_len = str.length();
        if (s_len <= 0) return 0;

        int sign = 1;
        char zero = '0';
        char nine = '0' + 9;

        int res = 0;

        int start = 0;
        while (str[start] == ' ') ++start;
        if (str[start] == '-' || str[start] == '+') {
            if (str[start] == '-') sign = -1;
            ++start;
        }

        if (str[start] < zero || str[start] > nine) return 0;

        while (start < s_len) {
            if (str[start] < zero || str[start] > nine) return res;

            int digit = str[start] - '0';

            // 7 = (INT_MAX - (INT_MAX / 10) * 10)
            // 8 = ((INT_MIN / 10) * 10 - INT_MIN)
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && digit > 7)) return INT_MAX;
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && digit > 8)) return INT_MIN;

            res = res * 10 + sign * digit;
            ++start;
        }
        return res;
    }
};

int
main(int argc, char* argv[]) {
    Solution sln;
    std::string str1 = "42";
    std::string str2 = "   -42";
    std::string str3 = "4193 with words";
    std::string str4 = "words and 987";
    std::string str5 = "-91283472332";

    std::cout << "str1: " << sln.myAtoi(str1) << std::endl;
    std::cout << "str2: " << sln.myAtoi(str2) << std::endl;
    std::cout << "str3: " << sln.myAtoi(str3) << std::endl;
    std::cout << "str4: " << sln.myAtoi(str4) << std::endl;
    std::cout << "str5: " << sln.myAtoi(str5) << std::endl;

    return 0;
}

#include <vector>
#include <string>

class Solution {
    public:
        std::string
        intToRoman(int num) {
            static std::vector<int> divs{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
            static std::vector<std::string> symbols{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
            assert(divs.size() == symbols.size());
            int len = divs.size();

            std::string ans;
            int divisor = num;
            for (int i = 0; i < len; i++) {
                int quotient = divisor / divs[i];
                divisor = divisor % divs[i];
                for (int j = 0; j < quotient; j++) {
                    ans += symbols[i];
                }
            }

            return ans;
        }
};

int
main(int argc, char* argv[]) {
    Solution sln;

    assert(sln.intToRoman(3) == "III");
    assert(sln.intToRoman(4) == "IV");
    assert(sln.intToRoman(9) == "IX");
    assert(sln.intToRoman(58) == "LVIII");
    assert(sln.intToRoman(1994) == "MCMXCIV");
}

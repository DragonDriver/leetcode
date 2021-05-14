#include <vector>

class Solution {
public:
    const int MODULO = 1000000007;

    int numWays(int steps, int arrLen) {
        int maxColumn = std::min(arrLen - 1, steps);
        std::vector<std::vector<int> > dp(steps + 1, std::vector<int>(maxColumn + 1));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxColumn; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MODULO;
                }
                if (j + 1 <= maxColumn) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MODULO;
                }
            }
        }
        return dp[steps][0];
    }
};

int
main(int argc, char* argv[]) {
    Solution sln;
    assert(sln.numWays(3, 2) == 4);
    assert(sln.numWays(2, 4) == 2);
    assert(sln.numWays(4, 2) == 8);

    return 0;
}


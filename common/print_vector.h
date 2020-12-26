#include <vector>

void
print_vector(const std::vector<int>& nums) {
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

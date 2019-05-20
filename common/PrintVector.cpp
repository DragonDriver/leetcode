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
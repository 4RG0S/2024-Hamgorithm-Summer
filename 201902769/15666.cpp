#include <iostream>
#include <vector>
#include <algorithm>

void recursion(int depth, int start, int m, std::vector<int>& v, std::vector<int>& nums) {

    if (depth == m) {
        for (int i=0;i<m;i++) {
            std::cout << v[i] << " ";
        }
        std::cout << "\n";
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        v.push_back(nums[i]);
        recursion(depth + 1, i, m, v, nums);
        v.pop_back();
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());


    std::vector<int> v;
    recursion(0, 0, m, v, nums);

    return 0;
}

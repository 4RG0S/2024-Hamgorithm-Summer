#include <iostream>
#include <algorithm>

int main(void) {
    int n;
    std::cin >> n;

    int a[6];
    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
    }

    int sum_of_two_sides[12] = {a[0] + a[1], a[0] + a[2], a[0] + a[3], a[0] + a[4], a[5] + a[1], a[5] + a[2], a[5] + a[3], a[5] + a[4],  a[1] + a[2], a[2] + a[4], a[4] + a[3], a[3] + a[1]};


    int min_one_side = *std::min_element(a, a + 6);

    int min_two_sides = *std::min_element(sum_of_two_sides, sum_of_two_sides+12);

    int min_three_sides = a[0] + a[1] + a[2];
    min_three_sides = std::min(min_three_sides, a[0] + a[1] + a[3]);
    min_three_sides = std::min(min_three_sides, a[0] + a[4] + a[2]);
    min_three_sides = std::min(min_three_sides, a[0] + a[4] + a[3]);
    min_three_sides = std::min(min_three_sides, a[5] + a[1] + a[2]);
    min_three_sides = std::min(min_three_sides, a[5] + a[1] + a[3]);
    min_three_sides = std::min(min_three_sides, a[5] + a[4] + a[2]);
    min_three_sides = std::min(min_three_sides, a[5] + a[4] + a[3]);

    if (n == 1) {
        int max_val = *std::max_element(a, a + 6);
        int total_sum = 0;
        for (int i = 0; i < 6; i++) {
            total_sum += a[i];
        }
        std::cout << total_sum - max_val << std::endl;
    } else {
        long long answer = 0;
        answer += static_cast<long long> (min_three_sides) * 4; // 3개의 면이 돌출된 블록 (꼭지점) 4개
        answer += static_cast<long long> (min_two_sides) * (4 * (n - 1) + 4 * (n - 2)); // 2개의 면이 돌출된 블록 4(n-1) + 4(n-2)
        answer += static_cast<long long> (min_one_side) * (n - 2) * (5 * n - 6); // 1개의 면이 돌출된 블록


        std::cout << answer << std::endl;
    }

    return 0;
}

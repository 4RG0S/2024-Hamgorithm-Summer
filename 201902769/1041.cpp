#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> A(n), B(n), C(n), D(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    std::unordered_map<int, int> sumAB;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = A[i] + B[j];
            sumAB[sum]++;
        }
    }

    long long count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int sum = -(C[i] + D[j]);
            if (sumAB.find(sum) != sumAB.end()) {
                count += sumAB[sum];
            }
        }
    }

    std::cout << count << std::endl;
    return 0;
}

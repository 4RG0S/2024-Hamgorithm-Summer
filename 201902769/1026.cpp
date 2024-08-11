#include <iostream>
#include <algorithm>

int main(void) {
    int n;
    std::cin >> n;

    int a[50];
    int b[50];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    std::sort(a, a+n);
    std::sort(b, b+n);

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += a[i] * b[n - i + - 1];
    }
    std::cout << answer;
}
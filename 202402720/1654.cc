#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int K, N;
    cin >> K >> N;

    long long min = 0;
    long long max = 0;

    vector<int> lan(K);
    for (int i = 0; i < K; i++) {
        cin >> lan[i];
        if (max < lan[i]) {
            max = lan[i];
        }
    }

    while (min <= max) {
        long long mid = (min + max) / 2;
        if (mid == 0)
            mid = 1;

        int count = 0;

        for (int i = 0; i < lan.size(); i++) {
            count += (lan[i] / mid);
        }

        if (count < N) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    cout << min - 1 << '\n';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int K;
    cin >> K;

    stack<int> s;

    while (K > 0) {
        int num;
        cin >> num;

        if (num == 0) {
            s.pop();
        } else {
            s.push(num);
        }
        K--;
    }

    int result = 0;

    while (!s.empty()) {
        result += s.top();
        s.pop();
    }

    cout << result << endl;

    return 0;
}
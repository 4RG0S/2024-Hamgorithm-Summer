#include <string>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C;
    cin >> A >> B >> C;
    int result = A * B * C;
    int count[10];
    fill(count, count + 10, 0);
    string text;
    text = to_string(result);
    for (char ch : text) {
      count[ch - '0']++;
    }
    for (int iter : count) {
      cout << iter << '\n';
    }

    return 0;
}

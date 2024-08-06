#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
      int L, S, R;
      cin >> L >> R >> S;

      int result = min((S - L) * 2 + 1, (R - S) * 2);
      if (L == S || S == R) {
        cout << 1 << '\n';
      } else {
        cout << result << '\n';
      }
    }

    return 0;
}

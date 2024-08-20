#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
      stack<char> S;
      bool is_error = false;
      string line;
      cin >> line;

      for (char ch : line) {
        if (ch == '(') {
          S.push(ch);
        } else {
          if (S.size() == 0 || S.top() != '(') {
            is_error = true;
            break;
          } else {
            S.pop();
          }
        }
      }
      cout << ((S.size() == 0 && !is_error) ? "YES" : "NO") << '\n';
    }

    return 0;
}

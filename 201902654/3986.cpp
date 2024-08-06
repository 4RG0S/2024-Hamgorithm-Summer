#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int result = 0;
    for (int i=0;i<N;i++) {
      stack<char> S;
      string line;
      cin >> line;
      for (char ch : line) {
        if (S.size() > 0 && S.top() == ch) {
          S.pop();
        } else {
          S.push(ch);
        }
      }
      if (S.size() == 0) {
        result++;
      }
    }
    cout << result;
    return 0;
}

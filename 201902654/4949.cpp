#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    while (true) {
      stack<char> S;
      bool is_error = false;
      getline(cin, line);
      if (line == ".") {
        break;
      }
      for (char ch : line) {
        if (ch == '(') {
          S.push('(');
        }
        if (ch == ')') {
          if (S.size() == 0 || S.top() != '(') {
            is_error = true;
            break;
          } else {
            S.pop();
          }
        }
        if (ch == '[') {
          S.push('[');
        }
        if (ch == ']') {
          if (S.size() == 0 || S.top() != '[') {
            is_error = true;
            break;
          } else {
            S.pop();
          }
        }
      }
      cout << ((S.size() == 0 && !is_error) ? "yes" : "no") << '\n';

    }
    return 0;
}

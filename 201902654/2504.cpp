#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    cin >> line;
    stack<char> S;
    int temp = 1;
    int result = 0;
    bool is_error = false;
    for (int i=0;i<line.size();i++) {
      char ch = line.at(i);
      if (ch == '(') {
        S.push(ch);
        temp *= 2;
      }
      if (ch == '[') {
        S.push(ch);
        temp *= 3;
      }
      if (ch == ')') {
        if (S.empty()) {
          is_error = true;
          break;
        } else if (S.top() == '(') {
          if (line.at(i-1) == '(') {
            result += temp;
          }
          temp /= 2;
          S.pop();
        }
      }
      if (ch == ']') {
        if (S.empty()) {
          is_error = true;
          break;
        } else if (S.top() == '[') {
          if (line.at(i-1) == '[') {
            result += temp;
          }
          temp /= 3;
          S.pop();
        }
      }
    }
    cout << ((!S.empty() || is_error) ? 0 : result);

    return 0;
}

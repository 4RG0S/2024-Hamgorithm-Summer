#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string line;
    stack<char> S;
    long result = 0;
    cin >> line;
    for (int i=0;i<line.size();i++) {
      char ch = line.at(i);
      if (ch == '(') {
        S.push(ch);
      } else {
        if (line.at(i - 1) == '(') {
          S.pop();
          result += S.size();
        } else {
          S.pop();
          result++;
        }
      }
    }
    cout << result;

    return 0;
}

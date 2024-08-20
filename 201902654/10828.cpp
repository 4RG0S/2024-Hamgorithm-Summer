#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    stack<int> stack;
    cin >> N;
    for (int i=0;i<N;i++) {
      string command;
      cin >> command;
      if (command == "push") {
        int val;
        cin >> val;
        stack.push(val);
      } else if (command == "pop") {
        if (stack.empty()) {
          cout << -1 << '\n';
        } else {
          cout << stack.top() << '\n';
          stack.pop();
        }
      } else if (command == "size") {
        cout << stack.size() << '\n';
      } else if (command == "empty") {
        if (stack.empty()) {
          cout << 1 << '\n';
        } else {
          cout << 0 << '\n';
        }
      } else {
        if (stack.empty()) {
          cout << -1 << '\n';
        } else {
          cout << stack.top() << '\n';
        }
      }
    }

    return 0;
}

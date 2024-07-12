#include <string>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int K;
    long result = 0;
    stack<int> stack;
    cin >> K;

    for (int i=0;i<K;i++) {
      int input;
      cin >> input;

      if (input == 0) {
        stack.pop();
      } else {
        stack.push(input);
      }
    }

    while (!stack.empty()) {
      result = result + stack.top();
      stack.pop();
    }

    cout << result;

    return 0;
}

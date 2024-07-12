#include <string>
#include <stack>
#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int max = 0;
    stack<int> stack;
    int n;
    cin >> n;
    int arr[n];
    list<char> result;
    for (int i=0;i<n;i++) {
      int input;
      cin >> input;
      arr[i] = input;
    }
    for (int i=0;i<n;i++) {
      int value = arr[i];
      if (value > max) {
        for (int j=0;j<value - max;j++) {
          stack.push(j + max + 1);
          result.push_back('+');
        }
        max = value;
        stack.pop();
        result.push_back('-');
      } else if (!stack.empty() && stack.top() == value) {
        stack.pop();
        result.push_back('-');
      } else {
        cout << "NO";
        return 0;
      }
    }
    for (char iter : result) {
      cout << iter << '\n';
    }

    return 0;
}

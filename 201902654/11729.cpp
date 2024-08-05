#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<stack<int> > stacks;
int result = 0;

void move(int n, int from, int to, int middle, bool is_print) {
  if (n == stacks[from].top()) {
    result++;
    stacks[to].push(stacks[from].top());
    stacks[from].pop();
    if (is_print) {
      cout << from + 1 << ' ' << to + 1 << '\n';
    }
  } else {
    move(n-1, from, middle, to, is_print);
    result++;
    stacks[to].push(stacks[from].top());
    stacks[from].pop();
    if (is_print) {
      cout << from + 1 << ' ' << to + 1 << '\n';
    }
    move(n-1, middle, to, from, is_print);
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stacks.push_back(stack<int>());
    stacks.push_back(stack<int>());
    stacks.push_back(stack<int>());
    int N;
    cin >> N;
    for (int i=N;i>0;i--) {
      stacks[0].push(i);
    }
    move(N, 0, 2, 1, false);
    for (int i=N;i>0;i--) {
      stacks[0].push(i);
    }
    stacks[2] = stack<int>();
    cout << result << '\n';
    move(N, 0, 2, 1, true);

    return 0;
}

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
int F, S, G, U, D;
int button_count[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> F >> S >> G >> U >> D;
    fill(button_count, button_count+F+1, -1);
    queue<int> Q;
    button_count[S] = 0;
    Q.push(S);
    while (!Q.empty()) {
      int top = Q.front(); Q.pop();
      if (top + U <= F && button_count[top + U] == -1) {
        button_count[top + U] = button_count[top] + 1;
        Q.push(top + U);
      }
      if (top - D > 0 && button_count[top - D] == -1) {
        button_count[top - D] = button_count[top] + 1;
        Q.push(top - D);
      }
    }
    if (button_count[G] == -1) {
      cout << "use the stairs";
    } else {
      cout << button_count[G];
    }

    return 0;
}

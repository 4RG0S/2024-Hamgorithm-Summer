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
int min_time[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(min_time, min_time+100001, -1);

    int N, K;
    queue<int> Q;
    cin >> N >> K;
    min_time[N] = 0;
    Q.push(N);
    while (!Q.empty()) {
      int top = Q.front(); Q.pop();
      if (top == K) {
        break;
      }
      if (top - 1 >= 0 && min_time[top - 1] == -1) {
        min_time[top - 1] = min_time[top] + 1;
        Q.push(top - 1);
      }
      if (top + 1 < 100001 && min_time[top + 1] == -1) {
        min_time[top + 1] = min_time[top] + 1;
        Q.push(top + 1);
      }
      if (top * 2 < 100001 && min_time[top * 2] == -1) {
        min_time[top * 2] = min_time[top] + 1;
        Q.push(top * 2);
      }
    }
    cout << min_time[K];

    return 0;
}

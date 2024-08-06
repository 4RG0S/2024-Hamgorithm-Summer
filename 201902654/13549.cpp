#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;
#define X first
#define Y second
int N, K;
int min_time[200001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(min_time, min_time + 200001, __INT_MAX__);
    cin >> N >> K;
    queue<pair<int, int> > Q;
    min_time[N] = 0;
    Q.push(make_pair(N, 0));
    while (!Q.empty()) {
      pair<int, int> top = Q.front(); Q.pop();
      if (top.X - 1 >= 0 && min_time[top.X - 1] > top.Y + 1) {
        min_time[top.X - 1] = top.Y + 1;
        Q.push(make_pair(top.X - 1, top.Y + 1));
      }
      if (top.X + 1 < 200001 && min_time[top.X + 1] > top.Y + 1) {
        min_time[top.X + 1] = top.Y + 1;
        Q.push(make_pair(top.X + 1, top.Y + 1));
      }
      if (top.X * 2 < 200001 && min_time[top.X * 2] > top.Y) {
        min_time[top.X * 2] = top.Y;
        Q.push(make_pair(top.X * 2, top.Y));
      }
    }
    cout << min_time[K];

    return 0;
}

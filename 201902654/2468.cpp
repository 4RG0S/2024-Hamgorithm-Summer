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
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int heights[101][101];
bool is_visit[101][101];
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        cin >> heights[y][x];
      }
    }
    int result = INT_MIN;
    for (int rain=0;rain<101;rain++) {
      int count = 0;
      for (int i=0;i<N;i++) fill(is_visit[i], is_visit[i]+N+1, false);
      for (int y=0;y<N;y++) {
        for (int x=0;x<N;x++) {
          if (!is_visit[y][x] && heights[y][x] > rain) {
            count++;
            queue<pair<int, int> > Q;
            Q.push(make_pair(x, y));
            is_visit[y][x] = true;
            while (!Q.empty()) {
              pair<int, int> top = Q.front(); Q.pop();
              for (int i=0;i<4;i++) {
                int nx = top.X + dx[i];
                int ny = top.Y + dy[i];
                if (0 <= nx && nx < N && 0 <= ny && ny < N && !is_visit[ny][nx] && heights[ny][nx] > rain) {
                  is_visit[ny][nx] = true;
                  Q.push(make_pair(nx, ny));
                }
              }
            }
          }
        }
      }
      result = max(result, count);
    }
    cout << result;
    return 0;
}

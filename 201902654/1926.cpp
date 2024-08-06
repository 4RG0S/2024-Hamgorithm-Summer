#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define X first
#define Y second

int board[501][501];
bool is_visit[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int count_result = 0;
    int area_result = 0;
    queue<pair<int, int> > Q;
    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        cin >> board[i][j];
      }
    }

    for (int i=0;i<n;i++) {
      for (int j=0;j<m;j++) {
        if (board[i][j] == 1 && !is_visit[i][j]) {
          count_result++;
          int area = 0;
          Q.push(make_pair(j, i));
          is_visit[i][j] = true;
          while (!Q.empty()) {
            area++;
            pair<int, int> top = Q.front(); Q.pop();
            for (int k=0;k<4;k++) {
              int nx = top.X + dx[k];
              int ny = top.Y + dy[k];
              if (0 <= nx && nx < m && 0 <= ny && ny < n && board[ny][nx] == 1 && !is_visit[ny][nx]) {
                is_visit[ny][nx] = true;
                Q.push(make_pair(nx, ny));
              }
            }
          }
          area_result = max(area_result, area);
        }
      }
    }
    cout << count_result << '\n' << area_result;

    return 0;
}

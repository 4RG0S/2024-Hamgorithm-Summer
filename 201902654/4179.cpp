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
int board[1001][1001];
int fire_time[1001][1001];
int j_time[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0;i<1001;i++) {
      fill(fire_time[i], fire_time[i] + 1001, -1);
      fill(j_time[i], j_time[i] + 1001, -1);
    }

    int R, C;
    int result = __INT_MAX__;
    pair<int, int> j_location, fire_location;
    queue<pair<int, int> > Q;
    cin >> R >> C;
    for (int i=0;i<R;i++) {
      string line;
      cin >> line;
      for (int j=0;j<C;j++) {
        if (line.at(j) == '#') {
          board[i][j] = -1;
        }
        if (line.at(j) == 'J') {
          j_location = make_pair(j, i);
          j_time[i][j] = 0;
        }
        if (line.at(j) == 'F') {
          fire_location = make_pair(j, i);
          fire_time[i][j] = 0;
          Q.push(fire_location);
        }
      }
    }

    while (!Q.empty()) {
      pair<int, int> top = Q.front(); Q.pop();
      for (int i=0;i<4;i++) {
        int nx = top.X + dx[i];
        int ny = top.Y + dy[i];
        if (0 <= nx && nx < C && 0 <= ny && ny < R && board[ny][nx] != -1 && fire_time[ny][nx] == -1) {
          fire_time[ny][nx] = fire_time[top.Y][top.X] + 1;
          Q.push(make_pair(nx, ny));
        }
      }
    }

    Q.push(j_location);
    while (!Q.empty()) {
      pair<int, int> top = Q.front(); Q.pop();
      if (top.X == 0 || top.X == C - 1 || top.Y == 0 || top.Y == R - 1) {
        result = min(result, j_time[top.Y][top.X] + 1);
      }
      for (int i=0;i<4;i++) {
        int nx = top.X + dx[i];
        int ny = top.Y + dy[i];
        if (0 <= nx && nx < C && 0 <= ny && ny < R && board[ny][nx] != -1 && j_time[ny][nx] == -1 && (fire_time[ny][nx] == -1 || j_time[top.Y][top.X] + 1 < fire_time[ny][nx])) {
          j_time[ny][nx] = j_time[top.Y][top.X] + 1;
          Q.push(make_pair(nx, ny));
        }
      }
    }

    if (result == __INT_MAX__) {
      cout << "IMPOSSIBLE";
    } else {
      cout << result;
    }

    return 0;
}


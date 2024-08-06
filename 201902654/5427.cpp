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
int human_time[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
      for (int i=0;i<1001;i++) {
        fill(board[i], board[i] + 1001, 0);
        fill(fire_time[i], fire_time[i] + 1001, -1);
        fill(human_time[i], human_time[i] + 1001, -1);
      }
      int result = -1;
      pair<int, int> human_position;
      queue<pair<int, int> > Q;
      int w, h;
      cin >> w >> h;
      for (int y=0;y<h;y++) {
        string line;
        cin >> line;
        for (int x=0;x<w;x++) {
          char ch = line.at(x);
          if (ch == '#') {
            board[y][x] = 1;
          }
          if (ch == '@') {
            human_position = make_pair(x, y);
            human_time[y][x] = 0;
          }
          if (ch == '*') {
            Q.push(make_pair(x, y));
            fire_time[y][x] = 0;
          }
        }
      }
      while (!Q.empty()) {
        pair<int, int> top = Q.front(); Q.pop();
        for (int i=0;i<4;i++) {
          int nx = top.X + dx[i];
          int ny = top.Y + dy[i];
          if (0 <= nx && nx < w && 0 <= ny && ny < h && board[ny][nx] == 0 && fire_time[ny][nx] == -1) {
            fire_time[ny][nx] = fire_time[top.Y][top.X] + 1;
            Q.push(make_pair(nx, ny));
          }
        }
      }
      Q.push(human_position);
      while (!Q.empty()) {
        pair<int, int> top = Q.front(); Q.pop();
        if (top.X == 0 || top.X == w - 1 || top.Y == 0 || top.Y == h - 1) {
          result = human_time[top.Y][top.X] + 1;
          break;
        }
        for (int i=0;i<4;i++) {
          int nx = top.X + dx[i];
          int ny = top.Y + dy[i];
          if (0 <= nx && nx < w && 0 <= ny && ny < h && board[ny][nx] == 0 && human_time[ny][nx] == -1 && (fire_time[ny][nx] == -1 || fire_time[ny][nx] > human_time[top.Y][top.X] + 1)) {
            human_time[ny][nx] = human_time[top.Y][top.X] + 1;
            Q.push(make_pair(nx, ny));
          }
        }
      }
      if (result == -1) {
        cout << "IMPOSSIBLE" << '\n';
      } else {
        cout << result << '\n';
      }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[301][301];
bool is_visit[301][301];
int N, M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int y=0;y<N;y++) {
      for (int x=0;x<M;x++) {
        cin >> board[y][x];
      }
    }
    int time = 0;
    bool is_ice_exist = false;
    while (true) {
      time++;
      int new_board[301][301];
      for (int y=0;y<301;y++) {
        fill(new_board[y], new_board[y]+301, 0);
        fill(is_visit[y], is_visit[y]+301, 0);
      }
      is_ice_exist = false;
      for (int y=0;y<N;y++) {
        for (int x=0;x<M;x++) {
          if (board[y][x] > 0) {
            is_ice_exist = true;
            int count = 0;
            for (int i=0;i<4;i++) {
              int nx = x + dx[i];
              int ny = y + dy[i];
              if (board[ny][nx] == 0) {
                count++;
              }
            }
            new_board[y][x] = max(0, board[y][x] - count);
          }
        }
      }
      for (int i=0;i<301;i++) {
        for (int j=0;j<301;j++) {
          board[i][j] = new_board[i][j];
        }
      }
      queue<pair<int, int> > Q;
      int area = 0;
      for (int y=0;y<N;y++) {
        for (int x=0;x<M;x++) {
          if (board[y][x] > 0 && !is_visit[y][x]) {
            area++;
            Q.push(make_pair(x, y));
            is_visit[y][x] = true;
            while (!Q.empty()) {
              pair<int, int> top = Q.front(); Q.pop();
              for (int i=0;i<4;i++) {
                int nx = top.X + dx[i];
                int ny = top.Y + dy[i];
                if (!is_visit[ny][nx] && board[ny][nx] != 0) {
                  is_visit[ny][nx] = true;
                  Q.push(make_pair(nx, ny));
                }
              }
            }
          }
        }
      }
      if (area > 1) {
        cout << time;
        break;
      }
      if (is_ice_exist == false) {
        break;
      }
    }
    if (is_ice_exist == false) {
      cout << 0;
    }

    return 0;
}

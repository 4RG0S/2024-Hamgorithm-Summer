#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N;
int board[101][101];
int min_length[101][101];
bool is_visit[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int y=0;y<N;y++) {
      fill(min_length[y], min_length[y] + 101, __INT_MAX__);
    }
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        cin >> board[y][x];
      }
    }
    int area = 1;
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        if (!is_visit[y][x] && board[y][x] > 0) {
          queue<pair<int, int> > Q;
          Q.push(make_pair(x, y));
          is_visit[y][x] = true;
          board[y][x] = area;
          while (!Q.empty()) {
            pair<int, int> top = Q.front(); Q.pop();
            for (int i=0;i<4;i++) {
              int nx = top.X + dx[i];
              int ny = top.Y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < N && !is_visit[ny][nx] && board[ny][nx] > 0) {
                is_visit[ny][nx] = true;
                board[ny][nx] = area;
                Q.push(make_pair(nx, ny));
              }
            }
          }

          area++;
        }
      }
    }
    // cout << "#############" << '\n';
    // for (int y=0;y<N;y++) {
    //   for (int x=0;x<N;x++) {
    //     cout << board[y][x] << ' ';
    //   }
    //   cout << '\n';
    // }
    int result = __INT_MAX__;
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        if (board[y][x] != 0 && ((x != 0 && board[y][x-1] == 0) || (x != N-1 && board[y][x+1] == 0) || (y != 0 && board[y-1][x] == 0) || (y != N-1 && board[y+1][x] == 0))) {
          // cout << x << ' ' << y << '\n';
          queue<tuple<int, int, int, int> > Q;
          Q.push(make_tuple(x, y, board[y][x], 0));
          min_length[y][x] = 0;
          while (!Q.empty()) {
            tuple<int, int, int, int> top = Q.front(); Q.pop();
            int x = get<0>(top);
            int y = get<1>(top);
            int area = get<2>(top);
            int length = get<3>(top);
            for (int i=0;i<4;i++) {
              int nx = x + dx[i];
              int ny = y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < N && length + 1 <= result) {
                // cout << "^^" << '\n';
                if (board[ny][nx] == 0 && min_length[ny][nx] > length + 1) {
                  min_length[ny][nx] = length + 1;
                  Q.push(make_tuple(nx, ny, area, length + 1));
                } else if (board[ny][nx] != 0 && board[ny][nx] != area) {
                  result = min(result, length);
                  // cout << length << '\n';
                  queue<tuple<int, int, int, int> > empty;
                  Q.swap(empty);
                }
              }
            }
          }
        }
      }
    }
    cout << result;

    return 0;
}

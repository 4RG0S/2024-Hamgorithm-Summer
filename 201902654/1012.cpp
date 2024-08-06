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
int board[51][51];
int is_visit[51][51];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
      int M, N, K;
      int result = 0;
      queue<pair<int, int> > Q;
      cin >> M >> N >> K;
      for (int y=0;y<N;y++) {
        fill(board[y], board[y] + M, 0);
        fill(is_visit[y], is_visit[y] + M, false);
      }
      for (int i=0;i<K;i++) {
        int x, y;
        cin >> x >> y;
        board[y][x] = 1;
      }
      for (int y=0;y<N;y++) {
        for (int x=0;x<M;x++) {
          if (board[y][x] == 1 && !is_visit[y][x]) {
            result++;
            Q.push(make_pair(x, y));
            is_visit[y][x] = true;
            while (!Q.empty()) {
              pair<int, int> top = Q.front(); Q.pop();
              for (int i=0;i<4;i++) {
                int nx = top.X + dx[i];
                int ny = top.Y + dy[i];
                if (0 <= nx && nx < M && 0 <= ny && ny < N && is_visit[ny][nx] == false && board[ny][nx] == 1) {
                  is_visit[ny][nx] = true;
                  Q.push(make_pair(nx, ny));
                }
              }
            }
          }
        }
      }
      cout << result << '\n';
    }

    return 0;
}

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
int map[1001][1001];
int dist[11][1001][1001];
int N, M, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0;i<11;i++) {
      for (int j=0;j<1001;j++) {
        fill(dist[i][j], dist[i][j] + 1001, -1);
      }
    }
    cin >> N >> M >> K;
    for (int i=0;i<N;i++) {
      string line;
      cin >> line;
      for (int j=0;j<M;j++) {
        map[i][j] = line.at(j) - '0';
      }
    }
    queue<tuple<int, int, int> > Q;
    dist[0][0][0] = 1;
    Q.push(make_tuple(0, 0, 0));
    while (!Q.empty()) {
      tuple<int, int, int> top = Q.front(); Q.pop();
      int x = get<0>(top);
      int y = get<1>(top);
      int broken_wall_count = get<2>(top);
      for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N) {
          bool is_wall = map[ny][nx] == 1;
          int next_wall_count = is_wall ? broken_wall_count + 1 : broken_wall_count;
          if (next_wall_count <= K && dist[next_wall_count][ny][nx] == -1) {
            dist[next_wall_count][ny][nx] = dist[broken_wall_count][y][x] + 1;
            Q.push(make_tuple(nx, ny, next_wall_count));
          }
        }
      }
    }
    int result = __INT_MAX__;
    for (int i=0;i<=K;i++) {
      if (dist[i][N-1][M-1] != -1) {
        result = min(result, dist[i][N-1][M-1]);
      }
      // cout << dist[i][N-1][M-1];
    }
    cout << ((result == __INT_MAX__) ? -1 : result);

    return 0;
}

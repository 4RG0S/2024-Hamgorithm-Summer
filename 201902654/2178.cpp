#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[101][101];
int is_visit[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int result = 1000000000;
    queue<tuple<int, int, int> > Q; // X Y val
    cin >> N >> M;
    for (int i=0;i<N;i++) {
      string line;
      cin >> line;
      for (int j=0;j<M;j++) {
        board[i][j] = line.at(j) - '0';
      }
    }
    Q.push(make_tuple(0, 0, 1));
    is_visit[0][0] = true;
    while (!Q.empty()) {
      tuple<int, int, int> top = Q.front(); Q.pop();
      if (get<0>(top) == M - 1 && get<1>(top) == N - 1) {
        result = min(result, get<2>(top));
      }
      for (int i=0;i<4;i++) {
        int nx = get<0>(top) + dx[i];
        int ny = get<1>(top) + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && !is_visit[ny][nx] && board[ny][nx] == 1) {
          is_visit[ny][nx] = true;
          Q.push(make_tuple(nx, ny, get<2>(top) + 1));
        }
      }
    }
    cout << result;

    return 0;
}

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
int board[101][101];
bool is_visit[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int count = 0;
    vector<int> arr;
    int M, N, K;
    queue<pair<int, int> > Q;
    cin >> M >> N >> K;
    for (int i=0;i<K;i++) {
      int start_x, start_y, end_x, end_y;
      cin >> start_x >> start_y >> end_x >> end_y;
      for (int y=start_y;y<end_y;y++) {
        for (int x=start_x;x<end_x;x++) {
          board[y][x] = 1;
        }
      }
    }
    for (int y=0;y<M;y++) {
      for (int x=0;x<N;x++) {
        if (board[y][x] == 0 && !is_visit[y][x]) {
          count++;
          int area = 1;
          is_visit[y][x] = true;
          Q.push(make_pair(x, y));
          while (!Q.empty()) {
            pair<int, int> top = Q.front(); Q.pop();
            for (int i=0;i<4;i++) {
              int nx = top.X + dx[i];
              int ny = top.Y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < M && board[ny][nx] == 0 && !is_visit[ny][nx]) {
                is_visit[ny][nx] = true;
                area++;
                Q.push(make_pair(nx, ny));
              }
            }
          }
          arr.push_back(area);
        }
      }
    }
    sort(arr.begin(), arr.end());
    cout << count << '\n';
    for (int iter : arr) {
      cout << iter << ' ';
    }

    return 0;
}

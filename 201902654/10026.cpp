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
char board[101][101];
bool is_visit[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int normal_result = 0;
    int abnormal_result = 0;
    queue<pair<int, int> > Q;
    cin >> N;
    for (int i=0;i<N;i++) {
      string line;
      cin >> line;
      for (int j=0;j<N;j++) {
        board[i][j] = line.at(j);
      }
    }
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        if (!is_visit[y][x]) {
          normal_result++;
          is_visit[y][x] = true;
          Q.push(make_pair(x, y));
          while (!Q.empty()) {
            pair<int, int> top = Q.front(); Q.pop();
            for (int i=0;i<4;i++) {
              int nx = top.X + dx[i];
              int ny = top.Y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < N && !is_visit[ny][nx] && board[ny][nx] == board[top.Y][top.X]) {
                is_visit[ny][nx] = true;
                Q.push(make_pair(nx, ny));
              }
            }
          }
        }
      }
    }
    for (int i=0;i<N;i++) fill(is_visit[i], is_visit[i] + N, false);
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        if (!is_visit[y][x]) {
          abnormal_result++;
          is_visit[y][x] = true;
          Q.push(make_pair(x, y));
          while (!Q.empty()) {
            pair<int, int> top = Q.front(); Q.pop();
            for (int i=0;i<4;i++) {
              int nx = top.X + dx[i];
              int ny = top.Y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < N && !is_visit[ny][nx] && (board[ny][nx] == board[top.Y][top.X] || (board[ny][nx] == 'R' && board[top.Y][top.X] == 'G') || (board[ny][nx] == 'G' && board[top.Y][top.X] == 'R'))) {
                is_visit[ny][nx] = true;
                Q.push(make_pair(nx, ny));
              }
            }
          }
        }
      }
    }
    cout << normal_result << ' ' << abnormal_result;
    return 0;
}

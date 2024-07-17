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
int days[1001][1001];
int boards[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0;i<1001;i++) {
      fill(days[i], days[i]+1001, -1);
    }

    int M, N;
    queue<pair<int, int> > Q;
    cin >> M >> N;
    for (int i=0;i<N;i++) {
      for (int j=0;j<M;j++) {
        cin >> boards[i][j];
        if (boards[i][j] == 1) {
          Q.push(make_pair(j, i));
          days[i][j] = 0;
        }
      }
    }
    while (!Q.empty()) {
      pair<int, int> top = Q.front(); Q.pop();
      for (int i=0;i<4;i++) {
        int nx = top.X + dx[i];
        int ny = top.Y + dy[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && boards[ny][nx] != -1 && days[ny][nx] == -1) {
          days[ny][nx] = days[top.Y][top.X] + 1;
          Q.push(make_pair(nx, ny));
        }
      }
    }
    int result = 0;
    for (int i=0;i<N;i++) {
      for (int j=0;j<M;j++) {
        if (boards[i][j] != -1 && days[i][j] == -1) {
          cout << -1;
          return 0;
        } else if (boards[i][j] != -1) {
          result = max(result, days[i][j]);
        }
      }
    }
    cout << result;


    return 0;
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int days[101][101][101];
int boards[101][101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0;i<101;i++) {
      for (int j=0;j<101;j++) {
        fill(days[i][j], days[i][j]+101, -1);
      }
    }

    int M, N, H;
    queue<tuple<int, int, int> > Q;
    cin >> M >> N >> H;
    for (int h=0;h<H;h++) {
      for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
          cin >> boards[h][i][j];
          if (boards[h][i][j] == 1) {
            Q.push(make_tuple(j, i, h));
            days[h][i][j] = 0;
          }
        }
      }
    }
    while (!Q.empty()) {
      tuple<int, int, int> top = Q.front(); Q.pop();
      for (int i=0;i<6;i++) {
        int nx = get<0>(top) + dx[i];
        int ny = get<1>(top) + dy[i];
        int nz = get<2>(top) + dz[i];
        if (0 <= nx && nx < M && 0 <= ny && ny < N && 0 <= nz && nz < H && boards[nz][ny][nx] != -1 && days[nz][ny][nx] == -1) {
          days[nz][ny][nx] = days[get<2>(top)][get<1>(top)][get<0>(top)] + 1;
          Q.push(make_tuple(nx, ny, nz));
        }
      }
    }
    int result = 0;
    for (int h=0;h<H;h++) {
      for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
          if (boards[h][i][j] != -1 && days[h][i][j] == -1) {
            cout << -1;
            return 0;
          } else if (boards[h][i][j] != -1) {
            result = max(result, days[h][i][j]);
          }
        }
      }
    }
    cout << result;


    return 0;
}

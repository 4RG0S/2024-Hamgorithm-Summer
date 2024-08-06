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
int map[26][26];
bool is_visit[26][26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
      string line;
      cin >> line;
      for (int j=0;j<N;j++) {
        map[i][j] = line.at(j) - '0';
      }
    }
    int count_result = 0;
    vector<int> area_result;
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        if (!is_visit[y][x] && map[y][x] == 1) {
          int area = 1;
          count_result++;
          queue<pair<int, int> > Q;
          Q.push(make_pair(x, y));
          is_visit[y][x] = true;
          while (!Q.empty()) {
            pair<int, int> top = Q.front(); Q.pop();
            for (int i=0;i<4;i++) {
              int nx = top.X + dx[i];
              int ny = top.Y + dy[i];
              if (0 <= nx && nx < N && 0 <= ny && ny < N && !is_visit[ny][nx] && map[ny][nx] == 1) {
                area++;
                is_visit[ny][nx] = true;
                Q.push(make_pair(nx, ny));
              }
            }
          }
          area_result.push_back(area);
        }
      }
    }
    sort(area_result.begin(), area_result.end());
    cout << count_result << '\n';
    for (int iter : area_result) {
      cout << iter << '\n';
    }

    return 0;
}

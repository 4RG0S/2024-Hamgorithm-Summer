#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int moving[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t=0;t<T;t++) {
      for (int i=0;i<301;i++) fill(moving[i], moving[i] + 301, -1);
      int l, x, y;
      int result = 0;
      pair<int, int> knight_position, dest_position;
      queue<pair<int, int> > Q;
      cin >> l;
      cin >> x >> y;
      knight_position = make_pair(x, y);
      moving[y][x] = 0;
      Q.push(make_pair(x, y));
      cin >> x >> y;
      dest_position = make_pair(x, y);

      while (!Q.empty()) {
        pair<int, int> top = Q.front(); Q.pop();
        if (top == dest_position) {
          break;
        }
        for (int i=0;i<8;i++) {
          int nx = top.X + dx[i];
          int ny = top.Y + dy[i];
          if (0 <= nx && nx < l && 0 <= ny && ny < l && moving[ny][nx] == -1) {
            moving[ny][nx] = moving[top.Y][top.X] + 1;
            Q.push(make_pair(nx, ny));
          }
        }
      }
      cout << moving[dest_position.Y][dest_position.X] << '\n';
    }

    return 0;
}

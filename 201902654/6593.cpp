#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <tuple>

using namespace std;

int dx[6] = {0, 0, 1, -1, 0, 0};
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int L, R, C;
int building[31][31][31];
int count_minutes[31][31][31];
tuple<int, int, int> s_position;
tuple<int, int, int> e_position;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (true) {
      cin >> L >> R >> C;
      if (L == 0 && R == 0 && C == 0) {
        break;
      }
      for (int z=0;z<L;z++) {
        for (int y=0;y<R;y++) {
          fill(count_minutes[z][y], count_minutes[z][y]+C+1, -1);
          fill(building[z][y], building[z][y]+C+1, 0);
        }
      }
      for (int z=0;z<L;z++) {
        for (int y=0;y<R;y++) {
          string line;
          cin >> line;
          for (int x=0;x<C;x++) {
            if (line.at(x) == 'S') {
              s_position = make_tuple(x, y, z);
            }
            if (line.at(x) == 'E') {
              e_position = make_tuple(x, y, z);
            }
            if (line.at(x) == '#') {
              building[z][y][x] = 1;
            }
          }
        }
      }
      queue<tuple<int, int, int> > Q;
      Q.push(s_position);
      count_minutes[get<2>(s_position)][get<1>(s_position)][get<0>(s_position)] = 0;
      while (!Q.empty()) {
        tuple<int, int, int> top = Q.front(); Q.pop();
        for (int i=0;i<6;i++) {
          int nx = get<0>(top) + dx[i];
          int ny = get<1>(top) + dy[i];
          int nz = get<2>(top) + dz[i];

          if (0 <= nx && nx < C && 0 <= ny && ny < R && 0 <= nz && nz < L && building[nz][ny][nx] == 0 && count_minutes[nz][ny][nx] == -1) {
            count_minutes[nz][ny][nx] = count_minutes[get<2>(top)][get<1>(top)][get<0>(top)] + 1;
            Q.push(make_tuple(nx, ny, nz));
          }
        }
      }
      if (count_minutes[get<2>(e_position)][get<1>(e_position)][get<0>(e_position)] == -1) {
        cout << "Trapped!" << '\n';
      } else {
        cout << "Escaped in " << count_minutes[get<2>(e_position)][get<1>(e_position)][get<0>(e_position)] << " minute(s)." << '\n';
      }
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int counts[3];
int board[2200][2200];
int N;

void recursion(int N, int init_x, int init_y) {
  int comp = board[init_y][init_x];
  bool is_same = true;
  for (int y = init_y; y < N + init_y; y++) {
    for (int x = init_x; x < N + init_x; x++) {
      if (board[y][x] != comp) is_same = false;
    }
  }
  if (is_same) {
    counts[comp + 1]++;
  } else {
    int w = N/3;
    recursion(N/3, init_x, init_y);
    recursion(N/3, init_x+w*1, init_y);
    recursion(N/3, init_x+w*2, init_y);
    recursion(N/3, init_x, init_y+w*1);
    recursion(N/3, init_x+w*1, init_y+w*1);
    recursion(N/3, init_x+w*2, init_y+w*1);
    recursion(N/3, init_x, init_y+w*2);
    recursion(N/3, init_x+w*1, init_y+w*2);
    recursion(N/3, init_x+w*2, init_y+w*2);
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i=0;i<N;i++) {
      for (int j=0;j<N;j++) {
        cin >> board[i][j];
      }
    }
    recursion(N, 0, 0);
    cout << counts[0] << '\n';
    cout << counts[1] << '\n';
    cout << counts[2] << '\n';

    return 0;
}

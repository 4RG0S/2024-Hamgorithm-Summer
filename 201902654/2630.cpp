#include <bits/stdc++.h>

using namespace std;

int board[128][128];
int N;
int counts[2];

void recursion(int N, int init_x, int init_y) {
  int comp = board[init_y][init_x];
  bool is_same = true;
  for (int y = init_y; y < N + init_y; y++) {
    for (int x = init_x; x < N + init_x; x++) {
      if (comp != board[y][x]) is_same = false;
    }
  }
  if (is_same) {
    counts[comp]++;
  } else {
    int w = N / 2;
    recursion(N/2, init_x, init_y);
    recursion(N/2, init_x + w, init_y);
    recursion(N/2, init_x, init_y + w);
    recursion(N/2, init_x + w, init_y + w);
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int y=0;y<N;y++) {
      for (int x=0;x<N;x++) {
        cin >> board[y][x];
      }
    }
    recursion(N, 0, 0);
    cout << counts[0] << '\n';
    cout << counts[1] << '\n';

    return 0;
}

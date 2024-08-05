#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
int order;
int N, r, c;

int record(int N, int x, int y) {
  int half = pow(2, N-1);
  if (N == 0) {
    return 0;
  }
  if (x < half && y < half) return record(N-1, x, y);
  if (x >= half && y < half) return half * half * 1 + record(N-1, x-half, y);
  if (x < half && y >= half) return half * half * 2 + record(N-1, x, y-half);
  if (x >= half && y >= half) return half * half * 3 + record(N-1, x-half, y-half);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> r >> c;

    cout << record(N, c, r);


    return 0;
}

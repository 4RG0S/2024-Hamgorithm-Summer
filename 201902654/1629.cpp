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

long long POW(int a, int b, int c) {
  if (b == 1) return a % c;
  long long val = POW(a, b/2, c);
  val = val * val % c;
  if (b % 2 == 0) {
    return val;
  } else {
    return val * a % c;
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int A, B, C;
    cin >> A >> B >> C;

    cout << POW(A, B, C);
    return 0;
}

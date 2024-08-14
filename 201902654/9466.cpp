#include <bits/stdc++.h>

using namespace std;
int T;
int select_num[100001], connecting[100001];
bool is_visit[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t=0;t<T;t++) {
      fill(select_num, select_num+100001, 0);
      fill(connecting, connecting+100001, 0);
      fill(is_visit, is_visit+100001, 0);
      int n;
      queue<int> Q;
      cin >> n;
      for (int i=0;i<n;i++) {
        cin >> select_num[i];
      }
      for (int i=0;i<n;i++) {
        if (connecting[i] == 0 && !is_visit[i]) {
          Q.push(i);
          is_visit[i] = true;
          connecting[i] = i;
          while (!Q.empty()) {
            int top = Q.front(); Q.pop();
            int next = select_num[top] - 1;
            if (is_visit[next] == true && connecting[next] == i) {
              connecting[next] = -1;
              Q.push(next);
            } else if (is_visit[next] == false) {
              is_visit[next] = true;
              connecting[next] = i;
              Q.push(next);
            }
          }
        }
      }

      int result = 0;
      for (int i=0;i<n;i++) {
        // cout << connecting[i] << ' ';
        if (connecting[i] == -1) {
          result++;
        }
      }
      cout << n - result << '\n';
    }

    return 0;
}

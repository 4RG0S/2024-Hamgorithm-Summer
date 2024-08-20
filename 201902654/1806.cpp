#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, S;
    cin >> N >> S;
    int arr[N];
    for (int i=0;i<N;i++) {
      cin >> arr[i];
    }
    int sub_sum[N+1];
    sub_sum[0] = 0;
    for (int i=1;i<=N;i++) {
      sub_sum[i] = sub_sum[i-1] + arr[i-1];
    }
    int end = N;
    int result = __INT_MAX__;
    for (int start=N;start>=0;start--) {
      while (end >= 0) {
        if (sub_sum[start] - sub_sum[end] >= S) {
          result = min(result, start - end);
          break;
        }
        end--;
      }
    }
    cout << ((result == __INT_MAX__) ? 0 : result);

    return 0;
}

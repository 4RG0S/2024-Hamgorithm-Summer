#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int arr[N];
    for (int i=0;i<N;i++) {
      cin >> arr[i];
    }
    sort(arr, arr + N);
    int end = 0;
    int result = __INT_MAX__;
    for (int start=0;start<N;start++) {
      while (end < N) {
        if (abs(arr[start] - arr[end]) >= M) {
          result = min(result, abs(arr[start] - arr[end]));
          break;
        }
        end++;
      }
    }
    cout << result;

    return 0;
}

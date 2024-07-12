#include <string>
#include <algorithm>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int arr[N];
    int result[N];
    fill(result, result+N, 0);
    stack<pair<int, int> > stack;
    for (int i=0;i<N;i++) {
      cin >> arr[i];
    }
    for (int i=N-1;i>=0;i--) {
      while (!stack.empty() && stack.top().second < arr[i]) {
        result[stack.top().first] = i + 1;
        stack.pop();
      }
      stack.push(make_pair(i, arr[i]));
    }

    for (int iter : result) {
      cout << iter << ' ';
    }
    return 0;
}

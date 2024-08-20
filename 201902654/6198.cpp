#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[N+1], result[N];
    stack<pair<int, int> > stack;
    fill(result, result + N, 0);
    for (int i=0;i<N;i++) {
      cin >> arr[i];
    }
    arr[N] = 1000000000;
    for (int i=0;i<N+1;i++) {
      while (!stack.empty() && stack.top().second <= arr[i]) {
        result[stack.top().first] = i - stack.top().first - 1;
        stack.pop();
      }
      stack.push(make_pair(i, arr[i]));
    }
    long value = 0;
    for (int iter : result) {
      value = value + iter;
    }
    cout << value;

    return 0;
}

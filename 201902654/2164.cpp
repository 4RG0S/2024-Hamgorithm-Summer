#include <string>
#include <queue>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
      Q.push(i+1);
    }
    for (int i=0;i<N-1;i++) {
      Q.pop();
      Q.push(Q.front());
      Q.pop();
    }
    cout << Q.front();

    return 0;
}

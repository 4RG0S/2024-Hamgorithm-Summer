#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int count[201];
    fill(count, count+201, 0);
    for (int i=0;i<N;i++) {
      int val;
      cin >> val;
      count[val + 100]++;
    }
    int find;
    cin >> find;
    cout << count[find+100];

    return 0;
}

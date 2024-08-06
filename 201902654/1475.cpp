#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string N;
  vector<int> arr(10, 0);
  getline(cin, N);
  for (char ch : N) {
    ++arr[ch - '0'];
  }
  arr[6] = (arr[6] + arr[9] + 1) / 2;
  arr[9] = 0;
  int max = 0;
  for (int iter : arr) {
    if (max < iter) {
      max = iter;
    }
  }
  cout << max;
}

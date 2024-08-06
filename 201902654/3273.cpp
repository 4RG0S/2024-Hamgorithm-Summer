#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> arr(2000001, 0);
  for (int i=0;i<n;++i) {
    int input;
    cin >> input;
    ++arr[input];
  }
  int x;
  cin >> x;

  int result = 0;
  if (x % 2 == 0) {
    for (int i=1;i<x/2;++i){
      result = result + arr[i] * arr[x - i];
    }
    result = result + (arr[x/2] * (arr[x/2] - 1) / 2);
  } else {
    for (int i=1;i<=x/2;++i){
      result = result + arr[i] * arr[x - i];
    }
  }
  cout << result;
}

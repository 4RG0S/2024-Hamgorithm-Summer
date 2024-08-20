#include <bits/stdc++.h>

using namespace std;
int count_divider[4000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> prime_numbers;
    for (int i=2;i<=4000000;i++) {
      for (int index=i;index<=4000000;index+=i) {
        ++count_divider[index];
      }
    }
    for (int i=2;i<=4000000;i++) {
      if (count_divider[i] == 1) {
        prime_numbers.push_back(i);
      }
    }
    int result = 0;
    long long N;
    cin >> N;
    vector<long long> sub_sum;
    sub_sum.push_back(0);
    for (int i=1;i<=prime_numbers.size();i++) {
      sub_sum.push_back(sub_sum[i-1] + prime_numbers[i-1]);
    }
    int end = 0;
    int length = sub_sum.size();
    for (int start=0;start<length;start++) {
      while (end < length) {
        if (sub_sum[end] - sub_sum[start] >= N) {
          if (sub_sum[end] - sub_sum[start] == N) {
            result++;
          }
          break;
        }
        end++;
      }
    }
    cout << result;

    return 0;
}

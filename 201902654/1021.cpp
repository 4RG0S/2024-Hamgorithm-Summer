#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int result = 0;
    deque<int> D;
    cin >> N >> M;
    for (int i=0;i<N;i++) {
      D.push_back(i+1);
    }
    for (int i=0;i<M;i++) {
      int value;
      cin >> value;
      int front_count = 0;
      int back_count = 0;
      while (D.front() != value) {
        D.push_back(D.front());
        D.pop_front();
        front_count++;
      }
      for (int i=0;i<front_count;i++) {
        D.push_front(D.back());
        D.pop_back();
      }
      while (D.front() != value) {
        D.push_front(D.back());
        D.pop_back();
        back_count++;
      }
      for (int i=0;i<back_count;i++) {
        D.push_back(D.front());
        D.pop_front();
      }

      if (front_count > back_count) {
        for (int i=0;i<back_count;i++) {
          D.push_front(D.back());
          D.pop_back();
        }
        D.pop_front();
        result = result + back_count;
      } else {
        for (int i=0;i<front_count;i++) {
          D.push_back(D.front());
          D.pop_front();
        }
        D.pop_front();
        result = result + front_count;
      }
    }
    cout << result;

    return 0;
}

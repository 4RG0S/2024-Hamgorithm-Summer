#include <string>
#include <list>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    list<int> L,result;
    auto cursor = L.begin();
    for (int i=0;i<N;++i) {
      L.push_back(i+1);
    }
    for (int i=0;i<N;i++) {
      for (int j=0;j<K-1;j++) {
        if (cursor == L.end()) {
          cursor = L.begin();
        }
        cursor++;
      }
      if (cursor == L.end()) {
        cursor = L.begin();
      }
      result.push_back(*cursor);
      cursor = L.erase(cursor);
    }
    cout << '<';
    for (list<int>::iterator it = result.begin();it != result.end();it++) {
      cout << *it;
      if (it != --result.end()) {
        cout << ", ";
      }
    }
    cout << '>';

    return 0;
}

#include <string>
#include <list>
#include <iostream>

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string N;
  int M;
  cin >> N;
  list<char> L;
  for (char ch : N) {
    L.push_back(ch);
  }
  auto cursor = L.end();
  cin >> M;
  for (int i=0;i<M;++i) {
    char op;
    cin >> op;
    if (op == 'L') {
      if (cursor != L.begin()) {
        cursor--;
      }
    } else if (op == 'D') {
      if (cursor != L.end()) {
        cursor++;
      }
    } else if (op == 'B') {
      if (cursor != L.begin()) {
        cursor--;
        cursor = L.erase(cursor);
      }
    } else if (op == 'P') {
      char ch;
      cin >> ch;
      L.insert(cursor, ch);
    }
  }
  for (char ch : L) {
    cout << ch;
  }
}

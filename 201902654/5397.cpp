#include <string>
#include <list>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    for (int i=0;i<test_case;++i){
      string input;
      list<char> L;
      auto cursor = L.end();
      cin >> input;

      for (char ch : input) {
        if (ch == '<') {
          if (cursor != L.begin()) {
            cursor--;
          }
        } else if (ch == '>') {
          if (cursor != L.end()) {
            cursor++;
          }
        } else if (ch == '-') {
          if (cursor != L.begin()) {
            cursor--;
            cursor = L.erase(cursor);
          }
        } else {
          L.insert(cursor, ch);
        }
      }

      for (char ch : L) {
        cout << ch;
      }
      cout << '\n';
    }

    return 0;
}

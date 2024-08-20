#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> D;
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
      string command;
      cin >> command;
      if (command == "push_front") {
        int value;
        cin >> value;
        D.push_front(value);
      } else if (command == "push_back") {
        int value;
        cin >> value;
        D.push_back(value);
      } else if (command == "pop_front") {
        cout << ((D.size() == 0) ? -1 : D.front()) << '\n';
        if (D.size() != 0) {
          D.pop_front();
        }
      } else if (command == "pop_back") {
        cout << ((D.size() == 0) ? -1 : D.back()) << '\n';
        if (D.size() != 0) {
          D.pop_back();
        }
      } else if (command == "size") {
        cout << D.size() << '\n';
      } else if (command == "empty") {
        cout << ((D.size() == 0) ? 1 : 0) << '\n';
      } else if (command == "front") {
        cout << ((D.size() == 0) ? -1 : D.front()) << '\n';
      } else if (command == "back") {
        cout << ((D.size() == 0) ? -1 : D.back()) << '\n';
      }
    }

    return 0;
}

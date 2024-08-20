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
      string command;
      cin >> command;
      if (command == "push") {
        int value;
        cin >> value;

        Q.push(value);
      } else {
        if (command == "pop") {
          cout << ((Q.size() == 0) ? -1 : Q.front());
          if (Q.size() != 0) {
            Q.pop();
          }
        } else if (command == "size") {
          cout << Q.size();
        } else if (command == "empty") {
          cout << ((Q.size() == 0) ? 1 : 0);
        } else if (command == "front") {
          cout << ((Q.size() == 0) ? -1 : Q.front());
        } else if (command == "back") {
          cout << ((Q.size() == 0) ? -1 : Q.back());
        }
        cout << '\n';
      }
    }

    return 0;
}

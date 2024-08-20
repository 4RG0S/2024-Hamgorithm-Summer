#include <string>
#include <deque>
#include <iostream>

using namespace std;

deque<int> tokenize(string s, string del = ",")
{
    deque<int> result;
    int start, end = -1 * del.size();
    if (s.size() > 0) {
      do {
          start = end + del.size();
          end = s.find(del, start);
          result.push_back(stoi(s.substr(start, end - start)));
      } while (end != -1);
    }

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int i=0;i<T;i++) {
      string commands;
      int n;
      string arr;
      cin >> commands;
      cin >> n;
      getline(cin >> ws, arr);
      deque<int> D = tokenize(arr.substr(1, arr.size() - 2), ",");
      bool is_reversed = false;
      bool is_error = false;
      // cout << D.size() << '\n';
      for (char command : commands) {
        if (command == 'R') {
          is_reversed = !is_reversed;
        } else {
          if (D.size() == 0) {
            cout << "error" << '\n';
            is_error = true;
            break;
          }
          if (is_reversed) {
            D.pop_back();
          } else {
            D.pop_front();
          }
        }
      }
      if (!is_error) {
        cout << '[';
        while (!D.empty()) {
          if (is_reversed) {
            cout << D.back();
            D.pop_back();
          } else {
            cout << D.front();
            D.pop_front();
          }
          if (!D.empty()) {
            cout << ',';
          }
        }
        cout << ']' << '\n';
      }
    }

    return 0;
}

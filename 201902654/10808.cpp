#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
  string s;
  getline(cin, s);
  vector<int> alpha(26, 0);

  for (int i=0;i<s.length();++i){
    int index = s[i] - 'a';
    ++alpha[index];
  }

  for (int iter : alpha) {
    cout << iter << ' ';
  }
}

#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    stack<pair<int, int> > stack;
    int result[N];
    fill(result, result+N, -1);
    for (int i=0;i<N;i++) {
        int input;
        cin >> input;
        while (!stack.empty() && stack.top().second < input) {
            result[stack.top().first] = input;
            stack.pop();
        }
        stack.push(make_pair(i, input));
    }
    for (int iter : result) {
        cout << iter << ' ';
    }

    return 0;
}

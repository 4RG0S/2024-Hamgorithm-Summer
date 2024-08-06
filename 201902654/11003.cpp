#include <string>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<pair<int, int> > D;
    int N, L;
    cin >> N >> L;
    int arr[N];
    for (int i=0;i<N;i++) {
        cin >> arr[i];
    }
    D.push_back(make_pair(arr[0], L));
    for (int i=0;i<N;i++) {
        if (i != 0) {
            int pop_sum = 0;
            while (!D.empty() && D.back().first >= arr[i]) {
                pop_sum += D.back().second;
                D.pop_back();
            }
            D.push_back(make_pair(arr[i], pop_sum + 1));
        }
        pair<int, int> front = D.front();
        if (front.second == 1) {
            D.pop_front();
        } else {
            D.pop_front();
            D.push_front(make_pair(front.first, front.second - 1));
        }
        cout << front.first << ' ';
    }

    return 0;
}

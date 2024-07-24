#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;

	while (T > 0) {
		string command;
		cin >> command;

		int n;
		cin >> n;

		string rawArr;
		cin >> rawArr;

		rawArr.replace(0, 1, "");
		rawArr.replace(rawArr.size() - 1, 1, "");

		deque<int> arr;
		deque<int> revArr;

		string now;
		istringstream ss(rawArr);

		while (getline(ss, now, ',')) {
			arr.push_back(stoi(now));
			revArr.push_front(stoi(now));
		}

		int mode = 0;

		for (int i = 0; i < command.size(); i++) {
			if (command[i] == 'R') {
				mode ^= 1;
			} else if (command[i] == 'D') {
				if (n < 1) {
					cout << "error" << endl;
					mode = 2;
					break;
				}

				n--;

				if (mode == 0) {
					arr.pop_front();
					revArr.pop_back();
				} else if (mode == 1) {
					arr.pop_back();
					revArr.pop_front();
				}
			}
		}

		if (mode != 2) {
			cout << "[";

			if (mode == 0) {
				for (int i = 0; i < n; i++) {
					cout << arr.front();
					arr.pop_front();

					if (i != n - 1) {
						cout << ",";
					}
				}
			} else if (mode == 1) {
				for (int i = 0; i < n; i++) {
					cout << revArr.front();
					revArr.pop_front();

					if (i != n - 1) {
						cout << ",";
					}
				}
			}

			cout << "]\n";
		}

		T--;
	}

	return 0;
}